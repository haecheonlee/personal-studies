#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

int main() {
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	int i=0, j=N-1;
	int total=2e9+1;
	pi ans;
	while(i<j) {
		if(abs(a[i]+a[j])<total) {
			ans.first=a[i];
			ans.second=a[j];
			total=abs(a[i]+a[j]);
		}
		
		if(a[i]+a[j]<0) i++;
		else j--;
	}
	cout<<ans.first<<' '<<ans.second;
	
	return 0;
}
