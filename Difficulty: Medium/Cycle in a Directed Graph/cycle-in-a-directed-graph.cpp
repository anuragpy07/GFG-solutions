//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int N = adj.size();
        vector<int> indegree(N, 0);
        
        //step-1: Filling the indegree vector
        for(int u = 0; u<N; u++){
            for(int &v : adj[u]){
                indegree[v]++;
                
            }
        }
        //step-2: Fill que, indegree with 0
        queue<int>que;
        int count = 0;
        for(int i = 0; i<N; i++){
            if(indegree[i] == 0){
                que.push(i);
           }
        }
 
        //step-3: simple BFS
        while(!que.empty()){
            count++;
            int u = que.front();
            que.pop();
            
            
            for(int &v : adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    que.push(v);
                    
                }
            }
        }
        return (count == N) ? false : true;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends