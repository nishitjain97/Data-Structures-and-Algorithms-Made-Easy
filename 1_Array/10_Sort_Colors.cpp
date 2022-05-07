/*
Title: Sort Colors

Link: https://leetcode.com/problems/sort-colors/

Problem Type: Array

Description: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*/

#include<vector>
#include<utility>
using std::vector;
using std::swap;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        
        while(mid <= end) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[start]);
                start++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};