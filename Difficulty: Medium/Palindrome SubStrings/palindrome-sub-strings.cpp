//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int n = s.size(), count = 0;
        
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= 2) count++;
                l--, r++;
            }
        };
        
        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd-length palindromes
            expand(i, i + 1); // Even-length palindromes
        }
        
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends