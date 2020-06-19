#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int convert(char c) {
	if(c=='A') return 0;
	else if(c=='T') return 1;
	else if(c=='G') return 2;
	else if(c=='C') return 3;
}
struct Node {
	int children[4];	// 'A', 'T', 'G', 'C'
	int pi;
	int cnt;

	Node() {
		for(int i=0; i<4; i++) children[i]=-1;
		pi=-1;
		cnt=0;
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
		trie[node].cnt=1;
		return;
	}
	
	int c=convert(s[index]);
	if(trie[node].children[c]==-1) {
		int next=init();
		trie[node].children[c]=next;
	}
	
	add(trie[node].children[c],s,index+1);
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		trie.clear();
		int root=init();
		
		string s,p;
		cin>>s>>p;
		
		// insert all possible patterns
		vector<string> a;
        for (int i=0; i<m; i++) {
            for (int j=i; j<m; j++) {
                string p2 = p;
                reverse(p2.begin()+i,p2.begin()+j+1);
                a.push_back(p2);
            }
        }
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        for (string &s : a) {
            add(root, s, 0);
        }
		
		//aho-korasick
		queue<int> q;
		trie[root].pi=root;
		q.push(root);
		
		while(!q.empty()) {
			int current=q.front();
			q.pop();
			
			for(int i=0; i<4; i++) {
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
				trie[next].cnt+=trie[pi].cnt;
				q.push(next);
			}
		}
		
		int node=0, ans=0;
		for(int i=0; i<s.size(); i++) {
			int c=convert(s[i]);
			
			while(node!=root && trie[node].children[c]==-1) node=trie[node].pi;
			if(trie[node].children[c]!=-1) node=trie[node].children[c];
			ans+=trie[node].cnt;
		}
		
		cout<<ans<<'\n';
	}

	return 0;
}
