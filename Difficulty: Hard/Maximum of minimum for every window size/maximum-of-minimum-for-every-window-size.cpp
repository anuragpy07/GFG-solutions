//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Finding previous smaller elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Finding next smaller elements
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        vector<int> res(n, 0);
        vector<int> ans(n + 1, 0);

        // Filling maxOfMins array
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        // Filling missing values in ans
        for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);

        for (int i = 0; i < n; i++) res[i] = ans[i + 1];

        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends