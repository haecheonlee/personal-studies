#include <iostream>

using namespace std;

int main() {
	int num[]={1,2,3};
	int d[100001];
	d[0]=1;
	
	for(int i=0; i<3; i++) {
		for(int j=1; j<=10000; j++) {
			if(j-num[i]>=0) d[j]+=d[j-num[i]];
		}
	}

	int t,n;
	cin>>t;
	
	while(t--) {
		cin>>n;
		cout<<d[n]<<'\n';
	}

	return 0;
}

/*
INPUT:
3
4
7
10

OUTPUT:
4
8
14
*/
