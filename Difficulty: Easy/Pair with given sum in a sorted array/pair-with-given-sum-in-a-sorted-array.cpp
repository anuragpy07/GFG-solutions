//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int result = 0;
        int length = arr.size();
        unordered_map<int, int> frequency;
        
        for(int index = 0; index < length; index++) {
            int complement = target - arr[index];
            if(frequency.find(complement) != frequency.end()) {
                result += frequency[complement];
            }
            frequency[arr[index]]++;
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends