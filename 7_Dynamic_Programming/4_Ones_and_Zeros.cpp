/*
Title: Ones and Zeros

Link: https://leetcode.com/problems/ones-and-zeroes/

Problem Type: Dynamic Programming

Description: You are given an array of binary strings strs and two integers m and n. Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset. A set x is a subset of a set y if all elements of x are also elements of y.
*/
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void countItems(string& str, int& countZero, int& countOne) {
        countZero = 0; countOne = 0;
        
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '0') {
                countZero++;
            } else {
                countOne++;
            }
        }
        return;
    }
    
    int getCountRecursive(vector<string>& strs, int** counts, int m, int n, int index) {
        if(index == strs.size()) {
            return 0;
        }
        
        int take = INT_MIN;
        int not_take = INT_MIN;
        
        if((counts[0][index] <= m) && (counts[1][index] <= n)) {
            take = 1 + getCountRecursive(strs, counts, m - counts[0][index], n - counts[1][index], index+1);
        }
        
        not_take = getCountRecursive(strs, counts, m, n, index+1);
        
        return max(take, not_take);
    }
    
    int getCountMemo(vector<string>& strs, int **counts, int ***table, int m, int n, int index) {
        if((index == strs.size()) || (m + n == 0)) {
            return 0;
        }
        
        if(table[m][n][index] >= 0) {
            return table[m][n][index];
        }
        
        int take = INT_MIN;
        int not_take = INT_MIN;
        
        if((counts[0][index] <= m) && (counts[1][index] <= n)) {
            take = 1 + getCountMemo(strs, counts, table, m - counts[0][index], n - counts[1][index], index + 1);
        }
        
        not_take = getCountMemo(strs, counts, table, m, n, index+1);
        
        table[m][n][index] = max(take, not_take);
        
        return table[m][n][index];
    }
    
    int runMemo(vector<string>& strs, int **counts, int m, int n, int index) {
        int ***table;
        table = new int**[m+1];
        
        for(int i = 0; i < m+1; i++) {
            table[i] = new int*[n+1];
            
            for(int j = 0; j < n+1; j++) {
                table[i][j] = new int[strs.size()];
            }
        }
        
        return getCountMemo(strs, counts, table, m, n, index);
    }
    
    int getCountDp(vector<string>& strs, int **counts, int m, int n) {
        int **table;
        table = new int*[m+1];
        for(int i = 0; i < m+1; i++) {
            table[i] = new int[n+1];
            
            for(int j = 0; j < n+1; j++) {
                table[i][j] = 0;
            }
        }
        
        for(int i = 0; i < strs.size(); i++) {
            for(int j = m; j >= counts[0][i]; j--) {
                for(int k = n; k >= counts[1][i]; k--) {
                    table[j][k] = max(table[j][k], table[j - counts[0][i]][k - counts[1][i]] + 1);
                }
            }
        }
        return table[m][n];
    }
    
    int runDp(vector<string>& strs, int **counts, int m, int n, int index) {
        return getCountDp(strs, counts, m, n);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int **counts;
        counts = new int*[2];
        counts[0] = new int[strs.size()];
        counts[1] = new int[strs.size()];
        
        int current_zeros, current_ones;
        
        for(int i = 0; i < strs.size(); i++) {
            countItems(strs[i], current_zeros, current_ones);
            counts[0][i] = current_zeros;
            counts[1][i] = current_ones;
        }
        
        // return getCountRecursive(strs, counts, m, n, 0);
        // return runMemo(strs, counts, m, n, 0);
        return runDp(strs, counts, m, n, 0);
    }
};