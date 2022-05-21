/*
Title: Max Sum Increasing Subsequence

Link: https://www.codingninjas.com/codestudio/problems/1112624?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Problem Type: Dynamic Programming
*/

#include<vector>
#include<iostream>
using namespace std;

int getSolRecursive(vector<int> &rack, int& n, int previous_index, int current_index) {
    if(current_index == n) {
        return 0;
    }

    int previous_value = INT_MIN;
    
    if(previous_index != -1) {
        previous_value = rack[previous_index];
    }

    if(rack[current_index] > previous_value) {
        return max(rack[current_index] + getSolRecursive(rack, n, current_index, current_index + 1), getSolRecursive(rack, n, previous_index, current_index + 1));
    } else {
        return getSolRecursive(rack, n, previous_index, current_index + 1);
    }
}

int getSolMemo(vector<int>& rack, int& n, int** table, int previous_index, int current_index) {
    if(current_index == n+1) {
        return 0;
    }

    if(table[current_index][previous_index] != INT_MIN) {
        return table[current_index][previous_index];
    }

    int previous_value = INT_MIN;

    if(previous_index != 0) {
        previous_value = rack[previous_index-1];
    }

    if(rack[current_index-1] > previous_value) {
        table[current_index][previous_index] = max(rack[current_index-1] + getSolMemo(rack, n, table, current_index, current_index + 1), getSolMemo(rack, n, table, previous_index, current_index + 1));
    } else {
        table[current_index][previous_index] = getSolMemo(rack, n, table, previous_index, current_index + 1);
    }

    return table[current_index][previous_index];
}

int getSolDp(vector<int>& rack, int& n) {
    int* table = new int[n];
    table[0] = rack[0];
    int max_val = table[0];

    for(int i = 1; i < n; i++) {
        table[i] = rack[i];

        for(int j = 0; j < i; j++) {
            if(rack[j] < rack[i]) {
                table[i] = max(rack[i] + table[j], table[i]);
            }
        }

        if(table[i] > max_val) {
            max_val = table[i];
        }
    }

    return max_val;
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // return getSolRecursive(rack, n, -1, 0);

    // int** table = new int*[n+1];
    // for(int i = 0; i < n+1; i++) {
    //     table[i] = new int[n+1];
    //     for(int j = 0; j < n+1; j++) {
    //         table[i][j] = INT_MIN;
    //     }
    // }

    // return getSolMemo(rack, n, table, 0, 1);

    return getSolDp(rack, n);
}

int main() {
    // int n = 4;
    // vector<int> rack {9, 1, 2, 8}; // 11

    // int n = 1;
    // vector<int> rack {8}; // 8

    // int n = 6;
    // vector<int> rack {1, 2, 3, 4, 5, 6}; // 21

    // int n = 3;
    // vector<int> rack {3, 2, 1}; // 3

    // int n = 4;
    // vector<int> rack {1, 2, 1, 3}; // 6

    // int n = 4;
    // vector<int> rack {1, 2, 2, 1}; // 3

    int n = 1;
    vector<int> rack {1}; // 1

    cout<<maxIncreasingDumbbellsSum(rack, n)<<endl;
    return 0;
}