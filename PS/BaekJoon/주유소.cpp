#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int d[n-1], p[n];
	for(int i=0; i<n-1; i++) cin>>d[i];
	for(int i=0; i<n; i++) cin>>p[i];

	long long current=1000000001, total=0;
	for(int i=0; i<n-1; i++) {
		if(p[i]<current) current=p[i];
		total+=current*d[i];
	}
	
	cout<<total;

	return 0;
}

/*
boj.kr/13305

INPUT:
4
2 3 1
5 2 4 1

OUTPUT:
18
*/
