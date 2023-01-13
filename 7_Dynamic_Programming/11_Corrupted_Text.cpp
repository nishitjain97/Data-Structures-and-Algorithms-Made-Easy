#include<iostream>
#include<string.h>
using namespace std;

bool check_dict(string word) {
    if(word == "i" || word == "am" || word == "the" || word == "there" || word == "king" || word == "a") {
        return true;
    }
    return false;
}

bool check_construction(string s) {
    bool memo[s.length()];

    memo[0] = check_dict(s.substr(0, 1));

    for(int i = 1; i < s.length(); i++) {
        for(int j = 0; j < i; j++) {
            bool first_half = memo[j];

            bool second_half = check_dict(s.substr(j+1, i-j));

            memo[i] = first_half & second_half;

            if(memo[i]) {
                break;
            }
        }
    }
    return memo[s.length()-1];
}

void sequence_of_words(string s) {
    int memo[s.length()];

    for(int i = 0; i < s.length(); i++) {
        memo[i] = -1;
    }

    if(check_dict(s.substr(0, 1))) {
        memo[0] = 0;
    }

    for(int i = 1; i < s.length(); i++) {
        for(int j = 0; j < i; j++) {
            int first_half = memo[j];

            if((memo[j] != -1) && (check_dict(s.substr(j+1, i-j)))) {
                memo[i] = j;
            }

            if(memo[i] != -1) {
                break;
            }
        }
    }
    
    int k = s.length()-1;
    while(memo[k] != k) {
        cout<<k<<' ';
        k = memo[k];
    }
    cout<<k<<endl;
    return;
}

int main() {
    string s = "iamthereking";
    cout<<check_construction(s)<<endl;
    sequence_of_words(s);
    return 0;
}