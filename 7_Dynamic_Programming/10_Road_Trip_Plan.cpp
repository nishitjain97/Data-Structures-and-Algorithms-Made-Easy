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
	int cost1, cost2;

	for(int rest_stop = source + 1; rest_stop < destination; rest_stop++) {
		if((arr[rest_stop] - arr[source]) <= 100) {
			cost1 = pow(100 - (arr[rest_stop] - arr[source]), 2);
		} else {
			cost1 = tripRec(source, rest_stop, arr);
		}

		if((arr[destination] - arr[rest_stop]) <= 100) {
			cost2 = pow(100 - (arr[destination] - arr[rest_stop]), 2);
		} else {
			cost2 = tripRec(rest_stop, destination, arr);
		}

		cost = min(cost, cost1 + cost2);
	}
	return cost;
}



int tripMemo(int source, int destination, int* arr, int** memo) {
	if((arr[destination] - arr[source]) <= 100) {
		int cost = pow(100 - (arr[destination] - arr[source]), 2);
		memo[source][destination] = cost;
		return memo[source][destination];
	}

	if(memo[source][destination] != -1) {
		return memo[source][destination];
	}

	memo[source][destination] = INT_MAX;
	int cost1, cost2;

	for(int rest_stop = source + 1; rest_stop < destination; rest_stop++) {
		if((arr[rest_stop] - arr[source]) <= 100) {
			cost1 = pow(100 - (arr[rest_stop] - arr[source]), 2);
		} else {
			cost1 = tripRec(source, rest_stop, arr);
		}

		if((arr[destination] - arr[rest_stop]) <= 100) {
			cost2 = pow(100 - (arr[destination] - arr[rest_stop]), 2);
		} else {
			cost2 = tripRec(rest_stop, destination, arr);
		}

		memo[source][destination] = min(memo[source][destination], cost1 + cost2);
	}
	return memo[source][destination];
}

int tripPlanning(int* arr, int N) {
	int **memo = new int*[N];
	for(int i = 0; i < N; i++) {
		memo[i] = new int[N];
		for(int j = 0; j < N; j++) {
			memo[i][j] = -1;
		}
	}
	return tripMemo(0, N-1, arr, memo);
	// return tripRec(0, N-1, arr);
}

int main() {
	int N = 25;
	int arr[N];
	arr[0] = 0;
	for(int i = 1; i < N; i++) {
		arr[i] = i * 10;
	}
	cout<<tripPlanning(arr, N)<<endl;
    return 0;
}