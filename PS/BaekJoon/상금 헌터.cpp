#include <iostream>

using namespace std;

int go1(int rank) {
	if(rank==1) return 500;
	if(rank==2) return 300;
	if(rank==3) return 200;
	if(rank==4) return 50;
	if(rank==5) return 30;
	if(rank==6) return 10;
}

int go2(int rank) {
	if(rank==1) return 1<<9;
	if(rank==2) return 1<<8;
	if(rank==3) return 1<<7;
	if(rank==4) return 1<<6;
	if(rank==5) return 1<<5;
}

int main() {
	int n,a,b;
	cin>>n;
	
	while(n--) {
		cin>>a>>b;
		
		int reward=0;
		
		int cnt=0;
		if(a>0) {
			for(int i=1; i<=6; i++) {
				cnt+=i;
				
				if(a<=cnt) {
					reward+=go1(i);
					break;
				}
			}
		}
		
		cnt=0;
		if(b>1) {
			for(int i=1; i<=5; i++) {
				cnt+=(1<<i-1);
				if(b<=cnt) {
					reward+=go2(i);
					break;
				}
			}
		}
		
		cout<<reward*10000<<'\n';
	}
	
	return 0;
}

/*
INPUT:
6
8 4
13 19
8 10
18 18
8 25
13 16

OUTPUT:
1780000
620000
1140000
420000
820000
620000
*/
