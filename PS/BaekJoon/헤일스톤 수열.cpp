#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;

	int n;
	while(T--) {
		cin>>n;
		
		int m=n;
		while(n!=1) {
			m=max(m,n);
			if(!(m&(m-1))) break;

			if(n%2==0) n/=2;
			else n=(n*3)+1;
		}

		cout<<m<<'\n';
	}

	return 0;
}

/*
boj.kr/3943

INPUT:
4
1
3
9999
100000

OUTPUT:
1
16
101248
100000
*/
