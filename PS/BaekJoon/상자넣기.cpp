#include <iostream>

using namespace std;

int DP[1001]{0};
int main() {
	int n;
	cin>>n;
	
	int list[n+1];
	for(int i=1; i<=n; i++) {
		cin>>list[i];
	}
	
	int m=-1;
	for(int i=1; i<=n; i++) {
		DP[i]=1;
		for(int j=i-1; j>=1; j--) {
			if(list[i]>list[j] && DP[i]<DP[j]+1) {
				DP[i]=DP[j]+1;
			}
		}
		
		m=max(m, DP[i]);	
	}
	
	cout<<m;

	return 0;
}

/*
boj.kr/1965

INPUT:
8
1 6 2 5 7 3 5 6

OUTPUT:
5
*/
