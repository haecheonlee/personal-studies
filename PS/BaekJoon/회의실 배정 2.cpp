#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

int N;
vector<pair<pi,int>> a;
int ans=0;

void go(int i, int end, int total) {
	if(i==N) {
		ans=max(ans, total);
		return;
	}
	
	// select
	if(end<=a[i].first.first) go(i+1, a[i].first.second, total+a[i].second);
	
	// non-select
	go(i+1, end, total);
}

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int start, end, people;
		cin>>start>>end>>people;
		
		a.push_back({{start,end}, people});
	}
	sort(a.begin(), a.end());
	
	go(0,-1,0);
	cout<<ans;

	return 0;
}
