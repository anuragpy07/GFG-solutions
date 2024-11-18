//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

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
    int subsequenceCount(string& txt, string& pat) {
        const int MOD = 1e9 + 7;
        int txtLen = txt.length(), patLen = pat.length();
        vector<vector<int>> dp(patLen + 1, vector<int>(txtLen + 1, 0));
        
        int idx = 0;
        while(idx <= txtLen) {
            dp[0][idx] = 1;
            idx++;
        }
        
        int patIdx = 1;
        while(patIdx <= patLen) {
            int txtIdx = 1;
            while(txtIdx <= txtLen) {
                dp[patIdx][txtIdx] = dp[patIdx][txtIdx - 1] + 
                    ((txt[txtIdx - 1] == pat[patIdx - 1]) ? 
                        dp[patIdx - 1][txtIdx - 1] : 0);
                dp[patIdx][txtIdx] %= MOD;
                txtIdx++;
            }
            patIdx++;
        }
        
        return dp[patLen][txtLen];
    }
};


//{ Driver Code Starts.

//  Driver code to check above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends