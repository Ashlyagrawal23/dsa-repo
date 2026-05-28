class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Make sure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {

            int partitionX = (left + right) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            // Correct partition found
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {

                // If total length is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) +
                            min(minRightX, minRightY)) / 2.0;
                }
                // If total length is odd
                else {
                    return max(maxLeftX, maxLeftY);
                }
            }

            // Move towards left in nums1
            else if (maxLeftX > minRightY) {
                right = partitionX - 1;
            }

            // Move towards right in nums1
            else {
                left = partitionX + 1;
            }
        }

        return 0.0;
    }
};