//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
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
private:
    int getCountLessEqual(vector<int>& row, int mid) {
        int low = 0, high = row.size() - 1;
        while (low <= high) {
            int m = low + (high - low) / 2;
            (row[m] <= mid ? low = m + 1 : high = m - 1);
        }
        return low;
    }
    
    int findTotal(vector<vector<int>>& matrix, int mid, int R, int C) {
        int count = 0;
        int j = 0;
        while (j < R) {
            count += getCountLessEqual(matrix[j], mid);
            j++;
        }
        return count;
    }
    
public:
    int median(vector<vector<int>>& matrix, int R, int C) {
        int low = 1, high = 2000;
        int desired = (R * C + 1) / 2;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = findTotal(matrix, mid, R, C);
            (count < desired ? low = mid + 1 : high = mid);
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends