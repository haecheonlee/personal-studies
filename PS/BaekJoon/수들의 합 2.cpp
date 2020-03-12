#include <iostream>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int sum=0,lo=0,hi=0,cnt=0;
	while(1) 
	{
		if(sum>m || hi==n) {
			sum-=a[lo++];
		} else {
			sum+=a[hi++];
		}
		if(sum==m) cnt++;
		if(lo>=n) break;
	}
	
	cout<<cnt;
	
	return 0;
}

/*
boj.kr/2003

INPUT:
10 5
1 2 3 4 2 5 3 1 1 2

OUTPUT:
3
*/
