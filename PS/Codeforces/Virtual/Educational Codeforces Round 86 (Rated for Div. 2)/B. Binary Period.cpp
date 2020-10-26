#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string s;
		cin>>s;
		
		if(s.size()<=2) {
			cout<<s<<'\n';
		} else {
			bool is_all_same=true;
			for(int i=0; i<s.size()-1; i++) if(s[i]!=s[i+1]) is_all_same=false;
			
			if(is_all_same) {
				cout<<s<<'\n';
			} else {
				string ns="";
				
				for(int i=1; i<=(s.size()*2)/2; i++) {
					if(s[0]=='0') ns+="01";
					else ns+="10";
				}
				
				cout<<ns<<'\n';
			}
		}
	}
 
	return 0;
}
