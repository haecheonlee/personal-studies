#include <iostream>

using namespace std;

unsigned long long DP[68] {0};
int main() {
	
	DP[0]=1;DP[1]=1;DP[2]=2;DP[3]=4;
	
	int t;
	cin>>t;
	
	int n;
	for(int i=0; i<t; i++) {
		cin>>n;

		for(int j=4; j<=n; j++) {
			DP[j]=DP[j-1]+DP[j-2]+DP[j-3]+DP[j-4];
		}
		
		cout<<DP[n]<<'\n';
	}
	
	return 0;
}

/*
boj.kr/9507

INPUT:
8
0
1
2
3
4
5
30
67

OUTPUT:
1
1
2
4
8
15
201061985
7057305768232953720
*/
