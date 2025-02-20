//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    // Max heap to store the lower half of numbers
    priority_queue<int> maxHeap;
    // Min heap to store the upper half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> medians;
        
        for(int num : arr) {
            // Step 1: Add new element
            if(maxHeap.empty() || num < maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            
            // Step 2: Balance heaps
            // Max heap can have at most one more element than min heap
            if(maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if(minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // Step 3: Calculate median
            if(maxHeap.size() > minHeap.size()) {
                // Odd number of elements
                medians.push_back(maxHeap.top());
            } else {
                // Even number of elements
                double median = (maxHeap.top() + minHeap.top()) / 2.0;
                medians.push_back(median);
            }
        }
        
        return medians;
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
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends