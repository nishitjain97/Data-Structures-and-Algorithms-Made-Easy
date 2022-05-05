/*
Title: Set Matrix Elements to 0

Link: https://leetcode.com/problems/set-matrix-zeroes/submissions/

Problem Type: Array

Description: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.
*/
#include<vector>
using std::vector;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        bool firstRow = false;
        bool firstColumn = false;
        
        // Check first row for 0
        for(int i = 0; i < columns; i++) {
            // If first row has 0 at any position, 
            // make flag true to clear out first row
            if(matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }
        
        // Check first column for 0
        for(int i = 0; i < rows; i++) {
            // If first column has 0 at any position,
            // make flag true to clear out first column
            if(matrix[i][0] == 0) {
                firstColumn = true;
            }
        }
        
        // Iterate over each element starting from second row and second column
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < columns; j++) {
                // If element at (i, j) is 0,
                // make first row - j column element as 0 and
                // make first column - i row element as 0
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Go through first row
        // If any element is 0, make the whole column 0
        for(int i = 1; i < columns; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < rows; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        // Go through first column
        // If any element is 0, make the whole row 0
        for(int i = 1; i < rows; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < columns; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Finally, check if first row had any 0,
        // then make the whole row 0
        if(firstRow) {
            for(int i = 0; i < columns; i++) {
                matrix[0][i] = 0;
            }
        }
        
        // Check if first column had any 0,
        // then make the whole column 0
        if(firstColumn) {
            for(int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};