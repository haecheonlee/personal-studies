#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX=1e2+1;

set<int> a[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	int total=0;
	for(int i=0; i<M; i++) {
		int K;
		cin>>K;
		
		vector<int> p;
		bool check=false;
		while(K--) {
			int x;
			cin>>x;
			
			p.push_back(x);
			if(x==1) check=true;
		}
		
		if(check) {
			for(auto& x : p) a[x].insert(i);
			total++;
		} else {
			for(int i=0; i<p.size(); i++) {
				for(int j=i+1; j<p.size(); j++) {
					if(i==j) continue;
					
					for(auto& x : a[p[i]]) a[p[j]].insert(x);
					for(auto& x : a[p[j]]) a[p[i]].insert(x);
				}
			}
		}
	}
	
	for(int i=1; i<=N; i++) {
		if(a[i].size()==total) cout<<i<<'\n';
	}
		
	return 0;
}
