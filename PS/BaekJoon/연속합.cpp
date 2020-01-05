#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int l[n], dp[n], m=-1001;
	for(int i=0; i<n; i++) {
		cin>>l[i];
		
		if(i==0) {
			dp[i]=l[i];		
		} else {
			dp[i]=max(dp[i-1]+l[i], l[i]);
		}
		
		m = max(dp[i], m);
	}
	
	cout<<m;

	return 0;
}

/*
boj.kr/1912

INPUT:
10
10 -4 3 1 5 6 -35 12 21 -1

OUTPUT:
33
*/
