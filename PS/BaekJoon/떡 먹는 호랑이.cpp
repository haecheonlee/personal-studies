#include <iostream>

using namespace std;

int first_day[31]{0};
int second_day[31]{0};

int main() {
	int d,k;
	cin>>d>>k;
	
	first_day[1]=1;
	second_day[2]=1;
	for(int i=3; i<=d; i++) {
		first_day[i]=first_day[i-1]+first_day[i-2];
		second_day[i]=second_day[i-1]+second_day[i-2];
	}
	
	for(int i=k/second_day[d]; i>=0; i--) {
		int x=k-(i*second_day[d]);
		if(x%first_day[d]==0) {
			cout<<x/first_day[d]<<'\n'<<i;
			return 0;
		}
	}
	
	return 0;
}

/*
boj.kr/2502

INPUT:
6 41

OUTPUT:
2
7
*/
