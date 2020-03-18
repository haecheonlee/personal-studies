#include <iostream>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	int len=s.length();
	
	int a[len];
	for(int i=0; i<len; i++) a[i]=s[i]-'0';
	
	for(int i=len/2; i>=0; i--) {
		for(int j=0; j+i*2<=len; j++) {
			int sum1=0, sum2=0;
			for(int k=0; k<i; k++) {
				sum1+=a[k+j];
				sum2+=a[k+j+i];
			}
			
			if(sum1==sum2) {
				cout<<i*2;
				return 0;
			}
		}
	}
	
	cout<<0;
	
	return 0;
}

/*
INPUT:
74233285

OUTPUT:
4
*/

