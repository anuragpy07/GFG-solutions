//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
#define REP(i,n) while(int i=0, i<(n), i++) 
#define FOR(i,a,b) while(int i=(a), i<=(b), i++) 
#define FORD(i,a,b) while(int i=(a), i>=(b), i--) 
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
    void mergeArrays(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> leftArr(n1), rightArr(n2);
        int i = 0;
        while (i < n1) leftArr[i] = arr[l + i], i++;
        i = 0;
        while (i < n2) rightArr[i] = arr[m + 1 + i], i++;
        int j = 0, k = l;
        i = 0;
        while (i < n1 && j < n2) arr[k++] = leftArr[i] <= rightArr[j] ? leftArr[i++] : rightArr[j++];
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        l >= r ? void() : [&]() {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            mergeArrays(arr, l, m, r);
        }();
    }

  public:
    int maxSubarraySum(vector<int>& arr) {
        int max_sum = INT_MIN, current_sum = 0;
        int i = 0;
        while (i < arr.size()) {
            current_sum = current_sum + arr[i] > arr[i] ? current_sum + arr[i] : arr[i];
            max_sum = max_sum > current_sum ? max_sum : current_sum;
            i++;
        }
        return max_sum;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends