#include <iostream>

using namespace std;

int main() {
	int a,b,n,z;
	cin>>a>>b>>n;
	
	int selected=abs(a-b);
	int cnt=0;
	for(int i=0; i<n; i++) {
		cin>>z;
		
		if(selected>abs(z-b)) {
			selected=abs(z-b);
			cnt=1;
		}
	}
	
	cout<<selected+cnt;

	return 0;
}

/*
boj.kr/3135

INPUT:
88 17
3
18
1
42

OUTPUT:
2
*/
