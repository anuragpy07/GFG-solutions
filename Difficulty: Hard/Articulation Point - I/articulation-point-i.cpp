//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

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
    void APUtil(vector<int> adj[], int u, bool visited[],
                int disc[], int low[], int &time, int parent,
                bool isAP[])
    {
        int children = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;
        
        int idx = 0;
        while(idx < adj[u].size())
        {
            int v = adj[u][idx];
            
            if (!visited[v]) {
                children++;
                APUtil(adj, v, visited, disc, low, time, u, isAP);
                
                low[u] = min(low[u], low[v]);
                
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
            
            ++idx;
        }
        
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> ans;
        int disc[V] = {0};
        int low[V] = {0};
        bool visited[V] = {false};
        bool isAP[V] = {false};
        int time = 0, par = -1;
        
        int u = 0;
        while(u < V)
        {
            if (!visited[u])
                APUtil(adj, u, visited, disc, low, time, par, isAP);
            ++u;
        }
        
        u = 0;
        while(u < V)
        {
            if (isAP[u])
                ans.push_back(u);
            ++u;
        }
        
        if (ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends