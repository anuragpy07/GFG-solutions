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
    string smallestWindow(string &nexS1, string &nexS2) {
        vector<int> nexFreqS2(26, 0);
        vector<int> nexCurrWindow(26, 0);
        int nexRequired = 0;
        int nexStart = 0, nexMinStart = 0;
        int nexMinLen = nexS1.length() + 1;
        
        int nexIdx = 0;
        while (nexIdx < nexS2.length()) {
            nexFreqS2[nexS2[nexIdx] - 'a'] == 0 ? nexRequired++ : nexRequired;
            nexFreqS2[nexS2[nexIdx] - 'a']++;
            nexIdx++;
        }
        
        int nexLeft = 0, nexRight = 0;
        int nexCount = 0;
        int nexMatched = 0;
        
        while (nexRight < nexS1.length()) {
            nexCurrWindow[nexS1[nexRight] - 'a']++;
            
            (nexCurrWindow[nexS1[nexRight] - 'a'] == nexFreqS2[nexS1[nexRight] - 'a']) ?
                (nexFreqS2[nexS1[nexRight] - 'a'] != 0 ? nexMatched++ : nexMatched) : nexMatched;
            
            nexMatched == nexRequired ? nexCount = 1 : nexCount;
            
            while (nexCount > 0 && nexLeft <= nexRight) {
                int nexLen = nexRight - nexLeft + 1;
                
                (nexLen < nexMinLen) ? (nexMinLen = nexLen, nexMinStart = nexLeft) : nexMinLen;
                
                nexCurrWindow[nexS1[nexLeft] - 'a']--;
                
                (nexCurrWindow[nexS1[nexLeft] - 'a'] < nexFreqS2[nexS1[nexLeft] - 'a']) ?
                    (nexFreqS2[nexS1[nexLeft] - 'a'] != 0 ? nexMatched-- : nexMatched) : nexMatched;
                
                nexMatched < nexRequired ? nexCount = 0 : nexCount;
                
                nexLeft++;
            }
            
            nexRight++;
        }
        
        return nexMinLen > nexS1.length() ? "-1" : nexS1.substr(nexMinStart, nexMinLen);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        cout << obj.smallestWindow(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends