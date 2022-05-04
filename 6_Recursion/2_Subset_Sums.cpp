/*
Title: Subset Sums 2

Link: https://leetcode.com/problems/subsets-ii/

Problem Type: Recursion

Description: Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result = {{}};
        vector<int> current;
        int size;
        
        for(int i = 0; i < nums.size(); i++) {
            size = result.size();
            
            for(int j = 0; j < size; j++) {
                current = result[j];
                current.push_back(nums[i]);
                
                if(find(result.begin(), result.end(), current) == result.end()) {
                    result.push_back(current);
                }
            }
        }
        return result;
    }
};