//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    struct BoxDim {
        int len;
        int wid;
        int hgt;
    };
    
    void mergeSortedArrays(vector<BoxDim>& boxes, int left, int middle, int right) {
        vector<BoxDim> tempLeft, tempRight;
        
        int ptr1 = 0;
        while (ptr1 < middle - left + 1) {
            tempLeft.push_back(boxes[left + ptr1]);
            ptr1++;
        }
        
        int ptr2 = 0;
        while (ptr2 < right - middle) {
            tempRight.push_back(boxes[middle + 1 + ptr2]);
            ptr2++;
        }
        
        int idx1 = 0, idx2 = 0, mergeIdx = left;
        
        while (idx1 < tempLeft.size() && idx2 < tempRight.size()) {
            bool condition = (tempLeft[idx1].len * tempLeft[idx1].wid) >= 
                           (tempRight[idx2].len * tempRight[idx2].wid);
            boxes[mergeIdx] = condition ? tempLeft[idx1++] : tempRight[idx2++];
            mergeIdx++;
        }
        
        while (idx1 < tempLeft.size()) {
            boxes[mergeIdx] = tempLeft[idx1];
            idx1++;
            mergeIdx++;
        }
        
        while (idx2 < tempRight.size()) {
            boxes[mergeIdx] = tempRight[idx2];
            idx2++;
            mergeIdx++;
        }
    }
    
    void customMergeSort(vector<BoxDim>& boxes, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            customMergeSort(boxes, start, mid);
            customMergeSort(boxes, mid + 1, end);
            mergeSortedArrays(boxes, start, mid, end);
        }
    }
    
    bool canPlace(BoxDim& lower, BoxDim& upper) {
        return (lower.len > upper.len && lower.wid > upper.wid);
    }
    
    public:
    int maxHeight(int height[], int width[], int length[], int n) {
        vector<BoxDim> boxes;
        
        int idx = 0;
        while (idx < n) {
            BoxDim box1 = {max(width[idx], length[idx]), min(width[idx], length[idx]), height[idx]};
            BoxDim box2 = {max(height[idx], length[idx]), min(height[idx], length[idx]), width[idx]};
            BoxDim box3 = {max(height[idx], width[idx]), min(height[idx], width[idx]), length[idx]};
            
            boxes.push_back(box1);
            boxes.push_back(box2);
            boxes.push_back(box3);
            idx++;
        }
        
        customMergeSort(boxes, 0, boxes.size() - 1);
        
        vector<int> maxHeights(boxes.size());
        int ptr = 0;
        while (ptr < boxes.size()) {
            maxHeights[ptr] = boxes[ptr].hgt;
            ptr++;
        }
        
        int outerPtr = 1;
        while (outerPtr < boxes.size()) {
            int innerPtr = 0;
            while (innerPtr < outerPtr) {
                int newHeight = canPlace(boxes[innerPtr], boxes[outerPtr]) ? 
                              maxHeights[innerPtr] + boxes[outerPtr].hgt : 
                              maxHeights[outerPtr];
                maxHeights[outerPtr] = max(maxHeights[outerPtr], newHeight);
                innerPtr++;
            }
            outerPtr++;
        }
        
        return *max_element(maxHeights.begin(), maxHeights.end());
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    
cout << "~" << "\n";
}
	
	return 0;
}
	
// } Driver Code Ends