#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> a(n), b(n), c(n), d(n);
	for(int i=0; i<n; i++) {
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	
	vector<int> first, second;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			first.push_back(a[i]+b[j]);
			second.push_back(c[i]+d[j]);
		}
	}
	sort(second.begin(), second.end());
	
	long long ans=0;
	for(int &num : first) {
		auto range=equal_range(second.begin(), second.end(), -num);
		ans+=range.second-range.first;
	}
	cout<<ans;

	return 0;
}
