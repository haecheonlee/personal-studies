#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	while(n--) {
		string s;
		cin>>s;
		
		if(s=="anj") {
			cout<<"뭐야;";
			return 0;
		}
	}
	
	cout<<"뭐야?";

	return 0;
}

/*
boj.kr/17350

INPUT:
4
aptl
molamolamolamola
dlqmfkglahqlcl
QWERTOP

OUTPUT:
뭐야?
*/
