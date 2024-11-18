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
    void mergeSortedArrays(vector<int>& alpha, int leftStart, int mid, int rightEnd) {
        vector<int> tempArray(rightEnd - leftStart + 1);
        int leftPtr = leftStart;
        int rightPtr = mid + 1;
        int idx = 0;
        
        while ((leftPtr <= mid) && (rightPtr <= rightEnd)) {
            tempArray[idx++] = (alpha[leftPtr] <= alpha[rightPtr]) ? alpha[leftPtr++] : alpha[rightPtr++];
        }
        
        while (leftPtr <= mid) {
            tempArray[idx++] = alpha[leftPtr++];
        }
        
        while (rightPtr <= rightEnd) {
            tempArray[idx++] = alpha[rightPtr++];
        }
        
        idx = 0;
        while (leftStart <= rightEnd) {
            alpha[leftStart++] = tempArray[idx++];
        }
    }
    
    void customMergeSort(vector<int>& alpha, int startIdx, int endIdx) {
        (startIdx >= endIdx) ? void() : [&]() {
            int midIdx = startIdx + (endIdx - startIdx) / 2;
            customMergeSort(alpha, startIdx, midIdx);
            customMergeSort(alpha, midIdx + 1, endIdx);
            mergeSortedArrays(alpha, startIdx, midIdx, endIdx);
        }();
    }
    
    void depthFirstTraverse(vector<vector<int>>& adjMatrix, vector<bool>& visitMark, int vertex) {
        visitMark[vertex] = true;
        int neighborIdx = 0;
        while (neighborIdx < 26) {
            (adjMatrix[vertex][neighborIdx] && !visitMark[neighborIdx]) ? 
                depthFirstTraverse(adjMatrix, visitMark, neighborIdx) : void();
            neighborIdx++;
        }
    }

public:
    int isCircle(vector<string>& arr) {
        vector<vector<int>> adjMatrix(26, vector<int>(26, 0));
        vector<int> inDegree(26, 0), outDegree(26, 0);
        vector<bool> presentChars(26, false);
        
        int strIdx = 0;
        while (strIdx < arr.size()) {
            int firstChar = arr[strIdx][0] - 'a';
            int lastChar = arr[strIdx][arr[strIdx].length() - 1] - 'a';
            
            adjMatrix[firstChar][lastChar] += 1;
            inDegree[lastChar] += 1;
            outDegree[firstChar] += 1;
            presentChars[firstChar] = presentChars[lastChar] = true;
            
            strIdx++;
        }
        
        int charIdx = 0;
        while (charIdx < 26) {
            int result = (presentChars[charIdx] && 
                         (inDegree[charIdx] != outDegree[charIdx])) ? 0 : 1;
            if (result == 0) return 0;
            charIdx++;
        }
        
        vector<bool> visitMark(26, false);
        int startVertex = 0;
        while (!presentChars[startVertex] && startVertex < 26) {
            startVertex++;
        }
        
        depthFirstTraverse(adjMatrix, visitMark, startVertex);
        
        charIdx = 0;
        while (charIdx < 26) {
            int result = (presentChars[charIdx] && !visitMark[charIdx]) ? 0 : 1;
            if (result == 0) return 0;
            charIdx++;
        }
        
        return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends