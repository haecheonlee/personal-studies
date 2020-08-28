/* reference: jh05013 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=1e5+1;

int N,M;
vector<int> a[MAX];
vector<int> b[MAX];
bool visited1[MAX];
bool visited2[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x].push_back(y);	// 1 to N
		b[y].push_back(x);	// N to 1
	}

	// 1 to N
	queue<int> q;
	q.push(1);
	visited1[1]=true;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(visited1[y]==false) {
				visited1[y]=true;
				q.push(y);
			}
		}
	}
	
	// N to 1
	q.push(N);
	visited2[N]=true;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : b[x]) {
			if(visited2[y]==false) {
				visited2[y]=true;
				q.push(y);
			}
		}
	}

	int T;
	cin>>T;
	
	while(T--) {
		int x;
		cin>>x;

		if(visited1[x] && visited2[x]) cout<<"Defend the CTP\n";
		else cout<<"Destroyed the CTP\n";
	}
	
	return 0;
}
