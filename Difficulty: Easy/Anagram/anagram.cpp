//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // First, check if lengths are different
        if (s1.length() != s2.length()) {
            return false;
        }
        
        // Create frequency array to count characters
        vector<int> freq(26, 0);
        
        // Count frequencies of characters in s1
        for (char c : s1) {
            freq[c - 'a']++;
        }
        
        // Decrease frequencies for characters in s2
        for (char c : s2) {
            freq[c - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends