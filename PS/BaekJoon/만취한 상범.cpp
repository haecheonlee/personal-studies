#include <iostream>

using namespace std;

int main() {
	int T, n;
	cin>>T;
	
	for(int i=0; i<T; i++) {
		cin>>n;
		
		int rooms[n+1]{0};
		for(int i=2; i<=n; i++) {
			for(int j=i; j<=n; j+=i) {
				if(rooms[j] == 0) rooms[j]=1;
				else rooms[j]=0;
			}
		}
		
		int count=0;
		for(int i=1; i<=n; i++) {
			if(rooms[i] == 0) count++;
		}
		cout<<count<<'\n';
	}
	
	return 0;
}

/*
boj.kr/6359

INPUT:
2
5
100

OUTPUT:
2
10
*/
