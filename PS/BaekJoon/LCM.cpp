#include <iostream>

using namespace std;

long long lcd(long long a, long long b) {
	if(b==0) return a;
	
	return lcd(b, a%b);
}

int main() {
	long long n,a,b;
	cin>>n;
	
	while(n--) {
		cin>>a>>b;
		cout<<(a*b)/lcd(a,b)<<'\n';
	}
	
	return 0;
}

/*
boj.kr/5347

INPUT:
3
15 21
33 22
9 10

OUTPUT:
105
66
90
*/
