/*
Title: Matrix Chain Multiplication

Link: https://www.codingninjas.com/codestudio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

Problem Type: Dynamic Programming

Description: Minimum cost to multiply matrices.
*/

#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;

int MCMDp(int* arr, int N) {
	int table[N][N];

	for(int i = 1; i < N; i++) {
		table[i][i] = 0;
	}

	int j;
	int cost;

	for(int L = 2; L < N; L++) {
		for(int i = 1; i < N - L + 1; i++) {
			j = i + L - 1;
			table[i][j] = INT_MAX;

			for(int k = i; k < j; k++) {
				cost = table[i][k] + table[k+1][j] + arr[i-1] * arr[k] * arr[j];

				table[i][j] = min(cost, table[i][j]);
			}
		}
	}
	return table[1][N-1];
}

int MCMRecursive(int i, int j, int* arr) {
	if(i == j) {
		return 0;
	}

	int cost = INT_MAX;

	for(int k = i; k < j; k++) {
		cost = min(cost, MCMRecursive(i, k, arr) + MCMRecursive(k+1, j, arr) + arr[i-1] * arr[k] * arr[j]);
	}
	return cost;
}

int MCMMemo(int i, int j, int *arr, int **memo) {
	if(i == j) {
		memo[i][j] = 0;
		return memo[i][j];
	}

	if(memo[i][j] != -1) {
		return memo[i][j];
	}

	memo[i][j] = INT_MAX;

	for(int k = i; k < j; k++) {
		memo[i][j] = min(memo[i][j], MCMMemo(i, k, arr, memo) + MCMMemo(k+1, j, arr, memo) + arr[i-1] * arr[j] * arr[k]);
	}
	
	return memo[i][j];
}

int matrixMultiplication(int* arr, int N) {
	// return MCMRecursive(1, N-1, arr);
	// return MCMDp(arr, N);

	int **memo;
	memo = new int*[N];

	for(int i = 0; i < N; i++) {
		memo[i] = new int[N];
		for(int j = 0; j < N; j++) {
			memo[i][j] = -1;
		}
	}

	return MCMMemo(1, N-1, arr, memo);
}

int main() {
    
    // int N = 4;
    // vector<int> arr {10, 15, 20, 25}; // 8000

    int N = 4;
	int arr[] = {1, 2, 3, 4};

    cout<<matrixMultiplication(arr, N)<<endl;
    return 0;
}