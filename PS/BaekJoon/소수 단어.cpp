#include <iostream>

using namespace std;

bool check[2000] {false};

int main() {
	for(int i=2; i<2000; i++) {
		if(check[i]==false) {
			for(int j=i+i; j<2000; j+=i) {
				check[j]=true;
			}
		}
	}
	
	string s;
	cin>>s;
	
	int sum=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='a' && s[i]<='z') {
			sum+=(s[i]-'a')+1;
		} else {
			sum+=(s[i]-'A')+27;
		}
	}
	
	if(check[sum]==false) cout<<"It is a prime word.";
	else cout<<"It is not a prime word.";
	
	return 0;
}

/*
INPUT:
UFRN

OUTPUT:
It is a prime word.
*/
