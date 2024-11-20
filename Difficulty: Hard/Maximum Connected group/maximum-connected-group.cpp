//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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

class Solution {
private:
    vector<int> parent, rank, size;
    int n;
    
    int find(int x) {
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x), rootY = find(y);
        while(rootX != rootY) {
            if(rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            if(rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
            break;
        }
    }
    
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
public:
    int MaxConnection(vector<vector<int>>& grid) {
        n = grid.size();
        parent.resize(n*n);
        rank.resize(n*n, 0);
        size.resize(n*n, 1);
        
        REP(i, n*n) {
            parent[i] = i;
        }
        
        REP(i, n) {
            REP(j, n) {
                if(grid[i][j] == 1) {
                    int curr = i*n + j;
                    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
                    for(auto& dir : dirs) {
                        int ni = i + dir.first, nj = j + dir.second;
                        if(isValid(ni, nj) && grid[ni][nj] == 1) {
                            int next = ni*n + nj;
                            unionSet(curr, next);
                        }
                    }
                }
            }
        }
        
        int maxSize = 0;
        REP(i, n) {
            REP(j, n) {
                if(grid[i][j] == 0) {
                    int curr = i*n + j;
                    set<int> uniqueGroups;
                    int currSize = 1;
                    
                    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
                    for(auto& dir : dirs) {
                        int ni = i + dir.first, nj = j + dir.second;
                        if(isValid(ni, nj) && grid[ni][nj] == 1) {
                            int root = find(ni*n + nj);
                            if(uniqueGroups.find(root) == uniqueGroups.end()) {
                                uniqueGroups.insert(root);
                                currSize += size[root];
                            }
                        }
                    }
                    
                    maxSize = max(maxSize, currSize);
                }
            }
        }
        
        return maxSize ? maxSize : n*n;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends