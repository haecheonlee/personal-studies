#include <iostream>

using namespace std;

#define modular 1000000009
#define max 100001

long long DP[max][4];
int main() {
	for(int i=1; i<max; i++) {
		if(i-1 >= 0) {
			DP[i][1]=DP[i-1][2]+DP[i-1][3];
			if(i==1) DP[i][1]=1;
		}
		
		if(i-2>=0) {
			DP[i][2]=DP[i-2][1]+DP[i-2][3];
			if(i==2) DP[i][2]=1;
		}
		
		if(i-3>=0) {
			DP[i][3]=DP[i-3][1]+DP[i-3][2];
			if(i==3) DP[i][3]=1;
		}
		
		DP[i][1]%=modular;
		DP[i][2]%=modular;
		DP[i][3]%=modular;
	}
	
	int T;
	cin>>T;
	
	int num;
	while(T--) {
		cin>>num;
		cout<<(DP[num][1]+DP[num][2]+DP[num][3])%modular<<'\n';
	}
	
	return 0;
}

/*
boj.kr/15990

INPUT:
3
4
7
10

OUTPUT:
3
9
27
*/
