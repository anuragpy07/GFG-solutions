//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

/* Link list Node */

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        // Step 1: Check if we have at least k nodes
        Node* curr = head;
        int count = 0;
        Node* check = head;
        
        // Count k nodes ahead to see if we have enough nodes
        while (check && count < k) {
            check = check->next;
            count++;
        }
        
        // If we have k nodes, reverse them
        if (count == k) {
            Node* prev = NULL;
            Node* next = NULL;
            curr = head;
            count = 0;
            
            // Reverse k nodes
            while (curr && count < k) {
                next = curr->next;  // Store next
                curr->next = prev;  // Reverse link
                prev = curr;        // Move prev forward
                curr = next;        // Move curr forward
                count++;
            }
            
            // After reversal, head points to last node of reversed group
            // Connect with rest of the list
            if (next) {
                head->next = reverseKGroup(next, k);
            }
            
            // prev is the new head of reversed group
            return prev;
        }
        
        // If less than k nodes, reverse remaining nodes
        else {
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            
            // Simple reversal for remaining nodes
            while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            return prev;
        }
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends