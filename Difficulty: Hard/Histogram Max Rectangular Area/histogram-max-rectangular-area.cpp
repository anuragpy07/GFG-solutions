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
    long long getMaxArea(vector<long long> &hist) {
        long long n = hist.size();
        stack<long long> s;
        long long max_area = 0;
        long long tp;
        long long area_with_top;
        long long i = 0;
        
        while (i < n) {
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);
            else {
                tp = s.top();
                s.pop();
                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
                max_area = max_area < area_with_top ? area_with_top : max_area;
            }
        }
        
        while (s.empty() == false) {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max_area < area_with_top ? area_with_top : max_area;
        }
        
        return max_area;
    }
};






//{ Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends