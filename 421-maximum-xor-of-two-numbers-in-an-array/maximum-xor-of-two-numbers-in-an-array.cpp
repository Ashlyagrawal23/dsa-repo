class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        int mask = 0;

        // Check bits from left to right
        for (int bit = 31; bit >= 0; bit--) {
            mask |= (1 << bit);

            unordered_set<int> prefixes;

            // Store prefixes of all numbers
            for (int num : nums) {
                prefixes.insert(num & mask);
            }

            // Try setting current bit in answer
            int candidate = maxXor | (1 << bit);

            for (int prefix : prefixes) {
                // If p1 ^ p2 = candidate, then p2 = candidate ^ p1
                if (prefixes.count(candidate ^ prefix)) {
                    maxXor = candidate;
                    break;
                }
            }
        }

        return maxXor;
    }
};