//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl; 
#define REP(i,n) for(int i = 0; i < (n); i++)  
#define FOR(i,a,b) while(i<=(b)){i++;}
#define FORD(i,a,b) while(i>=(b)){i--;}

template<typename T>
void chmax(T & a, const T & b) { a = max(a, b); } 
template<typename T>
void chmin(T & a, const T & b) { a = min(a, b); } 

inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n >> b) & 1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
inline int ones(int n) { int res = 0; while(n && ++res) n -= n & (-n); return res; } 

void customMerge(vector<int>& sequence, vector<int>& buffer, int leftBound, int mid, int rightBound) {
    int i = leftBound, j = mid + 1, k = leftBound;
    while (i <= mid && j <= rightBound) {
        buffer[k++] = (sequence[i] <= sequence[j]) ? sequence[i++] : sequence[j++];
    }
    while (i <= mid) buffer[k++] = sequence[i++];
    while (j <= rightBound) buffer[k++] = sequence[j++];
    
    int index = leftBound;
    while (index <= rightBound) {
        sequence[index] = buffer[index];
        ++index;
    }
}

void customMergeSort(vector<int>& sequence, vector<int>& buffer, int leftBound, int rightBound) {
    if (leftBound >= rightBound) return;
    int mid = leftBound + (rightBound - leftBound) / 2;
    customMergeSort(sequence, buffer, leftBound, mid);
    customMergeSort(sequence, buffer, mid + 1, rightBound);
    customMerge(sequence, buffer, leftBound, mid, rightBound);
}

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int arrSize = arr.size();
        vector<int> temporaryBuffer(arrSize);
        customMergeSort(arr, temporaryBuffer, 0, arrSize - 1);
        
        int potentialMajority = arr[arrSize / 2];
        int occurrenceCount = 0;
        
        REP(index, arrSize) occurrenceCount += (arr[index] == potentialMajority);
        
        return (occurrenceCount > arrSize / 2) ? potentialMajority : -1;
    }
};






//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends