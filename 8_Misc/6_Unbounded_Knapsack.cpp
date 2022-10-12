#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int recSolutionKnapsack(int W, int val[], int wt[], int index) {
    if(index == 0) {
        return (W / wt[index]) * val[index];
    }

    int notTake = recSolutionKnapsack(W, val, wt, index-1);

    int take = INT_MIN;

    if(wt[index] <= W) {
        take = val[index] + recSolutionKnapsack(W - wt[index], val, wt, index);
    }
    return max(notTake, take);
}

// int main() {
//     int W = 100;
//     int val[] = {10, 30, 20};
//     int wt[] = {5, 10, 15};
//     int n = sizeof(val) / sizeof(int);

//     cout<<recSolutionKnapsack(W, val, wt, n-1)<<endl;
//     return 0;
// }

int dp1Solution(int W, int val[], int wt[], int index, vector<vector<int> >& table) {
    if(index == 0) {
        return(W / wt[index]) * val[index];
    }

    if(table[index][W] != -1) {
        return table[index][W];
    }

    int notTake = dp1Solution(W, val, wt, index-1, table);

    int take = INT_MIN;
    if(wt[index] <= W) {
        take = val[index] + dp1Solution(W-wt[index], val, wt, index, table);
    }

    return table[index][W] = max(notTake, take);
}

// int main() {
//     int W = 100;
//     int val[] = {10, 30, 20};
//     int wt[] = {5, 10, 15};
//     int n = sizeof(val) / sizeof(int);
    
//     vector<vector<int> > table(n, vector<int>(W+1, -1));

//     cout<<dp1Solution(W, val, wt, n-1, table)<<endl;
//     return 0;
// }

int dp2Solution(int &W, int val[], int wt[], int &n) {
    int table[W+1];
    
    for(int i = 0; i <= W; i++) {
        table[i] = 0;
    }

    for(int i = 0; i <= W; i++) {
        for(int j = 0; j < n; j++) {
            if(wt[j] <= i) {
                table[i] = max(table[i], table[i - wt[j]] + val[j]);
            }
        }
    }
    return table[W];
}

int main() {
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(int);

    cout<<dp2Solution(W, val, wt, n)<<endl;
    return 0;
}