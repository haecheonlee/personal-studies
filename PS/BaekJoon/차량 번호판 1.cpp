#include <iostream>

using namespace std;

int go(string &s, int index, char last) {
	if(s.length()==index) return 1;
	
	char start=((s[index]=='d') ? '0' : 'a');
	char end=((s[index]=='d') ? '9' : 'z');
	int ans=0;
	for(int i=start; i<=end; i++) {
		if(i!=last) ans+=go(s,index+1,i);
	}
	
	return ans;
}

int main() {
	string s;
	cin>>s;
	
	cout<<go(s,0,' ');
	
	return 0;
}

/*
INPUT:
dcdd

OUTPUT:
23400
*/
