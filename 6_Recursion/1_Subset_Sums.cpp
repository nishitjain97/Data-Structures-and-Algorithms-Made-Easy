/*
Title: Subset Sums

Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

Problem Type: Recursion

Description: Given a list arr of N integers, print sums of all subsets in it.
*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void generateSum(vector<int> arr, vector<int> &result, int previous_index, int previous_sum, int N) {
        if(previous_index + 1 == N) {
            return;
        }
        for(int i = previous_index + 1; i < N; i++) {
            result.push_back(previous_sum + arr[i]);
            generateSum(arr, result, i, previous_sum + arr[i], N);
        }
        return;
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> result;
        result.push_back(0);
        generateSum(arr, result, -1, 0, N);
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends