// reference: baekjoon/codeplus

#include <iostream>

using namespace std;

bool broken[10];
int possible(int c) {
	if(c==0) {
		return broken[0]==false;
	}
	
	int pressed=0;
	while(c>0) {
		if(broken[c%10]) return 0;
		pressed++;
		c/=10;
	}
	
	return pressed;
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		
		broken[x]=true;
	}

	int ans=abs(N-100);
	for(int i=0; i<=1000000; i++) {
		int pressed=possible(i);
		
		if(pressed) {
			int extra=abs(N-i);		// pressed +/- button
			ans=min(ans,extra+pressed);
		}
	}
	cout<<ans;
	
	return 0;
}
