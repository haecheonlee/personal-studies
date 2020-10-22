#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N*2];
	for(int i=0; i<N; i++) cin>>a[i];
	for(int i=N; i<N*2; i++) a[i]=a[i-N];
	
	int ans=0, rest=0;
	for(int i=0; i<N*2; i++) {
		rest=(a[i]==1 ? rest+1 : 0);
		ans = max(ans, rest);
	}
	cout<<ans;
	
	return 0;
}
