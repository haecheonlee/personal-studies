#include <iostream>
#include <cmath>

using namespace std;

string transform(char n, int index) {
	int x=(int)(n-48);
	
	string s="";
	for(int i=2; i>=0; i--) {
		int p=pow(2, i);
		if(x>=p) {
			s+="1";
			x-=p;
		} else {
			s+="0";
		}
	}
	if(index == 0) return to_string(stol(s));
	else return s;
}

int main() {
	string s;
	cin>>s;
	
	string answer="";
	for(int i=0; i<s.size(); i++){
		answer += transform(s[i], i);
	}
	cout<<answer;
	
	return 0;
}

/*
boj.kr/1212

INPUT:
314

OUTPUT:
11001100
*/
