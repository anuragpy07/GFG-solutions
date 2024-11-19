//{ Driver Code Starts
// Initial Template for C++

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

void fusionArrays(vector<int>& arr, int start, int mid, int end) {
    int omega = mid - start + 1;
    int theta = end - mid;
    
    vector<int> leftSection(omega), rightSection(theta);
    
    int idx = 0;
    while(idx < omega) {
        leftSection[idx] = arr[start + idx];
        idx++;
    }
    
    idx = 0;
    while(idx < theta) {
        rightSection[idx] = arr[mid + 1 + idx];
        idx++;
    }
    
    int kappa = 0, lambda = 0, mu = start;
    
    while(kappa < omega && lambda < theta) {
        arr[mu++] = (leftSection[kappa] <= rightSection[lambda]) ? 
                    leftSection[kappa++] : rightSection[lambda++];
    }
    
    while(kappa < omega) {
        arr[mu++] = leftSection[kappa++];
    }
    
    while(lambda < theta) {
        arr[mu++] = rightSection[lambda++];
    }
}

void fusionSortImpl(vector<int>& arr, int start, int end) {
    end > start ? (
        fusionSortImpl(arr, start, (start + end) / 2),
        fusionSortImpl(arr, (start + end) / 2 + 1, end),
        fusionArrays(arr, start, (start + end) / 2, end)
    ) : void();
}

void fusionSort(vector<int>& arr) {
    fusionSortImpl(arr, 0, arr.size() - 1);
}

class Solution {
public:
    double medianOfSortedArrays(vector<int>& alpha, vector<int>& beta) {
        int totalLen = alpha.size() + beta.size();
        vector<int> merged(totalLen);
        
        int idxAlpha = 0, idxBeta = 0, idxMerged = 0;
        
        while(idxAlpha < alpha.size() && idxBeta < beta.size()) {
            merged[idxMerged++] = (alpha[idxAlpha] <= beta[idxBeta]) ? 
                                 alpha[idxAlpha++] : beta[idxBeta++];
        }
        
        while(idxAlpha < alpha.size()) {
            merged[idxMerged++] = alpha[idxAlpha++];
        }
        
        while(idxBeta < beta.size()) {
            merged[idxMerged++] = beta[idxBeta++];
        }
        
        return (totalLen % 2) ? 
               merged[totalLen / 2] : 
               (merged[(totalLen - 1) / 2] + merged[totalLen / 2]) / 2.0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOfSortedArrays(array1, array2);
        if (ans == (int)ans) {
            cout << (int)ans << endl;
        } else {
            cout << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends