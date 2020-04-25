#include <iostream>

using namespace std;

char convert(string s) {
	if(s=="000") return '0';
	if(s=="001") return '1';
	if(s=="010") return '2';
	if(s=="011") return '3';
	if(s=="100") return '4';
	if(s=="101") return '5';
	if(s=="110") return '6';
	if(s=="111") return '7';
}

int main() {
	string s;
	cin>>s;
	
	for(int i=0; i<s.size()%3; i++) s='0'+s;
	for(int i=0; i<s.size()/3; i++) cout<<convert(s.substr(i*3,3));
	
	return 0;
}

/*
INPUT:
1010

OUTPUT:
12
*/
