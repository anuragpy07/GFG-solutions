//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string decodedString(string &s) {
        stack<int> numStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '[') {
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            } else if (c == ']') {
                string temp = curr;
                curr = strStack.top();
                strStack.pop();
                int count = numStack.top();
                numStack.pop();
                while (count--) curr += temp;
            } else curr += c;
        }
        return curr;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends