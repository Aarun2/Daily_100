#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1_sz = nums1.size();
    int n2_sz = nums2.size();
    int sel = n1_sz + n2_sz;
    if ((sel % 2) == 0) {
        // cout << "Reached" << endl;
        sel = sel/2;
        int val1;
        if (sel < n1_sz)
            val1 = nums1[sel];
        else
            val1 = nums2[sel - n1_sz];
        sel--;
        int val2;
        if (sel < n1_sz)
            val2 = nums1[sel];
        else
            val2 = nums2[sel - n1_sz];
        double ret = (val1+val2) / 2.0;
        return ret;
        
    }
    else {
        // cout << "Reached" << endl;
        // cout << sel << endl;
        sel = sel / 2;
        if (sel < n1_sz) {
            // cout << nums1.at(0) << endl;
            return nums1[sel];   
        }
        else
            return nums2[sel - n1_sz];
    }
}

int main() {
    // vector<int> nums1 {1, 3};
    // vector<int> nums2 {2};
    // vector<int> nums1 {1, 2};
    // vector<int> nums2 {3, 4};
    vector<int> nums1 {0, 0};
    vector<int> nums2 {0, 0};
    // cout << nums1.at(0) << endl;
    double ret = findMedianSortedArrays(nums1, nums2);
    // cout << ret << endl;
    return 0;
}