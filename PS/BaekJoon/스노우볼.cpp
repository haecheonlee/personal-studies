#include <iostream>
using namespace std;

#define divider 1000000007

int main() {
	int H, x;
	cin>>H>>x;
	
	long long total=0, num=0, i=1;
	for(int j=0; j<H; j++) {
		cin>>num;
		i *= x; i %= divider;
		total += (num * i); total %= divider;
	}
	
	cout<<total;
	return 0;
}

/*
boj.kr/17950

INPUT:
4 5
1
3
2
4

OUTPUT:
2830
*/
