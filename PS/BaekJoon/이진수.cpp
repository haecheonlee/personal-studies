#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin>>t;

	while(t--) {
	    unsigned long long num;
	    cin>>num;
		
		int last=log2(num);
		for(int i=0; i<=last+1; i++) { 
			if(num&1<<i) cout<<i<<" ";
		}
		cout<<'\n';
	}
	
	return 0;
}

/*
boj.kr/3460

INPUT:
1
13

OUTPUT:
0 2 3
*/
