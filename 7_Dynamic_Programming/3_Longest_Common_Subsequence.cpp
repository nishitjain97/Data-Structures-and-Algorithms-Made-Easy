/*
Title: Longest Common Subsequence

Link: https://leetcode.com/problems/longest-common-subsequence/

Problem Type: Dynamic Programming

Description: Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0. A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int LCSRecursion(string& text1, string& text2, int index1, int index2) {
        if((index1 == text1.length()) || (index2 == text2.length())) {
            return 0;
        }
        
        if(text1[index1] == text2[index2]) {
            return 1 + LCSRecursion(text1, text2, index1 + 1, index2 + 1);
        } else {
            return max(LCSRecursion(text1, text2, index1+1, index2), LCSRecursion(text1, text2, index1, index2+1));
        }
    }
    
    int LCSMemoization(string& text1, string& text2, vector<vector<int> >& table, int index1, int index2) {
        if(table[index1][index2] != -1) {
            return table[index1][index2];
        }
        
        if((index1 == text1.length()) || (index2 == text2.length())) {
            table[index1][index2] = 0;
        } else if (text1[index1] == text2[index2]) {
            table[index1][index2] = 1 + LCSMemoization(text1, text2, table, index1+1, index2+1);
        } else {
            table[index1][index2] = max(LCSMemoization(text1, text2, table, index1+1, index2), LCSMemoization(text1, text2, table, index1, index2+1));
        }
        return table[index1][index2];
    }
    
    int LCSMemoizationCaller(string& text1, string& text2, int index1, int index2) {
        vector<vector<int> > table;
        
        for(int i = 0; i < text1.length()+1; i++) {
            vector<int> temp;
            for(int j = 0; j < text2.length()+1; j++) {
                temp.push_back(-1);
            }
            table.push_back(temp);
        }
        
        return LCSMemoization(text1, text2, table, index1, index2);
    }
    
    int LCSDynamicProgramming(string& text1, string& text2) {
        int m = text1.length(), n = text2.length();
        
        int table[m+1][n+1];
        
        for(int i = 0; i < m+1; i++) {
            table[i][0] = 0;
        }
        
        for(int i = 0; i < n+1; i++) {
            table[0][i] = 0;
        }
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(text1[i-1] == text2[j-1]) {
                    table[i][j] = 1 + table[i-1][j-1];
                } else {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        
        return table[m][n];
    }
    
    int LCSDPCaller(string& text1, string& text2, int index1, int index2) {
        return LCSDynamicProgramming(text1, text2);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        return LCSDPCaller(text1, text2, 0, 0);
    }
};