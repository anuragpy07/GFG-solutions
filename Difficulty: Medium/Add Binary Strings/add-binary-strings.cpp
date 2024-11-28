//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2)
            s2.insert(0, len1 - len2, '0');
        else if (len2 > len1)
            s1.insert(0, len2 - len1, '0');

        int carry = 0;
        string sumResult;

        for (int i = s1.length() - 1; i >= 0; --i) {
            int bit1 = s1[i] - '0', bit2 = s2[i] - '0';
            int total = bit1 + bit2 + carry;
            carry = total / 2;
            sumResult += (total % 2) + '0';
        }

        if (carry)
            sumResult += '1';

        reverse(sumResult.begin(), sumResult.end());
        size_t pos = sumResult.find_first_not_of('0');

        return pos != string::npos ? sumResult.substr(pos) : "0";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends