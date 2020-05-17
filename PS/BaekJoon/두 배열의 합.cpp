#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	int m;
	cin>>m;
	vector<int> b(m);
	for(int i=0; i<m; i++) cin>>b[i];
	
	vector<int> x;
	for(int i=0; i<n; i++) {
		int sum=0;
		for(int j=i; j<n; j++) {
			sum+=a[j];
			x.push_back(sum);
		}
	}
	
	vector<int> y;
	for(int i=0; i<m; i++) {
		int sum=0;
		for(int j=i; j<m; j++) {
			sum+=b[j];
			y.push_back(sum);
		}
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	long long ans=0;
	for(int i=0; i<x.size(); i++) {
		auto p=equal_range(y.begin(), y.end(), t-x[i]);
		ans+=p.second-p.first;
	}
	cout<<ans;
	
	return 0;
}
