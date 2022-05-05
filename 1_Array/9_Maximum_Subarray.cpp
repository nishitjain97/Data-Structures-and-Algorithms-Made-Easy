/*
Title: Maximum Subarray

Link: https://leetcode.com/problems/maximum-subarray/submissions/

Problem Type: Array

Description: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/
#include<vector>
using std::vector;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            if(current_sum > max_sum) {
                max_sum = current_sum;
            }
            
            if(current_sum < 0) {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};