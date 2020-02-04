#include <iostream>

using namespace std;

const int MAX=7500000;

int main() {
	bool check[MAX+1];

	int k;
	cin>>k;
	
	int count=0;
	for(int i=2; i<=MAX; i++) {
		if(check[i]==false) {
			for(int j=i+i; j<=MAX; j+=i) {
				check[j]=true;
			}
			count++;
		}
		
		if(count==k) {
			cout<<i;
			return 0;
		}
	}
	
	return 0;
}

/*
boj.kr/15965

INPUT:
3

OUTPUT:
5
*/
