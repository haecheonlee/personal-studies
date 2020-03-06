#include <iostream>

using namespace std;

int main() {
	int n,c,l;
	cin>>n;
	
	int a[11];
	for(int i=0; i<=10; i++) a[i]=-1;

	int cnt=0;
	for(int i=0; i<n; i++) {
		cin>>c>>l;
		
		if(a[c]==-1) a[c]=l;
		else {
			if(a[c]!=l) cnt++;
			a[c]=l;
		}
	}
	
	cout<<cnt;
	
	return 0;
}

/*
boj.kr/14467

INPUT:
8
3 1
3 0
6 0
2 1
4 1
3 0
4 0
3 1

OUTPUT:
3
*/
