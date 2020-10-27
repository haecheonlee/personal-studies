/* reference: kks227 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=3e3+1;

vector<int> a[MAX];
int degree[MAX];
bool check[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
		
		degree[u]++, degree[v]++;
	}
	
	int cnt=0;
	for(int i=1; i<=N; i++) {
		if(degree[i]%2==1) cnt++;
	}
	
	if(cnt!=0 && cnt!=2) {
		cout<<"NO";
		return 0;
	}
	
	queue<int> q;
	q.push(1);
	check[1]=true;
	cnt=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		cnt++;
		
		for(auto& y : a[x]) {
			if(check[y]==false) {
				check[y]=true;
				q.push(y);
			}
		}
	}
	
	cout<<(cnt < N ? "NO" : "YES");
	
	return 0;
}
