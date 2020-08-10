#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

vector<int> party[51];
set<int> a[51];
bool check[51];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(check[y]==false) {
				check[y]=true;
				q.push(y);
			}
		}
	}
}

int main() {
	int N,M;
	cin>>N>>M;

	// people who knows truth	
	int K;
	cin>>K;

	for(int i=0; i<K; i++) {
		int x;
		cin>>x;
		
		check[x]=true;
	}
	
	// party starts
	for(int i=0; i<M; i++) {
		int people;
		cin>>people;
		
		int b[people];
		for(int j=0; j<people; j++) {
			cin>>b[j];
			party[i].push_back(b[j]);	
		}
		
		for(int j=0; j<people; j++) {
			for(int k=j+1; k<people; k++) {
				a[b[j]].insert(b[k]);
				a[b[k]].insert(b[j]);
			}
		}
	}
	
	// people get to know truth
	for(int i=1; i<=N; i++) {
		if(check[i]) bfs(i);
	}
	
	int ans=0;
	for(int i=0; i<M; i++) {
		bool is_possible=true;
		// check if there's anyone who knows truth in a party 
		for(auto& x : party[i]) {
			if(check[x]) {
				is_possible=false;
				break;
			}
		}
		if(is_possible) ans++;
	}
	cout<<ans;
	
	return 0;
}
