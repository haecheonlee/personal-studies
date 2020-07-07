#include <iostream>

using namespace std;

int d[10001];

int main() {
	int N,T;
	cin>>N>>T;
	
	while(N--) {
		int K,S;
		cin>>K>>S;
		for(int i=T; i>=K; i--) d[i]=max(d[i],d[i-K]+S);
	}
	
	cout<<d[T];
	
	return 0;
}
