//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = arr[0];
        rightMax[n - 1] = arr[n - 1];

      
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

     
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

       
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(leftMax[i], rightMax[i]) - arr[i];
        }

        return waterTrapped;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends