//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        for (; curr; ) {
            Node* right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
        }
        return prev;
    }

  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        int carry = 0;
        Node* preHead = new Node(-1);
        Node* curr = preHead;
        for (; num1->next && num1->data == 0; num1 = num1->next);
        for (; num2->next && num2->data == 0; num2 = num2->next);
        Node* curr1 = reverse(num1);
        Node* curr2 = reverse(num2);

        for (; curr1 || curr2 || carry; ) {
            int sum = (curr1 ? curr1->data : 0) + (curr2 ? curr2->data : 0) + carry;
            Node* newNode = new Node(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
            curr1 = curr1 ? curr1->next : curr1;
            curr2 = curr2 ? curr2->next : curr2;
        }

        Node* ans = preHead->next;
        delete preHead;
        return reverse(ans);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends