#include <iostream>

using namespace std;

int dp[1000001];
int doMake(int n) {
	if(n==1) return 0;
	if(dp[n]>0) return dp[n];
	
	dp[n]=doMake(n-1)+1;
	int result=0;
	if(n%2==0) {
		result=doMake(n/2)+1;
		if(dp[n]>result) dp[n]=result;
	}
	
	if(n%3==0){
		result=doMake(n/3)+1;
		if(dp[n]>result) dp[n]=result;
	}
	
	return dp[n];
}

int main() {
	int n;
	cin>>n;
	
	cout<<doMake(n);
	return 0;
}

/*
boj.kr/1463

INPUT:
10

OUTPUT:
3
*/
