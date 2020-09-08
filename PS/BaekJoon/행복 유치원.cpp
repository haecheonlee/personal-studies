/* reference: jack2020 in the question board */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX=3e5+1;

int a[MAX], d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,K;
	cin>>N>>K;
	
	for(int i=0; i<N; i++) cin>>a[i];
	for(int i=0; i<N-1; i++) d[i]=a[i+1]-a[i];
	sort(d, d+N-1);
	
	int ans=0;
	for(int i=0; i<N-K; i++) ans+=d[i];
	cout<<ans;

	return 0;
}
