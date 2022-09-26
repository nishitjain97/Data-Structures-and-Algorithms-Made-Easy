#include<iostream>
using namespace std;

#include<string>

void permutation(string str, string prefix) {
    if(str.length() == 0) {
        cout<<prefix<<endl;
        return;
    } else {
        for(int i = 0; i < str.length(); i++) {
            string rem = str.substr(0, i) + str.substr(i+1);
            permutation(rem, prefix + str.at(i));
        }
    }
}

void permutation_(string str) {
    permutation(str, "");
}

int main() {
    permutation_("abc");
    return 0;
}