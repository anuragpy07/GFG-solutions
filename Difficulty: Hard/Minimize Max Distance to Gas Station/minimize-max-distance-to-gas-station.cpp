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
    int ok(double x, vector<int> &v) {
        int ret = 0, i = 0;
        while (i < v.size() - 1) {
            ret += ceil((v[i + 1] - v[i]) / x) - 1;
            i++;
        }
        return ret;
    }

    double findSmallestMaxDist(vector<int> &stations, int K) {
        double low = 0;
        int n = stations.size();
        double high = stations[n - 1] - stations[0];
        while ((high - low) >= 1e-6) {
            double mid = (low + high) / 2.0;
            int x = ok(mid, stations);
            low = x > K ? mid : low;
            high = x > K ? high : mid;
        }
        return high;
    }

    void merge_sort(vector<int>& array) {
        if (array.size() < 2) return;
        vector<int> left(array.begin(), array.begin() + array.size() / 2);
        vector<int> right(array.begin() + array.size() / 2, array.end());
        merge_sort(left);
        merge_sort(right);
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) 
            array[k++] = left[i] <= right[j] ? left[i++] : right[j++];
        while (i < left.size()) array[k++] = left[i++];
        while (j < right.size()) array[k++] = right[j++];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends