/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

int N,M;
int A[100];

int calc(int i, string s) {
	if(i+s.length()>N) return 0;
	int base=A[i]-(s[0]-'0');
	for(int j=0; j<s.length(); j++) {
		if(base!=A[i+j]-(s[j]-'0')) return 0;
	}
	return 1;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) cin>>A[i];
	
	int ans=0;
	for(int i=0; i<N; i++) {
		if(M==1) ans+=calc(i,"0")+calc(i,"0000");
		else if(M==2) ans+=calc(i,"00");
		else if(M==3) ans+=calc(i,"001")+calc(i,"10");
		else if(M==4) ans+=calc(i,"100")+calc(i,"01");
		else if(M==5) ans+=calc(i,"000")+calc(i,"01")+calc(i,"101")+calc(i,"10");
		else if(M==6) ans+=calc(i,"000")+calc(i,"00")+calc(i,"011")+calc(i,"20");
		else if(M==7) ans+=calc(i,"000")+calc(i,"00")+calc(i,"110")+calc(i,"02");
	}
	cout<<ans;
	
	return 0;
}
