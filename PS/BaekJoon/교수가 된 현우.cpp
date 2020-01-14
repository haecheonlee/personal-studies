#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T,N;
	cin>>T;

	while(T--) {
		cin>>N;
		
		long long count=0, c=5;
		while(1) {
			if(N<c) break;
			
			count+=N/c;
			c*=5;
		}
		
		cout<<count<<'\n';
	}
	
	return 0;
}

/*
boj.kr/3474

INPUT:
6
3
60
100
1024
23456
8735373

OUTPUT:
0
14
24
253
5861
2183837
*/
