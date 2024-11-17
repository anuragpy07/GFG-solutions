//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

class Solution {
public:
    bool isSafe(int x, int y, int n, vector<vector<int>>& mat) {
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1);
    }

    void findPaths(int x, int y, int n, vector<vector<int>>& mat, string& path, vector<string>& paths) {
        mat[x][y] = 0;
        if (x == n - 1 && y == n - 1) {
            paths.push_back(path);
            mat[x][y] = 1;
            return;
        }

        string directions = "DLRU";
        int moves[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        int i = 0;
        while (i < 4) {
            int newX = x + moves[i][0], newY = y + moves[i][1];
            if (isSafe(newX, newY, n, mat)) {
                path.push_back(directions[i]);
                findPaths(newX, newY, n, mat, path, paths);
                path.pop_back();
            }
            i++;
        }
        mat[x][y] = 1;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> paths;
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) return {"-1"};

        string path;
        findPaths(0, 0, n, mat, path, paths);
        sort(paths.begin(), paths.end());
        return paths.empty() ? vector<string>{"-1"} : paths;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends