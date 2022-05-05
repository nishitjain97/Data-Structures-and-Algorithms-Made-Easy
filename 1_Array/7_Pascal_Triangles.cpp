/*
Title: Pascal's Triangles

Link: https://leetcode.com/problems/pascals-triangle/

Problem Type: Array

Description: Given an integer numRows, return the first numRows of Pascal's triangle. In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/
#include<vector>
using std::vector;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pascalTry(numRows);
        
        for(int i = 1; i < numRows+1; i++) {
            pascalTry[i-1] = vector<int>(i);
            
            for(int j = 1; j <= i; j++) {
                if((j == 1) || (j == i)) {
                    pascalTry[i-1][j-1] = 1;
                } else {
                    pascalTry[i-1][j-1] = pascalTry[i-2][j-2] + pascalTry[i-2][j-1];
                }
            }
        }
        
        return pascalTry;
    }
};