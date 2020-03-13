#include <iostream>

using namespace std;

int main() {
	int arr[1001],sum[1001],v1=1,v2=1;
	for(int i=1; i<=1000; i++) {
		arr[i]=v1;v2--;
		
		if(v2==0) {
			v1++;
			v2=v1;
		}
		sum[i]=sum[i-1]+arr[i];
	}

	int a,b;
	cin>>a>>b;

	cout<<sum[b]-sum[a-1];

	return 0;
}

/*
boj.kr/1292

INPUT:
3 7

OUTPUT:
15
*/
