#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<int,int>;

const int MAX=1e5+1;

vector<PI> a[MAX];
bool check[MAX];
int n,m,s,e;

bool go(int mid) {
	for(int i=1; i<=n; i++) check[i]=false;
	
	queue<int> q;
	q.push(s);
	check[s]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		if(x==e) return true;
		for(int i=0; i<a[x].size(); i++) {
			int y=a[x][i].first;
			if(check[y]) continue;
			
			int cost=a[x][i].second;
			if(cost>=mid) {
				q.push(y);
				check[y]=true;
			}
		}
	}
	
	return false;
}

int main() {
	cin>>n>>m>>s>>e;
	
	while(m--) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}
	
	int left=0, right=1e6+1, result=0;

	while(left<=right) {
		int mid=(right+left)/2;
		
		if(go(mid)) {
			result=mid;
			left=mid+1;
		} else {
			right=mid-1;
		}
	}
	cout<<result;
	
	return 0;
}
