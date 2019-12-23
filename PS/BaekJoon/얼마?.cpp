#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	int total=0,s,n;
	for(int i=0; i<T; i++) {
		cin>>s>>n;
		
		total = s;
		int q,p;
		for(int j=0; j<n; j++) {
			cin>>q>>p;
			
			total += (q*p);
		}
		
		cout<<total<<endl;;
	}

	return 0;
}

/*
boj.kr/9325

INPUT:
2
10000
2
1 2000
3 400
50000
0

OUTPUT:
13200
50000
*/
