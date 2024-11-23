//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    Node* insertToAVL(Node *node, int data) {
        node = node ? (data < node->data ? (node->left = insertToAVL(node->left, data), node) 
                : (node->right = insertToAVL(node->right, data), node)) 
                : new Node(data);

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalanceFactor(node);

        balance > 1 && data < node->left->data ? (node = rightRotate(node)) :
        balance < -1 && data > node->right->data ? (node = leftRotate(node)) :
        balance > 1 && data > node->left->data ? (node->left = leftRotate(node->left), node = rightRotate(node)) :
        balance < -1 && data < node->right->data ? (node->right = rightRotate(node->right), node = leftRotate(node)) : node;

        return node;
    }

private:
    int getHeight(Node *node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node *node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    Node* rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        x->right = y;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
};

void inorderTraversal(Node *root, vector<int> &result) {
    Node *temp = root;
    stack<Node *> s;
    while (temp || !s.empty()) {
        temp ? (s.push(temp), temp = temp->left) : (temp = s.top(), s.pop(), result.push_back(temp->data), temp = temp->right);
    }
}







//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends