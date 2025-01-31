//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    bool isValid(vector<vector<int>>& board, int row, int col, int num) {
        // Check row
        for(int x = 0; x < 9; x++) {
            if(board[row][x] == num) return false;
        }
        
        // Check column
        for(int x = 0; x < 9; x++) {
            if(board[x][col] == num) return false;
        }
        
        // Check 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i + startRow][j + startCol] == num) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<int>>& board) {
        int row = -1;
        int col = -1;
        bool isEmpty = false;
        
        // Find an empty cell
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == 0) {
                    row = i;
                    col = j;
                    isEmpty = true;
                    break;
                }
            }
            if(isEmpty) break;
        }
        
        // If no empty cell found, puzzle is solved
        if(!isEmpty) return true;
        
        // Try digits 1-9 for the empty cell
        for(int num = 1; num <= 9; num++) {
            if(isValid(board, row, col, num)) {
                board[row][col] = num;
                if(solve(board)) return true;
                board[row][col] = 0; // Backtrack
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<int>>& mat) {
        solve(mat);
    }
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends