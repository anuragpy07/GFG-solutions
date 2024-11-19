//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <bits/stdc++.h>
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

template<class T>
void chmax(T & a, const T & b) { a = max(a, b); }
template<class T>
void chmin(T & a, const T & b) { a = min(a, b); }

void mergeArrays(vector<vector<int>>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    
    vector<vector<int>> leftArr(len1, vector<int>(arr[0].size()));
    vector<vector<int>> rightArr(len2, vector<int>(arr[0].size()));
    
    int idx = 0;
    while(idx < len1) {
        leftArr[idx] = arr[left + idx];
        idx++;
    }
    
    idx = 0;
    while(idx < len2) {
        rightArr[idx] = arr[mid + 1 + idx];
        idx++;
    }
    
    int i = 0, j = 0, k = left;
    
    while(i < len1 && j < len2) {
        arr[k] = (leftArr[i][0] <= rightArr[j][0]) ? leftArr[i++] : rightArr[j++];
        k++;
    }
    
    while(i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while(j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSortImpl(vector<vector<int>>& arr, int left, int right) {
    right > left ? (void)(mergeSortImpl(arr, left, (left + right) / 2), 
                         mergeSortImpl(arr, (left + right) / 2 + 1, right),
                         mergeArrays(arr, left, (left + right) / 2, right)) : void();
}

void mergeSort(vector<vector<int>>& arr) {
    mergeSortImpl(arr, 0, arr.size() - 1);
}

class Solution {
public:
    int matrixMultiplication(vector<int>& dimensions) {
        int matrixCount = dimensions.size() - 1;
        vector<vector<int>> dpMemo(matrixCount, vector<int>(matrixCount, 0));
        
        int chainLength = 2;
        while(chainLength <= matrixCount) {
            int startIdx = 0;
            while(startIdx < matrixCount - chainLength + 1) {
                int endIdx = startIdx + chainLength - 1;
                dpMemo[startIdx][endIdx] = INT_MAX;
                
                int splitIdx = startIdx;
                while(splitIdx < endIdx) {
                    int currentCost = dpMemo[startIdx][splitIdx] + 
                                    dpMemo[splitIdx + 1][endIdx] + 
                                    dimensions[startIdx] * dimensions[splitIdx + 1] * dimensions[endIdx + 1];
                    
                    dpMemo[startIdx][endIdx] = 
                        currentCost < dpMemo[startIdx][endIdx] ? currentCost : dpMemo[startIdx][endIdx];
                    
                    splitIdx++;
                }
                startIdx++;
            }
            chainLength++;
        }
        
        return matrixCount == 1 ? 0 : dpMemo[0][matrixCount - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends