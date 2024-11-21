//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        // Create adjacency list and in-degree array
        vector<vector<int>> graph(K);
        vector<int> inDegree(K, 0);
        
        // Build graph by comparing adjacent words
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                // If characters differ, create an edge
                if (word1[j] != word2[j]) {
                    graph[word1[j] - 'a'].push_back(word2[j] - 'a');
                    inDegree[word2[j] - 'a']++;
                    break;
                }
                
                // Check for invalid dictionary order
                if (j == min(word1.length(), word2.length()) - 1 && 
                    word1.length() > word2.length()) {
                    return "";
                }
            }
        }
        
        // Perform topological sorting using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        string result = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result += (char)(curr + 'a');
            
            for (int neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if a valid order exists
        return result.length() == K ? result : "";
    }
};




//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends