#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	int sum=0, ans=0;
	for(int i=0; i<n; i++) {
		sum+=a[i];
		ans+=sum;
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
5
3 1 4 3 2

OUTPUT:
32
*/
