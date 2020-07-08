#include <iostream>

using namespace std;

int a[31];

int main() {
	int K,N;
	cin>>K>>N;
	
	for(int i=0; i<N; i++) cin>>a[i];
	
	for(int i=0; i+1<N; i++) {
		if(a[i]<a[i+1]) {
			int temp=K/a[i];
			K=(K%a[i])+temp*a[i+1];
		}
	}
	cout<<K;
	
	return 0;
}
