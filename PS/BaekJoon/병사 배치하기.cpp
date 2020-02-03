#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int arr[n+1]{0}, l[n+1]{0};
	
	int m=0;
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
	
		l[i]=1;
		for(int j=1; j<i; j++) {
			if(arr[i]<arr[j] && l[i]<l[j]+1) {
				l[i]=l[j]+1;
				m=max(m, l[i]);
			}
		}
	}
	
	if(m==0) cout<<n-1;
	else cout<<n-m;
	
	return 0;
}

/*
boj.kr/18353

INPUT:
7
15 11 4 8 5 2 4

OUTPUT:
2
*/
