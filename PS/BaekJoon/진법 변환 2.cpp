#include <iostream>

using namespace std;

int main() {
	int n, b;
	cin>>n>>b;
	
	string result="";
	while(n>0) {
		int remainder=n%b;
		n/=b;
		if(remainder>=10) result+='A'+(remainder-10);
		else result+=(remainder+'0');
	}

	for(int i=result.size()-1; i>=0; i--) {
		cout<<result[i];
	}

	return 0;
}

/*
boj.kr/11005

INPUT:
60466175 36

OUTPUT:
ZZZZZ
*/
