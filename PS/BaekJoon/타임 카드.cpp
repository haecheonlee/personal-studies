#include <iostream>

using namespace std;

#define MAX 3
int main() {
	
	int h1, m1, s1, h2, m2, s2;
	int r1 = 0, r2 = 0;
	for(int i=0; i<3; i++) {
		cin>>h1>>m1>>s1>>h2>>m2>>s2;
		
		r1 = (h1 * 3600) + (m1 * 60) + s1;
		r2 = (h2 * 3600) + (m2 * 60) + s2;
		
		r2 -= r1;
		
		int quotient = 3600;
		for(int i=0; i<3; i++) {
			cout<<r2/quotient<<" ";
			r2 %= quotient;
			quotient /= 60;
		}
		cout<<endl;
	}

	return 0;
}

/*
boj.kr/5575

INPUT:
9 0 0 18 0 0
9 0 1 18 0 0
12 14 52 12 15 30

OUTPUT:
9 0 0
8 59 59
0 0 38
*/
