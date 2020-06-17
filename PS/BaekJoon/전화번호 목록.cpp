#include <iostream>
#include <vector>

using namespace std;

struct Trie {
	struct Node {
		int children[10];
		bool valid;
		
		Node() {
			for(int i=0; i<10; i++) children[i]=-1;
			valid=false;
		}
	};

	vector<Node> trie;
	int root;
	int init() {
		Node x;
		trie.push_back(x);

		return (int)trie.size()-1;
	}

	Trie() {
		root=init();
	}

	void add(int node, string &s, int index) {
		if(index==s.size()) {
			trie[node].valid=true;
			return;
		}
		
		int c=s[index]-'0';
		if(trie[node].children[c]==-1) {
			int next=init();
			trie[node].children[c]=next;
		}
		
		add(trie[node].children[c], s, index+1);
	}

	void add(string &s) {
		add(root, s, 0);
	}

	bool check(int node) {
		for(int i=0; i<10; i++) {
			if(trie[node].children[i]!=-1) {
				if(trie[node].valid) return false;
				else {
					if(check(trie[node].children[i])==false) return false;
				}
			}
		}

		return true;
	}
};
int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		Trie trie;
		bool check=true;
		for(int i=0; i<n; i++) {
			string s;
			cin>>s;
			
			trie.add(s);
		}

		if(trie.check(0)) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
