//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // Stack to store indices
        
        // First element's span is always 1
        span[0] = 1;
        st.push(0);
        
        // Calculate span for rest of the elements
        for(int i = 1; i < n; i++) {
            // Pop elements from stack while stack is not empty
            // and top of stack has smaller or equal value
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            // If stack is empty, all previous elements are smaller
            // Else the span is difference between current index and stack top
            span[i] = st.empty() ? (i + 1) : (i - st.top());
            
            // Push current index to stack
            st.push(i);
        }
        
        return span;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends