#include <vector>
#include <algorithm>
#include <set> // For multiset

class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        // Step 1: Preprocess conflictingPairs and create start_points
        // Store (b-1, original_pair_idx) for efficient access
        std::vector<std::vector<std::pair<int, int>>> start_points(n + 1);
        for (int k = 0; k < conflictingPairs.size(); ++k) {
            int u = conflictingPairs[k][0];
            int v = conflictingPairs[k][1];
            int a = std::min(u, v);
            int b = std::max(u, v);
            start_points[a].push_back({b - 1, k});
        }

        // Step 2: Compute f[i], s[i], id_f[i], id_s[i] arrays
        // f[i]: min b-1 for pairs [a,b] with a >= i
        // s[i]: second min b-1 for pairs [a,b] with a >= i
        // id_f[i]: original_pair_idx of the pair providing f[i]
        // id_s[i]: original_pair_idx of the pair providing s[i]
        
        std::vector<int> f(n + 1);
        std::vector<int> s(n + 1);
        std::vector<int> id_f(n + 1);
        std::vector<int> id_s(n + 1);

        // Multiset to store (b-1, original_pair_idx) for active pairs (a >= current i)
        // Ordered by b-1 values, then by original_pair_idx (though idx doesn't matter for ordering)
        std::multiset<std::pair<int, int>> active_limits_with_indices;

        long long total_f_sum_initial = 0;

        for (int i = n; i >= 1; --i) {
            // Add all pairs starting at 'i' to the multiset
            for (const auto& p : start_points[i]) {
                active_limits_with_indices.insert(p);
            }

            // Determine f[i], id_f[i], s[i], id_s[i] based on the current active limits
            if (active_limits_with_indices.empty()) {
                f[i] = n;
                id_f[i] = -1; // Sentinel for no restricting pair
                s[i] = n;
                id_s[i] = -1;
            } else {
                f[i] = active_limits_with_indices.begin()->first;
                id_f[i] = active_limits_with_indices.begin()->second;

                if (active_limits_with_indices.size() >= 2) {
                    auto it = active_limits_with_indices.begin();
                    std::advance(it, 1);
                    s[i] = it->first;
                    id_s[i] = it->second;
                } else {
                    s[i] = n; // No second minimum, so effective limit is n
                    id_s[i] = -1;
                }
            }
            total_f_sum_initial += f[i];
        }

        long long base_count = total_f_sum_initial - (long long)n * (n + 1) / 2 + n;

        // Step 3: Store potential gains for removal for each pair
        std::vector<long long> gains_for_pair(conflictingPairs.size(), 0);

        for (int i = 1; i <= n; ++i) {
            // If f[i] was restricted by a specific pair (not 'n' due to no pairs)
            if (id_f[i] != -1) {
                // The gain if this pair (id_f[i]) is removed is s[i] - f[i]
                // Note: s[i] can be equal to f[i] if multiple pairs gave the same min limit.
                // But if id_f[i] is truly removed, s[i] is the next active limit.
                gains_for_pair[id_f[i]] += (s[i] - f[i]);
            }
        }

        // Step 4: Find maximum additional gain
        long long max_additional_gain = 0;
        for (long long gain : gains_for_pair) {
            if (gain > max_additional_gain) {
                max_additional_gain = gain;
            }
        }

        // Step 5: Return final result
        return base_count + max_additional_gain;
    }
};