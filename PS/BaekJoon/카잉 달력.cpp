#include <iostream>

using namespace std;

int main() {
	int T,M,N,x,y;
	cin>>T;
	
	while(T--) {
		cin>>M>>N>>x>>y;
		
		x-=1;y-=1;
		bool found=false;
		for(int i=x; i<M*N; i+=M) {
			if(i%N==y) {
				cout<<i+1<<'\n';
				found=true;
				break;
			}
		}
		
		if(!found) cout<<-1<<'\n';
	}

	return 0;
}

/*
boj.kr/6064

INPUT:
3
10 12 3 9
10 12 7 2
13 11 5 6

OUTPUT:
33
-1
83
*/
