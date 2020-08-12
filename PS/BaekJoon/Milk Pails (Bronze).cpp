#include <iostream>

using namespace std;

int main() {
	int X,Y,M;
	cin>>X>>Y>>M;
	
	int L=M/X;
	
	int ans=0;
	for(int i=0; i<=L; i++) {
		int x=i*X;
		int y=((M-x)/Y)*Y;
		ans=max(ans, x+y);
	}
	cout<<ans;
	
	return 0;
}
