#include <iostream>

using namespace std;

int main() {
	string a,b,c,d;
	cin>>a>>b>>c>>d;

	string ab=a+b;
	string cd=c+d;
	
	cout<<stoll(ab)+stoll(cd);

	return 0;
}

/*
boj.kr/10824

INPUT:
10 20 30 40

OUTPUT:
4060
*/
