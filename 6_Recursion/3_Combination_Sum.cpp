/*
Title: Combination Sum

Link: https://leetcode.com/problems/combination-sum/

Problem Type: Recursion

Description: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different. It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
class Solution {
public:
    void getSum(vector<int> candidates, vector<vector<int>> &result, vector<int> solution, int current_index, int target) {
        if(target < 0) {
            return;
        }
        
        if(target == 0) {
            result.push_back(solution);
            return;
        }
        
        for(int i = current_index; i < candidates.size(); i++) {
            if(target - candidates[i] < 0) {
                break;
            }
            solution.push_back(candidates[i]);
            getSum(candidates, result, solution, i, target - candidates[i]);
            solution.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        getSum(candidates, result, vector<int>(0), 0, target);
        return result;
    }
};