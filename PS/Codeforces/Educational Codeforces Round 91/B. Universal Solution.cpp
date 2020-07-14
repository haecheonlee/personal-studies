#include <iostream>

using namespace std;

char get_winning(char x) {
	if(x=='R') return 'P';
	if(x=='S') return 'R';
	if(x=='P') return 'S';
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string s;
		cin>>s;
		
		int cnt[3]={0,0,0};
		for(auto x : s) {
			char w=get_winning(x);
			
			if(w=='R') cnt[0]++;
			else if(w=='S') cnt[1]++;
			else if(w=='P') cnt[2]++;
		}
		
		int idx=0, total=cnt[0];
		for(int i=1; i<3; i++) {
			if(total<cnt[i]) {
				idx=i;
				total=cnt[i];
			}
		}
		
		
		string ans="";
		for(int i=0; i<s.size(); i++) {
			if(idx==0) ans+='R';
			else if(idx==1) ans+='S';
			else if(idx==2) ans+='P';
		}
		cout<<ans<<'\n';
	}

	return 0;
}
