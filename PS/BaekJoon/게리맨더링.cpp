#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int total=0;
int people[11];
vector<int> edge[11];

int go(const vector<int> &a) {
	bool visited[10] {false};
	
	queue<int> q;
	q.push(a[0]);
	visited[a[0]]=true;
	int sum=people[a[0]];
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();

		for(auto y : edge[x]) {
			if(find(a.begin(), a.end(), y)!=a.end()) {
				if(visited[y]==false) {
					visited[y]=true;
					q.push(y);
					sum+=people[y];
				}
			}
		}
	}

	for(auto x : a) {
		if(visited[x]==false) return -1;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	
	for(int i=0; i<N; i++) {
		cin>>people[i];
		total+=people[i];
	}
	
	for(int x=0; x<N; x++) {
		int M;
		cin>>M;
		
		while(M--) {
			int y;
			cin>>y;
			
			y-=1;
			edge[x].push_back(y);
		}
	}
	
	int ans=-1;
	int len=(1<<N);
	for(int i=1; i<len; i++) {
		vector<int> a,b;
		
		for(int j=0; j<N; j++) {
			if(i&(1<<j)) a.push_back(j);
			else b.push_back(j);
		}
		if(a.size()==N) continue;
		
		int p1=go(a);
		int p2=go(b);
		
		if(p1!=-1 && p2!=-1) {
			int p2=abs(p1-total);
			int diff=abs(p1-p2);
			
			if(ans==-1 || ans>diff) ans=diff;
		}
	}
	cout<<ans;

	return 0;
}
