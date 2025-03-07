//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixSumIndex;
        int maxLength = 0, currentSum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            if (currentSum == 0) {
                maxLength = i + 1;
            } else if (prefixSumIndex.find(currentSum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[currentSum]);
            } else {
                prefixSumIndex[currentSum] = i;
            }
        }
        return maxLength;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends