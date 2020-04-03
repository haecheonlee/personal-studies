#include <iostream>

using namespace std;

class BST {
	struct Node {
		int data;
		Node *left;
		Node *right;
	};
	
	Node *root;
	
	Node *makeEmpty(Node *t) {
		if(t==NULL) return NULL;
		
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		
		return NULL;
	}
	
	Node *insert(int x, Node *t) {
		if(t==NULL) {
			t=new Node;
			t->data=x;
			t->left=t->right=NULL;
		} else {
			if(x<t->data) t->left=insert(x,t->left);
			else if(x>t->data) t->right=insert(x,t->right);
		}
		
		return t;
	}
	
	Node *findMin(Node *t) {
		if(t==NULL) return NULL;
		else if(t->left==NULL) return t;
		else return findMin(t->left);
	}
	
	Node *findMax(Node *t) {
		if(t==NULL) return NULL;
		else if(t->right==NULL) return t;
		else return findMax(t->right);
	}
	
	Node *remove(int x, Node *t) {
		Node *temp;
		if(t==NULL) return NULL;
		else if(x<t->data) t->left=remove(x,t->left);
		else if(x>t->data) t->right=remove(x,t->right);
		else {
			if(t->left==NULL) {
				temp=t;
				t=t->right;
				delete temp;
				return t;
			}
			
			if(t->right==NULL) {
				temp=t;
				t=t->left;
				delete temp;
				return t;
			}
			
			temp=findMin(t->right);
			t->data=temp->data;
			t->right=remove(t->data,t->right);
		}
		return t;
	}
	
	void inorder(Node *t) {
		if(t==NULL) return;
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	
	Node *find(Node *t, int x) {
		if(t==NULL) return NULL;
		else if(x<t->data) return find(t->left,x);
		else if(x>t->data) return find(t->right,x);
		else t;
	}
	
public:
	BST() {
		root=NULL;
	}
	
	~BST() {
		root=makeEmpty(root);
	}
	
	void insert(int x) {
		root=insert(x,root);
	}
	
	void remove(int x) {
		root=remove(x,root);
	}
	
	void display() {
		inorder(root);
		cout<<'\n';
	}
	
	void search(int x) {
		root=find(root,x);
	}
};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    
    return 0; 
}

/* 
  reference: https://gist.github.com/harish-r/a7df7ce576dda35c9660 
*/
