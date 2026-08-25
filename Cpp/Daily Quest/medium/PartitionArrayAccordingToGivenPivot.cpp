/* You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement. */

#include <vector>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        
        int n = nums.size();

        std::vector<int> ans(n);

        int count_less = 0;
        int count_equal = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                count_less++;
            } else if (nums[i] == pivot)
            {
                count_equal++;
            }
        }
        
        int p_less = 0;
        int p_equal = count_less;
        int p_greater = count_less + count_equal;

        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                ans[p_less] = nums[i];
                p_less++;
            } else if (nums[i] == pivot) 
            {
                ans[p_equal] = nums[i];
                p_equal++;
            } else 
            {
                ans[p_greater] = nums[i];
                p_greater++;
            }
        }

        return ans;
        
    }
};