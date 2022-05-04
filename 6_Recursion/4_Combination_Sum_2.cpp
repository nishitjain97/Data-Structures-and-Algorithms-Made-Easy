/*
Title: Combination Sum 2

Link: https://leetcode.com/problems/combination-sum-ii/

Problem Type: Recursion

Description: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination. Note: The solution set must not contain duplicate combinations.
*/
class Solution {
public:
    void getSum(vector<int> candidates, vector<vector<int>> &result, vector<int> &current_solution, int current_index, int target) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            result.push_back(current_solution);
            return;
        }
        
        int previous_element = -1;
        
        for(int i = current_index; i < candidates.size(); i++) {
            if(candidates[i] == previous_element) {
                continue;
            } else {
                previous_element = candidates[i];
            }
            if((target - candidates[i]) < 0) {
                break;
            }
            current_solution.push_back(candidates[i]);
            getSum(candidates, result, current_solution, i+1, target - candidates[i]);
            current_solution.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> current_solution(0);
        
        vector<vector<int>> result;
        getSum(candidates, result, current_solution, 0, target);
        return result;
    }
};