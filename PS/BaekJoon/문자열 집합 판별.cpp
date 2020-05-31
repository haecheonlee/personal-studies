#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int children[26];
	int pi;
	bool valid;
	
	Node() {
		for(int i=0; i<26; i++) children[i]=-1;
		valid=false;
		pi=-1;
	}
};

vector<Node> trie;

int init() {
	Node x;
	trie.push_back(x);
	
	return (int)trie.size()-1;
}

void add(int node, string &s, int index) {
	if(index==s.size()) {
		trie[node].valid=true;
		return;
	}
	
	int c=s[index]-'a';
	if(trie[node].children[c]==-1) {
		int next=init();
		trie[node].children[c]=next;
	}
	add(trie[node].children[c], s, index+1);
}

int main() {
	int root=init();
	
	int n;
	cin>>n;
	
	vector<string> a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		add(root, a[i], 0);
	}
	
	queue<int> q;
	trie[root].pi=root;
	q.push(root);
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(int i=0; i<26; i++) {
			int next=trie[current].children[i];
			if(next==-1) continue;
			
			if(current==root) {
				trie[next].pi=root;
			} else {
				int x=trie[current].pi;
				while(x!=root && trie[x].children[i]==-1) x=trie[x].pi;
				if(trie[x].children[i]!=-1) x=trie[x].children[i];
				trie[next].pi=x;
			}
			
			int pi=trie[next].pi;
			trie[next].valid |= trie[pi].valid;
			q.push(next);
		}
	}

	int m;
	cin>>m;
	
	while(m--) {
		string s;
		cin>>s;
		
		int node=root;
		bool ok=false;
		
		for(int i=0; i<s.size(); i++) {
			int c=s[i]-'a';
			
			while(node!=root && trie[node].children[c]==-1) node=trie[node].pi;
			if(trie[node].children[c]!=-1) node=trie[node].children[c];
			if(trie[node].valid) ok=true;
		}
		
		cout<<(ok ? "YES" : "NO")<<'\n';
	}

	return 0;
}
