/*
Title: Palindrome Partitioning

Link: https://leetcode.com/problems/palindrome-partitioning/

Problem Type: Recursion

Description: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s. A palindrome string is a string that reads the same backward as forward.
*/
class Solution {
public:
    bool isPalin(string s) {
        for(int i = 0; i < s.length() / 2; i++) {
            if(s[i] != s[s.length()-1 - i]) {
                return false;
            }
        }
        return true;
    }
    
    void getPalin(vector<vector<string>> &result, vector<string> current_solution, int current_index) {
        for(int i = current_index; i < current_solution.size()-1; i++) {
            vector<string> new_solution(current_solution);
            
            string current_change = current_solution[i] + current_solution[i+1];
            
            new_solution.erase(new_solution.begin() + i);
            new_solution.erase(new_solution.begin() + i);
            
            new_solution.insert(new_solution.begin() + i, current_change);
            
            if(isPalin(current_change)) {
                bool palin_check = true;
                
                for(int j = 0; j < new_solution.size(); j++) {
                    if(!isPalin(new_solution[j])) {
                        palin_check = false;
                        break;
                    }
                }
                
                if(palin_check) {
                    result.push_back(new_solution);
                }
            }
            
            getPalin(result, new_solution, i);
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        
        vector<string> current_solution;
        for(int i = 0; i < s.length(); i++) {
            current_solution.push_back(s.substr(i, 1));
        }
        
        result.push_back(current_solution);
        
        getPalin(result, current_solution, 0);
        
        return result;
    }
};