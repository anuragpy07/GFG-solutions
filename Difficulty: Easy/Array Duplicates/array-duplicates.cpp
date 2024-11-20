//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> result;
        vector<int> frequency(1e6 + 1, 0);

        int i = 0;
        while (i < arr.size()) {
            frequency[arr[i]]++;
            ++i;
        }

        i = 0;
        while (i < frequency.size()) {
            if (frequency[i] > 1) result.push_back(i);
            ++i;
        }

        return result;
    }
};







//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.findDuplicates(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no duplicates are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends