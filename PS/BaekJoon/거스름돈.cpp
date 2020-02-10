#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int cnt=0;
	for(int i=n/5; i>0; i--) {
		if((n-(i*5))%2==0) {
			cnt+=i;
			n=n-(i*5);
			break;
		}
	}
	
	if(n%2==0) {
		cnt+=n/2;
		cout<<cnt;	
	}
	else cout<<-1;

	return 0;
}

/*
boj.kr/14916

INPUT:
14

OUTPUT:
4
*/
