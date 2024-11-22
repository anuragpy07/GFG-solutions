//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(string& str) {
        int n = str.length();
        int maxLen = 0;
        stack<int> st;
        st.push(-1);
        
        int i = 0;
        while(i < n) {
            if(str[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                
                if(!st.empty()) {
                    maxLen = max(maxLen, i - st.top());
                } else {
                    st.push(i);
                }
            }
            
            i++;
        }
        
        return maxLen;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends