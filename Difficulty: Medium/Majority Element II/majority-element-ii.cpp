//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size(), threshold = n / 3;
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        
        for(int num : arr) {
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
            else if(count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(int num : arr) {
            if(num == candidate1) count1++;
            if(num == candidate2) count2++;
        }
        
        vector<int> result;
        if(count1 > threshold) result.push_back(candidate1);
        if(count2 > threshold && candidate2 != candidate1) result.push_back(candidate2);
        
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends