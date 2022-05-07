/*
Title: Rotate Image

Link: https://leetcode.com/problems/rotate-image/

Problem Type: Array

Description: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise). You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/
#include<vector>
using std::vector;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Flip horizontally
        for(int i = 0; i < matrix.size() / 2; i++) {
            for(int row = 0; row < matrix.size(); row++) {
                swap(matrix[row][i], matrix[row][matrix.size()-i-1]);
            }
        }
        
        // Flip along positive diagonal
        for(int i = 0; i < matrix.size()-1; i++) {
            for(int j = 0; j < matrix.size()-1-i; j++) {
                swap(matrix[i][j], matrix[matrix.size()-1-j][matrix.size()-1-i]);
            }
        }
    }
};