#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int A[N];
	int MN[N], MX[N];
	for(int i=0; i<N; i++) {
		cin>>A[i];
		
		if(i==0) MN[i]=A[i];
		else MN[i]=min(MN[i-1], A[i]);
	}
	
	for(int i=N-1; i>=0; i--) {
		if(i==N-1) MX[i]=A[i];
		else MX[i]=max(MX[i+1], A[i]);
	}
	
	int ans=0;
	for(int i=0; i<N-1; i++) ans=max(ans, MX[i+1]-MN[i]);
	cout<<ans;
	
	return 0;
}
