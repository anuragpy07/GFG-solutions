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

void mergeSortedSequences(vector<int>& primary, vector<int>& left, vector<int>& right) {
    size_t leftPtr = 0, rightPtr = 0;
    size_t leftSize = left.size(), rightSize = right.size();
    primary.clear();
    
    while (leftPtr < leftSize || rightPtr < rightSize) {
        (rightPtr >= rightSize || (leftPtr < leftSize && left[leftPtr] <= right[rightPtr])) ?
            (primary.push_back(left[leftPtr]), ++leftPtr) :
            (primary.push_back(right[rightPtr]), ++rightPtr);
    }
}

void advancedMergeSort(vector<int>& sequence) {
    size_t seqSize = sequence.size();
    (seqSize <= 1) ? void() : [&]() {
        size_t mid = seqSize / 2;
        vector<int> leftHalf(sequence.begin(), sequence.begin() + mid);
        vector<int> rightHalf(sequence.begin() + mid, sequence.end());
        
        advancedMergeSort(leftHalf);
        advancedMergeSort(rightHalf);
        
        mergeSortedSequences(sequence, leftHalf, rightHalf);
    }();
}

class Solution {
public:
    int calculateTotalSum(vector<int>& nums) {
        int total = 0;
        size_t idx = 0;
        while (idx < nums.size()) {
            total += nums[idx++];
        }
        return total;
    }
    
    int minDifference(vector<int>& arr) {
        int totalSum = calculateTotalSum(arr);
        int targetSum = totalSum / 2;
        size_t n = arr.size();
        
        vector<vector<bool>> dpMatrix(n + 1, vector<bool>(targetSum + 1, false));
        size_t row = 0;
        
        while (row <= n) {
            dpMatrix[row][0] = true;
            row++;
        }
        
        row = 1;
        while (row <= n) {
            size_t col = 1;
            while (col <= targetSum) {
                dpMatrix[row][col] = (arr[row - 1] <= col) ?
                    dpMatrix[row - 1][col - arr[row - 1]] || dpMatrix[row - 1][col] :
                    dpMatrix[row - 1][col];
                col++;
            }
            row++;
        }
        
        int minDiff = totalSum;
        int sum = 0;
        while (sum <= targetSum) {
            minDiff = dpMatrix[n][sum] ? 
                min(minDiff, abs(totalSum - 2 * sum)) : 
                minDiff;
            sum++;
        }
        
        return minDiff;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends