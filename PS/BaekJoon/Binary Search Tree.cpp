#include <iostream>

using namespace std;

class Tree {
	struct Node {
		int data;
		Node *left;
		Node *right;
	};
	
	Node *root;
	
	Node *makeEmpty(Node *node) {
		if(node==NULL) return NULL;
		
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
		
		return NULL;
	}
	
	Node *insert(int x, Node *node) {
		if(node==NULL) {
			node=new Node;
			node->data=x;
			node->left=node->right=NULL;
		} else {
			if(x<node->data) node->left=insert(x, node->left);
			else node->right=insert(x, node->right);
		}
		
		return node;
	}
	
	void postorder(Node *node) {
		if(node==NULL) return;
		postorder(node->left);
		postorder(node->right);
		cout<<node->data<<'\n';
	}

public:
	Tree() {
		root=NULL;
	}
	
	~Tree() {
		root=makeEmpty(root);	
	}
	
	void insert(int x) {
		root=insert(x, root);
	}
	
	void display() {
		postorder(root);
	}
};

int main() {
	Tree tree;

	int N;
	while(cin>>N) tree.insert(N);	
	tree.display();
	
	return 0;
}
