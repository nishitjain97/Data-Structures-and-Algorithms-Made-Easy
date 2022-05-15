/*
Title: Edit Distance

Link: https://leetcode.com/problems/edit-distance/

Problem Type: Dynamic Programming

Description: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int distRecursion(string& word1, string& word2, int index1, int index2) {
        if((index1 < 0) && (index2 < 0)) {
            return 0;
        }
        
        if(index1 < 0) {
            return index2 + 1;
        }
        
        if(index2 < 0) {
            return index1 + 1;
        }
        
        if(word1[index1] == word2[index2]) {
            return 0 + distRecursion(word1, word2, index1-1, index2-1);
        } else {
            return min(
                1 + distRecursion(word1, word2, index1-1, index2), // Delete
                min(
                    1 + distRecursion(word1, word2, index1, index2-1), // Insert
                    1 + distRecursion(word1, word2, index1-1, index2-1) // Replace
                )
            );
        }
    }
    
    int callRecursion(string& word1, string& word2) {
        return distRecursion(word1, word2, word1.length()-1, word2.length()-1);
    }
    
    int distMemo(string& word1, string& word2, int** table, int index1, int index2) {
        if((index1 < 0) && (index2 < 0)) {
            return 0;
        }
        
        if(index1 < 0) {
            return index2 + 1;
        }
        
        if(index2 < 0) {
            return index1 + 1;
        }
        
        if(table[index1][index2] > -1) {
            return table[index1][index2];
        }
        
        if(word1[index1] == word2[index2]) {
            table[index1][index2] = 0 + distRecursion(word1, word2, index1-1, index2-1);
            return table[index1][index2];
        } else {
            table[index1][index2] = min(
                1 + distRecursion(word1, word2, index1-1, index2), // Delete
                min(
                    1 + distRecursion(word1, word2, index1, index2-1), // Insert
                    1 + distRecursion(word1, word2, index1-1, index2-1) // Replace
                )
            );
            
            
            return table[index1][index2];
        }
    }
    
    int callMemo(string& word1, string& word2) {
        int** table;
        table = new int*[word1.length()];
        
        for(int i = 0; i < word1.length(); i++) {
            table[i] = new int[word2.length()];
            
            for(int j = 0; j < word2.length(); j++) {
                table[i][j] = -1;
            }
        }
        
        return distMemo(word1, word2, table, word1.length()-1, word2.length()-1);
    }
    
    int distDp(string& word1, string& word2) {
        int m = word1.length(), n = word2.length();
        
        int table[m+1][n+1];
        
        for(int i = 0; i < m+1; i++) {
            table[i][0] = i;
        }
        
        for(int j = 0; j < n+1; j++) {
            table[0][j] = j;
        }
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(word1[i-1] == word2[j-1]) {
                    table[i][j] = table[i-1][j-1];
                } else {
                    table[i][j] = min(
                        1 + table[i-1][j-1],
                        min(
                            1 + table[i][j-1],
                            1 + table[i-1][j]
                        )
                    );
                }
            }
        }
        return table[m][n];
    }
    
    int minDistance(string word1, string word2) {
        return distDp(word1, word2);
    }
};