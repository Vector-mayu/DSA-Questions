#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(queue<int>&q, Node *root){
	if(root == nullptr){
		return;
	}

	q.push(root->data);
	levelOrder(q, root->left);
	levelOrder(1, root->right);
}

int main() {
    int x;
    cout << "Enter Root Node: ";
    cin >> x;

    Node *root = new Node(x);

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter Left Node of " << temp->data << ": ";
        cin >> leftVal;

        if (leftVal != -1) {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        cout << "Enter Right Node of " << temp->data << ": ";
        cin >> rightVal;

        if (rightVal != -1) {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << endl;

		queue<int>q;
		levelOrder(q, root);

		while(!q.empty()){
			cout<<q.front()<<" ";
			q.pop();
		}

    return 0;
}