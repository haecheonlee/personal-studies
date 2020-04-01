#include <iostream>
#include <vector>

using namespace std;

struct Trie {
	struct Node {
		int children[26];
		bool valid;
		Node() {
			for(int i=0; i<26; i++) children[i]=-1;
			valid=false;
		}
	};
	
	vector<Node> trie;
	int root;
	
	Trie() {
		root=init();
	}
	
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
		int child=trie[node].children[c];
		add(child,s,index+1);
	}
	
	void add(string &s) {
		add(root,s,0);
	}
	
	bool search(int node, string &s, int index) {
		if(node==-1) return false;
		if(s.length()==index) return true;
		
		int child=trie[node].children[s[index]-'a'];
		return search(child,s,index+1);
	}
	
	bool search(string &s) {
		return search(root,s,0);
	}
};

int main() {
	int n,m;
	cin>>n>>m;
	
	Trie trie;
	while(n--) {
		string s;
		cin>>s;
		
		trie.add(s);
	}
	
	int cnt=0;
	while(m--) {
		string s;
		cin>>s;
		
		if(trie.search(s)) cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}

/*
INPUT:
5 10
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
star
start
code
sunday
coding
cod
online
judge
plus

OUTPUT:
7
*/
