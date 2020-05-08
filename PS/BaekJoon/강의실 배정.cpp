#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using PI=pair<int,int>;

int main() {
	int n;
	cin>>n;
	
	vector<PI> a(n);
	for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
	sort(a.begin(), a.end());
	
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(a[0].second);
	
	for(int i=1; i<n; i++) {
		if(pq.top()<=a[i].first) pq.pop();
		pq.push(a[i].second);
	}
	
	cout<<pq.size();
	
	return 0;
}

/*
INPUT:
3
1 3
2 4
3 5

OUTPUT:
2
*/
