#include<iostream>
using namespace std;

int recEditDistance(string &x, int i, string &y, int j) {
    if(i == 0) {
        return j;
    }
    if(j == 0) {
        return i;
    }
    
    int case1 = 1 + recEditDistance(x, i-1, y, j);
    int case2 = 1 + recEditDistance(x, i, y, j-1);
    int case3;
    if(x[i-1] == y[j-1]) {
        case3 = 0;
    } else {
        case3 = 1;
    }
    case3 += recEditDistance(x, i-1, y, j-1);
    return min(case1, min(case2, case3));
}

int dp1EditDistance(string &x, int m, string &y, int n) {
    int table[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                table[i][j] = j;
            } else if(j == 0) {
                table[i][j] = i;
            } else if(x[i-1] == y[j-1]) {
                table[i][j] = table[i-1][j-1];
            } else {
                table[i][j] = 1 + min(table[i-1][j-1], min(table[i-1][j], table[i][j-1]));
            }
        }
    }

    return table[m][n];
}

int dp2EditDistance(string &x, string &y) {
    int l1 = x.length();
    int l2 = y.length();

    int table[2][l1+1];

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < l1+1; j++) {
            table[i][j] = 0;
        }
    }

    for(int i = 0; i < l1+1; i++) {
        table[0][i] = i;
    }

    for(int i = 1; i < l2+1; i++) {
        for(int j = 0; j < l1+1; j++) {
            if(j == 0) {
                table[i%2][j] = i;
            } else if(x[j-1] == y[i-1]) {
                table[i%2][j] = table[(i-1)%2][j-1];
            } else {
                table[i%2][j] = 1 + min(min(table[(i-1)%2][j], table[i%2][j-1]), table[(i-1)%2][j-1]);
            }
        }
    }

    return table[l2%2][l1];
}

int main() {
    string x = "exponential";
    string y = "polynomial";

    // cout<<dp1EditDistance(x, x.length(), y, y.length())<<endl;
    cout<<dp2EditDistance(x, y)<<endl;

    return 0;
}