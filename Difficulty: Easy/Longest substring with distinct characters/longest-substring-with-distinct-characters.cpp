//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int longestUniqueSubstr(string &s) {
      
        if (s.empty()) return 0;
        
        vector<int> lastSeen(256, -1);  
        int maxLength = 0;
        int start = 0;                  
        
      
        for (int end = 0; end < s.length(); end++) {
          
            if (lastSeen[s[end]] >= start) {
        
                start = lastSeen[s[end]] + 1;
            }
            
            
            lastSeen[s[end]] = end;
            
          
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends