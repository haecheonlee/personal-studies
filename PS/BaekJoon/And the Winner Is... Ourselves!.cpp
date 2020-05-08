#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using PI=pair<int,int>;

int main() {
	vector<PI> a;
	
	for(int i=0; i<11; i++) {
		int t,v;
		cin>>t>>v;

		a.push_back(make_pair(t,v));
	}
	
	sort(a.begin(), a.end());
	
	int ans=0,sum=0;
	for(int i=0; i<11; i++) {
		sum+=a[i].first;
		ans+=sum+(a[i].second*20);
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
20 1
20 0
20 3
10 0
10 0
10 0
30 0
30 0
30 0
20 0
20 10

OUTPUT:
1360
*/
