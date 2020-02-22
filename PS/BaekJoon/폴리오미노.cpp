#include <iostream>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	string result="";
	int cnt=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='X') cnt++;
		
		if(s[i]=='.' || i==s.size()-1){
			if(cnt%2!=0) {
				cout<<-1;
				return 0;
			}
			
			for(int j=0; j<cnt/4; j++) result+="AAAA";
			cnt%=4;
			for(int j=0; j<cnt/2; j++) result+="BB";
			if(s[i]=='.') result+=s[i];

			cnt=0;
    }
	}
	
	cout<<result;

	return 0;
}

/*
boj.kr/1343

INPUT:
XX.XXXXXXXXXX..XXXXXXXX...XXXXXX

OUTPUT:
BB.AAAAAAAABB..AAAAAAAA...AAAABB
*/
