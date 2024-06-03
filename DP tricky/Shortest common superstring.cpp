int calculateOverlap(const string &s1, const string &s2) {
    int max_overlap = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    for (int i = 1; i <= min(len1, len2); ++i) {
        if (s1.substr(len1 - i) == s2.substr(0, i)) {
            max_overlap = i;
        }
    }
    return max_overlap;
}

int shortestSuperstring(vector<string>& strings) {
    int n = strings.size();
    
    // Precompute overlaps
    vector<vector<int>> overlaps(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                overlaps[i][j] = calculateOverlap(strings[i], strings[j]);
            }
        }
    }

    // dp[mask][i] will be the length of the shortest superstring containing all strings in mask and ending with strings[i]
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));
    
    // Base case: Starting with each string individually
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = strings[i].length();
    }

    // Fill dp table
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    if (!(mask & (1 << j))) {
                        int new_mask = mask | (1 << j);
                        int new_length = dp[mask][i] + strings[j].length() - overlaps[i][j];
                        if (new_length < dp[new_mask][j]) {
                            dp[new_mask][j] = new_length;
                            parent[new_mask][j] = i;
                        }
                    }
                }
            }
        }
    }

    // Find the minimum length in the full mask
    int final_mask = (1 << n) - 1;
    int min_length = INT_MAX;
    int end_index = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[final_mask][i] < min_length) {
            min_length = dp[final_mask][i];
            end_index = i;
        }
    }

    // Reconstruct the shortest superstring
    vector<int> perm;
    int mask = final_mask;
    while (end_index != -1) {
        perm.push_back(end_index);
        int new_end = parent[mask][end_index];
        mask ^= (1 << end_index);
        end_index = new_end;
    }
    reverse(perm.begin(), perm.end());

    // Build the resulting string using the permutation
    string superstring = strings[perm[0]];
    for (int i = 1; i < perm.size(); ++i) {
        int overlap = overlaps[perm[i-1]][perm[i]];
        superstring += strings[perm[i]].substr(overlap);
    }

    return superstring.length();
}

int Solution::solve(vector<string> &A) {
    return shortestSuperstring(A);
}
