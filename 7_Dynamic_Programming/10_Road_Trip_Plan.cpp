/*
Title: Road Trip Plan

Problem Type: Dynamic Programming

Description: Minimum penalty during road trip.
*/

#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;

int tripRec(int source, int destination, int* arr) {
	if((arr[destination] - arr[source]) <= 100) {
		int cost = pow(100 - (arr[destination] - arr[source]), 2);
		return cost;
	}

	int cost = INT_MAX;

	for(int rest_stop = source + 1; rest_stop < destination; rest_stop++) {
		cost = min(cost, tripRec(source, rest_stop, arr) + tripRec(rest_stop, destination, arr));
	}
	return cost;
}

int tripMemo(int source, int destination, int* arr, int** memo) {
	if(memo[source][destination] != -1) {
		return memo[source][destination];
	}

	if((arr[destination] - arr[source]) <= 100) {
		memo[source][destination] = pow(100 - (arr[destination] - arr[source]), 2);
	} else {
		memo[source][destination] = INT_MAX;
		for(int rest_stop = source + 1; rest_stop < destination; rest_stop++) {
			memo[source][destination] = min(memo[source][destination], tripMemo(source, rest_stop, arr, memo) + tripMemo(rest_stop, destination, arr, memo));
		}
	}
	return  memo[source][destination];
}

int tripDp(int initial_source, int final_destination, int* arr, int N) {
	int table[N][N];

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			table[i][j] = -1;
		}
	}

	for(int destination = initial_source; destination <= final_destination; destination++) {
		for(int source = destination; source >= initial_source; source--) {
			if((arr[destination] - arr[source]) <= 100) {
				table[source][destination] = pow(100 - (arr[destination] - arr[source]), 2);
			} else {
				table[source][destination] = INT_MAX;
				for(int rest_stop = source + 1; rest_stop < destination; rest_stop++) {
					table[source][destination] = min(table[source][destination], table[source][rest_stop] + table[rest_stop][destination]);
				}
			}
		}
	}
	
	return table[initial_source][final_destination];
}

int tripPlanning(int* arr, int N) {
	// int **memo = new int*[N];
	// for(int i = 0; i < N; i++) {
	// 	memo[i] = new int[N];
	// 	for(int j = 0; j < N; j++) {
	// 		memo[i][j] = -1;
	// 	}
	// }

	// int output = tripMemo(0, N-1, arr, memo);
	// for(int i = 0; i < N; i++) {
	// 	for(int j = 0; j < N; j++) {
	// 		cout<<memo[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }

	// return output;
	// return tripRec(0, N-1, arr);
	return tripDp(0, N-1, arr, N);
}

int main() {
	// int N = 11;
	// int arr[N];
	// arr[0] = 0;
	// for(int i = 1; i < N; i++) {
	// 	arr[i] = i * 10;
	// }

	int arr[] = {0, 60, 100, 120};
	int N = sizeof(arr) / sizeof(arr[0]);
	cout<<tripPlanning(arr, N)<<endl;
    return 0;
}