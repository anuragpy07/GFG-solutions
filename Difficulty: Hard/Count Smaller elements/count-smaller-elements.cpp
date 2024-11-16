//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
private:
    struct Item {
        int val, idx;
        Item(int v = 0, int i = 0) : val(v), idx(i) {}
    };
    
    void mergeSort(vector<Item>& arr, vector<int>& count, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }
    
    void merge(vector<Item>& arr, vector<int>& count, int left, int mid, int right) {
        vector<Item> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid || j <= right) {
            (j > right || (i <= mid && arr[i].val <= arr[j].val)) ? 
                (count[arr[i].idx] += (j - mid - 1), temp[k++] = arr[i++]) :
                (temp[k++] = arr[j++]);
        }
        
        k = 0;
        i = left;
        while (i <= right) {
            arr[i++] = temp[k++];
        }
    }
    
public:
    vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<Item> items(n);
        vector<int> count(n, 0);
        
        int i = 0;
        while (i < n) {
            items[i] = Item(arr[i], i);
            i++;
        }
        
        mergeSort(items, count, 0, n-1);
        return count;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends