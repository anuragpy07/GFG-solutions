//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.size(), start = 0, maxLen = 1;
        
        auto expand = [&](int l, int r) -> pair<int, int> {
            while (l >= 0 && r < n && s[l] == s[r]) l--, r++;
            return {l + 1, r - l - 1};
        };
        
        for (int i = 0; i < n; i++) {
            pair<int, int> p1 = expand(i, i);
            pair<int, int> p2 = expand(i, i + 1);
            
            if (p1.second > maxLen) maxLen = p1.second, start = p1.first;
            if (p2.second > maxLen) maxLen = p2.second, start = p2.first;
        }
        
        return s.substr(start, maxLen);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends