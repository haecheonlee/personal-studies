#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> a[10001];
bool c[10001];
int n,m;
int start,ed;

bool go(int node, int limit) {
	if(c[node]) return false;
	if(node==ed) return true;
	c[node]=true;
	
	for(auto &p : a[node]) {
		int next=p.first;
		int cost=p.second;
		
		if(cost>=limit) {
			if(go(next,limit)) return true;
		}
	}
	
	return false;
}

int main() {
	cin>>n>>m;
	while(m--) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}
	cin>>start>>ed;
	
	int left=1;
	int right=1e9;
	int ans=0;
	
	while(left<=right) {
		int mid=(left+right)/2;
		memset(c,false,sizeof(c));
		
		if(go(start,mid)) {
			ans=mid;
			left=mid+1;
		} else {
			right=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
3 3
1 2 2
3 1 3
2 3 2
1 3

OUTPUT:
3
*/
