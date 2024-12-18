//{ Driver Code Starts
// Initial function template for C++

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
private:
    bool canAllocateBooks(vector<int>& arr, int k, int maxPages) {
        int studentCount = 1, pagesAllocated = 0, currentStudent = 0;
        
        while (currentStudent < arr.size()) {
            if (pagesAllocated + arr[currentStudent] <= maxPages) {
                pagesAllocated += arr[currentStudent];
                currentStudent++;
            } else {
                studentCount++;
                pagesAllocated = 0;
                
                if (studentCount > k) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        
        return (k > n) ? -1 : [&]() {
            int totalPages = 0, maxPage = 0;
            
            while (maxPage < arr.size()) {
                totalPages += arr[maxPage];
                maxPage++;
            }
            
            int low = *max_element(arr.begin(), arr.end());
            int high = totalPages;
            int result = -1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                (canAllocateBooks(arr, k, mid)) ? 
                    (result = mid, high = mid - 1) : 
                    (low = mid + 1);
            }
            
            return result;
        }();
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends