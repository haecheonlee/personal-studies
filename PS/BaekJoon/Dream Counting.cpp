#include <iostream>

using namespace std;

int a[10];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=N; i<=M; i++) {
		int j=i;
		while(j) {
			int d=j%10;
			a[d]++;
			j/=10;
		}
	}
	
	for(int i=0; i<10; i++) cout<<a[i]<<' ';

	return 0;
}
