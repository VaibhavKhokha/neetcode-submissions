class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int left1 = 0;
        int left2 = 0;

        int total = nums1.size() + nums2.size();

        int pivot = total / 2;

        vector<int> temp;

        while(temp.size() <= pivot)
        {
            if(left1 < nums1.size() && (left2 >= nums2.size() || nums1[left1] <= nums2[left2]))
            {
                temp.push_back(nums1[left1]);
                left1++;
            }
            else
            {
                temp.push_back(nums2[left2]);
                left2++;
            }

        }

        if(total % 2 == 0)
        {
            return (temp[pivot] + temp[pivot - 1]) / 2.0;
        }
        else
        {
            return temp[pivot];
        }


    }

};
