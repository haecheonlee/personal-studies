#include <iostream>

using namespace std;
using ll=long long;

int main() {
	int N;
	string s;
	
	cin>>N>>s;
	
	ll c=0;
	ll co=0;
	ll cow=0;
	
	for(int i=0; i<N; i++) {
		if(s[i]=='C') c++;
		else if(s[i]=='O') co+=c;
		else cow+=co;
	}
	cout<<cow;
		
	return 0;
}
