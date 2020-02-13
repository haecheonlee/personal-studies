#include <iostream>

using namespace std;

int main() {
	int n;
	string p,word;
	cin>>n>>p;
	
	int s_pos=p.find('*');
	string p_s=p.substr(0,s_pos);
	string p_e=p.substr(s_pos+1);

	while(n--) {
		cin>>word;
		
		if(word.size()<p_s.size()+p_e.size()) {
			cout<<"NE\n";
		} else {
			if(word.substr(0,p_s.size())==p_s && word.substr(word.size()-p_e.size())==p_e) cout<<"DA\n";
			else cout<<"NE\n";
		}
	}
	
	return 0;
}

/*
boj.kr/9996

INPUT:
3
a*d
abcd
anestonestod
facebook

OUTPUT:
DA
DA
NE
*/
