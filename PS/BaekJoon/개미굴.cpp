/* reference: https://justicehui.github.io/ps/2019/08/27/BOJ14725/ */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	map<string, Node> children;	
};

Node trie;

void insert(Node& node, vector<string>& a, int idx) {
	if(idx==a.size()) return;
	
	if(node.children.find(a[idx]) == node.children.end()) node.children[a[idx]]=Node();
	insert(node.children[a[idx]], a, idx+1);
}

void print(Node& node, int depth) {
	for(auto& x : node.children) {
		for(int i=0; i<depth; i++) cout<<"--";
		cout<<x.first<<'\n';
		print(x.second, depth+1);
	}
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int M;
		cin>>M;

		vector<string> a(M);		
		for(int j=0; j<M; j++) cin>>a[j];
		insert(trie, a, 0);
	}
	
	print(trie,0);

	return 0;
}
