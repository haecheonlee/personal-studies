#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string a;
		int s;
		cin>>a>>s;
		
		int sum=0;
		for(auto & c : a) sum+=(c-'0');
		if(sum<=s) {
			cout<<0<<'\n';
			continue;
		}
		
		int total=0;
		int pos=0;
		while(total+(a[pos]-'0')<s && pos<a.size()) {
			total+=(a[pos]-'0');
			pos++;
		}
 
		string str=a.substr(pos);
		int L=str.size()+1;
		int p[L]={1};
		for(int i=str.size()-1; i>=0; i--) {
			int x=str[i]-'0';
			int pi=i+1;
			
			if(p[pi]-x<0) {
				int j;
				for(j=pi-1; j>=0; j--) if(p[j]) break; 
				
				while(j<pi) {
					p[j]--;
					p[j+1]+=10;
					j++;
				}
			}
			
			p[pi]-=x;
		}
		
		int i;
		for(i=0; i<L; i++) {
			if(p[i]==0) continue;
			else break;
		}
		while(i<L) cout<<p[i++];
		
		cout<<'\n';
	}
	
	return 0;
}
