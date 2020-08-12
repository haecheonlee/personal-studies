#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	
	// opening ith door
	int ans=-1;
	for(int i=0; i<N; i++) {
		int distance=0;
		for(int j=i+1; j<N; j++) distance+=(a[j]*(j-i));
		for(int j=0; j<i; j++) distance+=(a[j]*(N-i+j));
		if(ans==-1 || ans>distance) ans=distance;
	}
	cout<<ans;

	return 0;
}
