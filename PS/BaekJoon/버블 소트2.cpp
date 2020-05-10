#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<pair<int,int>> a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	
	sort(a.begin(), a.end());
	
	int ans=0;
	for(int i=0; i<n; i++) {
		if(a[i].second-i>ans) ans=a[i].second-i;
	}
	cout<<ans+1;

	return 0;
}

/*
INPUT:
5
10
1
5
2
3

OUTPUT:
3
*/
