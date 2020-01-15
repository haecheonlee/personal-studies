#include <iostream>
#include <algorithm>

using namespace std;

bool checkIfP(string s) {
	string first=s.substr(0, s.size()/2);
	string second=s.substr(s.size()/2 + ((s.size()%2==0) ? 0 : 1));
	
	reverse(second.begin(), second.end());
	
	return first==second;
}

bool checkIfPP(string s) {
	string c1, c2;
	
	for(int i=0; i<s.size()/2; i++) {
		int back = s.size()-i-1;
		if(s[i] != s[back]) {
			c1=s; c2=s;
			c1.erase(i,1);
			c2.erase(back, 1);
			
			bool first=checkIfP(c1);
			bool second=checkIfP(c2);
			
			if(first || second) return true;
			else return false;
		}
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	string s;
	while(T--) {
		cin>>s;
		
		if(checkIfP(s)) cout<<0<<'\n';
		else if(checkIfPP(s)) cout<<1<<'\n';
		else cout<<2<<'\n';
	}
	
    return 0;
}

/*
boj.kr/17609

INPUT:
7
abba
summuus
xabba
xabbay
comcom
comwwmoc
comwwtmoc

OUTPUT:
0
1
1
2
2
0
1
*/
