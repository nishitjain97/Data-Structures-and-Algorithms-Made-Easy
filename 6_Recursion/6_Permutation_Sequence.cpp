/*
Title: Permutation Sequence

Link: https://leetcode.com/problems/permutation-sequence/

Problem Type: Recursion

Description: The set [1, 2, 3, ..., n] contains a total of n! unique permutations. By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the kth permutation sequence.
*/
class Solution {
public:
    int getFactorial(int n) {
        if(n == 1) {
            return 1;
        }
        return n * getFactorial(n-1);
    }
    
    string getPermutation(int n, int k) {
        int perms = getFactorial(n);
        
        bool position_used[n+1];
        
        for(int i = 0; i < n; i++) {
            position_used[i+1] = false;
        }
        
        for(int i = n; i > 0; i--) {
            int c_perms = perms / i;
            int j = n;
            while((j > 0) && (k-c_perms) > 0) {
                k -= c_perms;
                j--;
            }
        }
        
        return "Hello";
    }
};