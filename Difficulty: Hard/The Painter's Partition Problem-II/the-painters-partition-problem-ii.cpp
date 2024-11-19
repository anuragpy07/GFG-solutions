//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    bool isPossible(vector<int>& arr, int k, long long maxTime) {
        long long currentTime = 0;
        int painters = 1;
        
        for (int i = 0; i < arr.size(); ) {
            long long tempTime = 0;
            
            while (i < arr.size() && tempTime + arr[i] <= maxTime) {
                tempTime += arr[i];
                i++;
            }
            
            painters = (i < arr.size()) ? painters + 1 : painters;
            
            if (painters > k) {
                return false;
            }
        }
        
        return true;
    }
    
    long long minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        
        for (int num : arr) {
            high += num;
        }
        
        long long result = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = min(result, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends