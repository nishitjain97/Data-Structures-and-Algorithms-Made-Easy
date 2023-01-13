#include<iostream>
#include<string.h>
using namespace std;

int lcsRec(string &s1, string &s2, int index1, int index2, int count) {
    if(index1 == -1 || index2 == -1) {
        return count;
    }

    if(s1[index1] == s2[index2]) {
        count = lcsRec(s1, s2, index1-1, index2-1, count + 1);
    }

    count = max(
        count,
        max(
            lcsRec(s1, s2, index1-1, index2, 0),
            lcsRec(s1, s2, index1, index2-1, 0)
        )
    );
    return count;
}

int lcsDp(string &s1, string &s2) {
    int table[s1.length()+1][s2.length()+1];

    int result = 0;

    for(int i = 0; i <= s1.length(); i++) {
        for(int j = 0; j <= s2.length(); j++) {
            if(i == 0 || j == 0) {
                table[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                result = max(result, table[i][j]);
            } else {
                table[i][j] = 0;
            }
        }
    }
    return result;
}

int main() {
    string first = "nishit";
    string second = "youshit";
    // cout<<lcsRec(first, second, first.length()-1, second.length()-1, 0)<<endl;
    
    cout<<lcsDp(first, second)<<endl;
    return 0;
}