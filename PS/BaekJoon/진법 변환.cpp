#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int base;
	string s;
	cin>>s>>base;
	
	int start=0;
	long long result=0;
	
	for(int i=s.size()-1; i>=0; i--) {
		if(s[i]>='A' && s[i]<='Z') result+=pow(base, start)*(s[i]-55);
		else result+=pow(base,start)*(s[i]-'0');
		start++;
	}

	cout<<result;

	return 0;
}

/*
boj.kr/2745

INPUT:
ZZZZZ 36

OUTPUT:
60466175
*/
