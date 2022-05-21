#include<vector>
using namespace std;

class Solution {
public:
    int getSolRecursive(vector<int>& coins, int amount, int index, int count) {
        if(index == coins.size()) {
            return INT_MAX;
        }
        
        if(amount == 0) {
            return count;
        }
        
        if(amount < 0) {
            return INT_MAX;
        }
        
        int take_and_move = getSolRecursive(coins, amount - coins[index], index+1, count+1);
        int take_and_repeat = getSolRecursive(coins, amount - coins[index], index, count+1);
        int not_take = getSolRecursive(coins, amount, index+1, count);
        
        return min(take_and_move, min(take_and_repeat, not_take));
    }
    
    int getSolMemo(vector<int>& coins, int** table, int amount, int index, int count) {
        if(index == coins.size()) {
            return INT_MAX;
        }
        
        if(amount == 0) {
            return count;
        }
        
        if(amount < 0) {
            return INT_MAX;
        }
        
        if(table[index][amount] != -1) {
            return table[index][amount];
        }
        
        int take_and_move = getSolRecursive(coins, amount - coins[index], index+1, count+1);
        int take_and_repeat = getSolRecursive(coins, amount - coins[index], index, count+1);
        int not_take = getSolRecursive(coins, amount, index+1, count);
        
        table[index][amount] = min(take_and_move, min(take_and_repeat, not_take));
        
        return table[index][amount];
    }
    
    int getSolDp(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        
        int** table;
        table = new int*[coins.size()];
        
        for(int i = 0; i < coins.size(); i++) {
            table[i] = new int[amount+1];
            for(int j = 0; j < amount+1; j++) {
                if(j == 0) {
                    table[i][j] = 0;
                } else {
                    table[i][j] = 1e9;
                }
            }
        }
        
        for(int j = 0; j < amount+1; j++) {
            if(j % coins[0] == 0) {
                table[0][j] = j / coins[0];
            }
        }
        
        for(int i = 1; i < coins.size(); i++) {
            for(int j = 0; j < amount+1; j++) {
                if(coins[i] <= j) {
                    table[i][j] = min(1 + table[i][j - coins[i]], table[i-1][j]);
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        
        return table[coins.size()-1][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // int answer = getSolRecursive(coins, amount, 0, 0);
        
//         int** table = new int*[coins.size()];
        
//         for(int i = 0; i < coins.size(); i++) {
//             table[i] = new int[amount+1];
            
//             for(int j = 0; j < amount+1; j++) {
//                 table[i][j] = -1;
//             }
//         }
        
//         int answer = getSolMemo(coins, table, amount, 0, 0);
        
        
        int answer = getSolDp(coins, amount);
        
        if(answer >= 1e9) {
            return -1;
        } else {
            return answer;
        }
    }
};