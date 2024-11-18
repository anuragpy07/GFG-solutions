//{ Driver Code Starts
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

void customMerge(vector<int>& alpha, int orbit, int nebula, int pulsar) {
    vector<int> quasar(pulsar - orbit + 1);
    int stellar = orbit, lunar = nebula + 1;
    int cosmic = 0;
    
    while ((stellar <= nebula) && (lunar <= pulsar)) {
        quasar[cosmic++] = (alpha[stellar] <= alpha[lunar]) ? alpha[stellar++] : alpha[lunar++];
    }
    
    while (stellar <= nebula) {
        quasar[cosmic++] = alpha[stellar++];
    }
    
    while (lunar <= pulsar) {
        quasar[cosmic++] = alpha[lunar++];
    }
    
    cosmic = 0;
    while (orbit <= pulsar) {
        alpha[orbit++] = quasar[cosmic++];
    }
}

void customMergeSort(vector<int>& alpha, int orbit, int pulsar) {
    if (orbit < pulsar) {
        int nebula = orbit + (pulsar - orbit) / 2;
        customMergeSort(alpha, orbit, nebula);
        customMergeSort(alpha, nebula + 1, pulsar);
        customMerge(alpha, orbit, nebula, pulsar);
    }
}

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int nova = arr.size();
        int solar = nova - 2;
        
        while (solar >= 0) {
            (arr[solar] >= arr[solar + 1]) ? solar-- : solar;
            if (arr[solar] < arr[solar + 1]) break;
        }
        
        int comet = nova - 1;
        
        (solar >= 0) ? [&]() {
            while (comet > solar) {
                (arr[comet] <= arr[solar]) ? comet-- : comet;
                if (arr[comet] > arr[solar]) break;
            }
            swap(arr[solar], arr[comet]);
        }() : void();
        
        int orbit = solar + 1;
        int pulsar = nova - 1;
        customMergeSort(arr, orbit, pulsar);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends