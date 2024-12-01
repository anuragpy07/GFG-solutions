//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    char nonRepeatingChar(string &s) {
        // Create a frequency array for all possible characters
        vector<int> freq(256, 0);
        
        // Count frequency of each character
        for(char c : s) {
            freq[c]++;
        }
        
        // Find the first character with frequency 1
        for(char c : s) {
            if(freq[c] == 1) {
                return c;
            }
        }
        
        // If no non-repeating character found, return '$'
        return '$';
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends