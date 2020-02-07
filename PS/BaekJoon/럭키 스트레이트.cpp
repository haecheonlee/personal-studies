#include <iostream>

using namespace std;

int getTotal(string s) {
	int total=0;
	for(int i=0; i<s.size(); i++) total+=s[i]-'0';
	return total;
}

int main() {
	string s;
	cin>>s;
	
	int l=getTotal(s.substr(0,s.size()/2));
	int r=getTotal(s.substr(s.size()/2));
	
	if(l==r) cout<<"LUCKY";
	else cout<<"READY";
	
	return 0;
}

/*
boj.kr/18406

INPUT:
123402

OUTPUT:
LUCKY
*/
