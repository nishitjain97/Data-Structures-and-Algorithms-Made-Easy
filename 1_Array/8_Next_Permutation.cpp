/*
Title: Next Permutation

Link: https://leetcode.com/problems/next-permutation/

Problem Type: Array

Description: The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
*/

#include<vector>
using std::vector;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max_index, current_index;
        for(int i = nums.size()-1; i >= 0; i--) {
            max_index = -1;
            for(int j = i+1; j < nums.size(); j++) {
                if((nums.at(j) > nums.at(i)) && (max_index == -1)) {
                    max_index = j;
                } else if((nums.at(j) > nums.at(i)) && (nums.at(j) < nums.at(max_index))) {
                    max_index = j;
                }
            }
            if(max_index != -1) {
                current_index = i;
                break;
            }
        }
        
        if(max_index != -1) {
            nums.at(current_index) = nums.at(current_index) + nums.at(max_index);
            nums.at(max_index) = nums.at(current_index) - nums.at(max_index);
            nums.at(current_index) = nums.at(current_index) - nums.at(max_index);
        } else {
            current_index = -1;
        }

        for(int i = current_index+1; i < nums.size()-1; i++) {
            int min_index = i;
            for(int j = i+1; j < nums.size(); j++) {
                if(nums.at(j) < nums.at(min_index)) {
                    min_index = j;
                }
            }
            
            if(i != min_index) {
                nums.at(i) = nums.at(i) + nums.at(min_index);
                nums.at(min_index) = nums.at(i) - nums.at(min_index);
                nums.at(i) = nums.at(i) - nums.at(min_index);
            }
        }
    }
};