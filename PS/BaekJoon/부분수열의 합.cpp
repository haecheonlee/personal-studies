#include <iostream>

using namespace std;

int main() {
	int n,s,count=0;
	cin>>n>>s;
	
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	
	for(int i=1; i<(1<<n); i++) {
		int sum=0;
		for(int j=0; j<n; j++) {
			if(i&(1<<j)) {
				sum+=arr[j];
			}
		}
		
		if(s==sum) count++;
	}
	
	cout<<count;

	return 0;
}

/*
boj.kr/1182

INPUT:
5 0
-7 -3 -2 5 8

OUTPUT:
1
*/
