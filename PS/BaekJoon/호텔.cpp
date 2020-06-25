#include <iostream>

using namespace std;

int n,m;
pair<int,int> a[20];
int d[1001];

int go(int total) {
	if(total<=0) return 0;
	if(d[total]) return d[total];

	int cost=1e5+1;
	for(int i=0; i<m; i++) {
		int x=go(total-a[i].second)+a[i].first;
		cost=min(cost,x);
	}
	return d[total]=cost;
}

int main() {
	cin>>n>>m;

	for(int i=0; i<m; i++) cin>>a[i].first>>a[i].second;
	cout<<go(n);

	return 0;
}
