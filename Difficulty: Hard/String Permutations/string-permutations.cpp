//{ Driver Code Starts
#include<bits/stdc++.h>
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
    void merge(vector<string>& strings, int startIdx, int endIdx) {
        (startIdx >= endIdx) ? void() : [this, &strings, startIdx, endIdx] {
            int midIdx = startIdx + (endIdx - startIdx) / 2;
            merge(strings, startIdx, midIdx);
            merge(strings, midIdx + 1, endIdx);

            vector<string> temp(endIdx - startIdx + 1);
            int leftIdx = startIdx, rightIdx = midIdx + 1, tempIdx = 0;
            while (leftIdx <= midIdx && rightIdx <= endIdx) {
                temp[tempIdx++] = (strings[leftIdx] < strings[rightIdx]) ? strings[leftIdx++] : strings[rightIdx++];
            }

            while (leftIdx <= midIdx) {
                temp[tempIdx++] = strings[leftIdx++];
            }
            while (rightIdx <= endIdx) {
                temp[tempIdx++] = strings[rightIdx++];
            }

            leftIdx = startIdx; 
            tempIdx = 0;
            while (leftIdx <= endIdx) {
                strings[leftIdx] = temp[tempIdx++];
                leftIdx++;
            }
        }();
    }

    void generatePermutations(string& S, vector<string>& result, int startIdx) {
        (startIdx == S.length() - 1) ? result.push_back(S) : permuteRest(S, result, startIdx);
    }
    
    void permuteRest(string& S, vector<string>& result, int startIdx) {
        int currentIdx = startIdx;
        while (currentIdx < S.length()) {
            (currentIdx != startIdx) ? swap(S[startIdx], S[currentIdx]) : void();
            generatePermutations(S, result, startIdx + 1);
            (currentIdx != startIdx) ? swap(S[startIdx], S[currentIdx]) : void();
            currentIdx++;
        }
    }
    
public:
    vector<string> permutation(string S) {
        vector<string> result;
        generatePermutations(S, result, 0);

        merge(result, 0, result.size() - 1);

        return result;
    }
};



//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends