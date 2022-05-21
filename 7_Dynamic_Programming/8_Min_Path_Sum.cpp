#include<vector>
using namespace std;

class Solution {
public:
    int getSolRecursive(vector<vector<int> >& grid, int row, int column) {
        if((row == grid.size()-1) && (column == grid[0].size()-1)) {
            return grid[row][column];
        } else if(row == grid.size()-1) {
            return grid[row][column] + getSolRecursive(grid, row, column+1);
        } else if(column == grid[0].size()-1) {
            return grid[row][column] + getSolRecursive(grid, row+1, column);
        } else {
            return grid[row][column] + min(getSolRecursive(grid, row+1, column), getSolRecursive(grid, row, column+1));
        }
    }
    
    int getSolMemo(vector<vector<int> >& grid, int** table, int row, int column) {
        if(table[row][column] != -1) {
            return table[row][column];
        }
        
        if((row == grid.size()-1) && (column == grid[0].size()-1)) {
            table[row][column] = grid[row][column];
        } else if(row == grid.size()-1) {
            table[row][column] = grid[row][column] + getSolMemo(grid, table, row, column+1);
        } else if(column == grid[0].size()-1) {
            table[row][column] = grid[row][column] + getSolMemo(grid, table, row+1, column);
        } else {
            table[row][column] = grid[row][column] + min(getSolMemo(grid, table, row+1, column), getSolMemo(grid, table, row, column+1));
        }
        
        return table[row][column];
    }

    int getSolDp(vector<vector<int> >& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        int** table = new int*[rows];
        for(int i = 0; i < columns; i++) {
            table[i] = new int[columns];
        }

        table[0][0] = grid[0][0];

        for(int i = 1; i < rows; i++) {
            table[i][0] = grid[i][0] + table[i-1][0];
        }

        for(int j = 1; j < columns; j++) {
            table[0][j] = grid[0][j] + table[0][j-1];
        }

        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < columns; j++) {
                table[i][j] = grid[i][j] + min(table[i-1][j], table[i][j-1]);
            }
        }

        return table[rows-1][columns-1];
    }
    
    int minPathSum(vector<vector<int> >& grid) {
        // return getSolRecursive(grid, 0, 0);
        
        // int** table = new int*[grid.size()];
        
        // for(int i = 0; i < grid.size(); i++) {
        //     table[i] = new int[grid[0].size()];
            
        //     for(int j = 0; j < grid[0].size(); j++) {
        //         table[i][j] = -1;
        //     }
        // }
        
        // return getSolMemo(grid, table, 0, 0);

        return getSolDp(grid);
    }
};