//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

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
    void customMerge(vector<int>& arr, int left, int mid, int right) {
        int size1 = mid - left + 1, size2 = right - mid;
        vector<int> L(size1), R(size2);
        REP(i, size1) L[i] = arr[left + i];
        REP(i, size2) R[i] = arr[mid + 1 + i];
        int i = 0, j = 0, k = left;
        while (i < size1 && j < size2) arr[k++] = (L[i] <= R[j] ? L[i++] : R[j++]);
        while (i < size1) arr[k++] = L[i++];
        while (j < size2) arr[k++] = R[j++];
    }

    void customMergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        customMergeSort(arr, left, mid);
        customMergeSort(arr, mid + 1, right);
        customMerge(arr, left, mid, right);
    }

public:
    int maxSubsetXOR(int arr[], int N) {
        vector<int> nums(arr, arr + N);
        customMergeSort(nums, 0, N - 1);
        int index = 0;
        for (int bit = 31; bit >= 0; bit--) {
            int maxInd = index, maxVal = -1;
            for (int i = index; i < N; i++) 
                if (nums[i] & (1 << bit)) 
                    maxVal = nums[i] > maxVal ? nums[i] : maxVal, 
                    maxInd = nums[i] == maxVal ? i : maxInd;
            if (maxVal == -1) continue;
            swap(nums[index], nums[maxInd]);
            maxInd = index++;
            for (int i = 0; i < N; i++) 
                if (i != maxInd && (nums[i] & (1 << bit))) 
                    nums[i] ^= nums[maxInd];
        }
        int result = 0;
        for (int i = 0; i < N; i++) 
            result ^= nums[i];
        return result;
    }
};




//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends