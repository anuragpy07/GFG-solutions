//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> board;
        function<void(int, bitset<10>, bitset<20>, bitset<20>)> solve = [&](int col, bitset<10> rows, bitset<20> d1, bitset<20> d2) {
            if (col == n) {
                res.push_back(board);
                return;
            }
            for (int row = 0; row < n; row++) {
                if (!rows[row] && !d1[row - col + n - 1] && !d2[row + col]) {
                    board.push_back(row + 1);
                    rows[row] = d1[row - col + n - 1] = d2[row + col] = 1;
                    solve(col + 1, rows, d1, d2);
                    rows[row] = d1[row - col + n - 1] = d2[row + col] = 0;
                    board.pop_back();
                }
            }
        };
        solve(0, {}, {}, {});
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends