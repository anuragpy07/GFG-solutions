//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int splitArray(int arr[], int N, int K) {
        int low = *max_element(arr, arr + N);
        int high = 0;
        
        REP(i, N) {
            high += arr[i];
        }
        
        int result = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int splits = countSplits(arr, N, mid);
            
            splits <= K ? (result = mid, high = mid - 1) : (low = mid + 1);
        }
        
        return result;
    }
    
private:
    int countSplits(int arr[], int N, int maxSum) {
        int currSum = 0;
        int splits = 1;
        
        REP(i, N) {
            currSum += arr[i];
            
            currSum > maxSum ? (splits++, currSum = arr[i]) : 0;
        }
        
        return splits;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends