//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
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
    vector<int> maximumToys(int N, vector<int> &A, int Q, vector<vector<int>> &Queries) {
        vector<int> result;
        vector<pair<int,int>> indexedToys(N);
        
        REP(i, N) {
            indexedToys[i] = {A[i], i+1};
        }
        
        sort(indexedToys.begin(), indexedToys.end());
        
        REP(queryIdx, Q) {
            int budget = Queries[queryIdx][0];
            int K = Queries[queryIdx][1];
            
            vector<bool> isBroken(N+1, false);
            
            int brokenCount = 2;
            while(K > 0) {
                isBroken[Queries[queryIdx][brokenCount]] = true;
                K--;
                brokenCount++;
            }
            
            int toyCount = 0;
            ll totalCost = 0;
            
            REP(i, N) {
                int toyIndex = indexedToys[i].second;
                if(!isBroken[toyIndex]) {
                    totalCost += indexedToys[i].first;
                    
                    if(totalCost <= budget) {
                        toyCount++;
                    } else {
                        break;
                    }
                }
            }
            
            result.push_back(toyCount);
        }
        
        return result;
    }
};




//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 
cout << "~" << "\n";
}
}
// } Driver Code Ends