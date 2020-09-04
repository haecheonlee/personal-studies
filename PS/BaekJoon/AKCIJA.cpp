#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	int ans=0, total=0, picked=0;
	for(int i=N-1; i>=0; i--) {
		total+=a[i];
		picked++;
		
		if(picked==3) {
			ans+=(total-a[i]);
			total=picked=0;
		}
	}
	ans+=total;
	cout<<ans;
		
	return 0;
}
