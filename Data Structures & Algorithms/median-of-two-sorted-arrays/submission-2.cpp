class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Optional:- Ensure nums1 is the smaller array to optimize more.
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        // Suppose both nums1 & nums2 are merged then median will present at the mid of the merged array
        // So half of the elements will be on the left side of array and half on the other. 
        int halfArrraySize = (n1 + n2) / 2;

        int left = 0;
        int right = n1;  // We didn't choose n1-1 to get proper partition of arr

        while(left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = halfArrraySize - partition1;

            // All the elements on the left of both arrays after partition <= right side elements 
            int left1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            int left2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
            int right1 = partition1 == n1 ? INT_MAX : nums1[partition1];
            int right2 = partition2 == n2 ? INT_MAX : nums2[partition2];

            if (left1 > right2) right = partition1 - 1;
            else if (left2 > right1) left = partition1 + 1;
            else {
                return (n1 + n2) % 2 == 0 
                        ? ((double)max(left1, left2) + (double)min(right1, right2))/2
                        : (double)min(right1, right2);
            }
        }
        return -1.0;
    }
};