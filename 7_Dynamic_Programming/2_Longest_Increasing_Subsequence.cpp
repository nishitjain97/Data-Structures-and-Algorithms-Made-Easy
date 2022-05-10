/*
Title: Longest Increasing Subsequence

Link: https://leetcode.com/problems/longest-increasing-subsequence/

Problem Type: Dynamic Programming

Description: Given an integer array nums, return the length of the longest strictly increasing subsequence. A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Initialize table for dp
        vector<int> db;
        for(int i = 0; i < nums.size(); i++) {
            db.push_back(1);
        }
        
        for(int i = nums.size()-1; i > -1; i--) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] < nums[j]) {
                    db[i] = max(db[i], 1 + db[j]);
                }
            }
        }
        
        int return_max = INT_MIN;
        
        for(int i = 0; i < db.size(); i++) {
            if(db[i] > return_max) {
                return_max = db[i];
            }
        }
        return return_max;
    }
};