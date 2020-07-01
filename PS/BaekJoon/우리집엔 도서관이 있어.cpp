#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	
	
	int x=N;
	int ans=0;
	for(int i=N-1; i>=0; i--) {
		if(x==a[i]) x--;
		else ans++;
	}
	cout<<ans;

	return 0;
}
