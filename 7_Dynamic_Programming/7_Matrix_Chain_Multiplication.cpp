/*
Title: Matrix Chain Multiplication

Link: https://www.codingninjas.com/codestudio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

Problem Type: Dynamic Programming

Description: Minimum cost to multiply matrices.
*/

#include<vector>
#include<iostream>
using namespace std;

int solMCMRecursive(vector<int>& arr, int start, int end) {
	if(start >= end) {
		return 0;
	}
	
	int min_value = INT_MAX;
	int temp;
	
	for(int k = start; k < end; k++) {
		temp = arr[start-1] * arr[k] * arr[end] + solMCMRecursive(arr, start, k) + solMCMRecursive(arr, k+1, end);
		
		min_value = min(min_value, temp);
	}
	
	return min_value;
}

int solMCMMemo(vector<int>& arr, int** table, int start, int end) {
	if(start >= end) {
		return 0;
	}
	
	if(table[start][end] != -1) {
		return table[start][end];
	}
	
	int min_value = INT_MAX;
	int temp;
	
	for(int k = start; k < end; k++) {
		temp = arr[start-1] * arr[k] * arr[end] + solMCMMemo(arr, table, start, k) + solMCMMemo(arr, table, k+1, end);
		
		min_value = min(min_value, temp);
	}
	
	table[start][end] = min_value;
	
	return min_value;
}

int matrixMultiplication(vector<int> &arr, int N)
{
// 	return solMCMRecursive(arr, 1, N-1);
	
	int **table = new int*[N];
	for(int i = 0; i < N; i++) {
		table[i] = new int[N];
		
		for(int j = 0; j < N; j++) {
			table[i][j] = -1;
		}
	}
	
	return solMCMMemo(arr, table, 1, N-1);
}

int main() {
    
    // int N = 4;
    // vector<int> arr {10, 15, 20, 25}; // 8000

    int N = 4;
    vector<int> arr {4, 5, 3, 2}; // 70

    cout<<matrixMultiplication(arr, N)<<endl;
    return 0;
}