#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
 
	int a, b, c, d, _a, _b, _c, _d;
	for(int i=0; i<T; i++) {
		cin>>a>>b>>c>>d>>_a>>_b>>_c>>_d;
 
		int a_total = a + _a;
		if(a_total < 1) a_total = 1;
 
		int b_total = b + _b;
		if(b_total < 1) b_total = 1;
 
		int c_total = c + _c;
		if(c_total < 0) c_total = 0;
 
		int d_total = d + _d;
 
		int total = a_total + (5 * b_total) + (2 * c_total) + (2 * d_total);
		cout << total << endl;
	}
 
	return 0;
}

/*
boj.kr/12790

INPUT:
3
100 100 100 100 0 0 0 0
10 20 30 40 40 30 20 10
100 100 100 100 -200 0 400 400

OUTPUT:
1000
500
2501
*/
