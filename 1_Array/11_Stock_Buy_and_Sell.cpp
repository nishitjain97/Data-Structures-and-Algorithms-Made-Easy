/*
Title: Stock Buy and Sell

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Problem Type: Array

Description: You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include<vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_min = prices[0];
        int max_prof = 0;
        for(int i = 0; i < prices.size(); i++) {
            int cur_prof = prices[i] - prev_min;
            if(cur_prof > max_prof) {
                max_prof = cur_prof;
            }
            if(prices[i] < prev_min) {
                prev_min = prices[i];
            }
        }
        return max_prof;
    }
};