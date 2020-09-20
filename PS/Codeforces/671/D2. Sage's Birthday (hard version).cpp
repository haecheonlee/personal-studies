#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N], b[N];
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a, a+N);
	
	int x=N/2;
	for(int i=0; i<N; i+=2) b[i]=a[x++];
	x=0;
	for(int i=1; i<N; i+=2) b[i]=a[x++];

	int ans=0;
	for(int i=1; i<N-1; i++) {
		if(b[i]<b[i-1] && b[i]<b[i+1]) ans++;
	}
	
	cout<<ans<<'\n';
	for(int i=0; i<N; i++) cout<<b[i]<<' ';
	
	return 0;
}
