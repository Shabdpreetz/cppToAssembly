// converting cpp program into Assembly using this command in minGW

// cmd

// gcc -S MedianOf2SortedArray.cpp 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// (Include the function here)
int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high) {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];

        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) {
                return max(l1, l2);
            }
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return 0;
}


int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1: " << findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Test 2: " << findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.5

    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Test 3: " << findMedianSortedArrays(nums1, nums2) << endl; // Output: 0.0

    nums1 = {};
    nums2 = {1};
    cout << "Test 4: " << findMedianSortedArrays(nums1, nums2) << endl; // Output: 1.0

    nums1 = {2};
    nums2 = {};
    cout << "Test 5: " << findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    return 0;
}
