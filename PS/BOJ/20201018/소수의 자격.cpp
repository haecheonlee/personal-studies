#include <iostream>

using namespace std;

const int MAX=4e6+1;

bool check[MAX];

int main() {
	check[0]=check[1]=true;
	for(int i=2; i<MAX; i++) {
		if(check[i]==false) {
			for(int j=2; j*i<MAX; j++) check[j*i]=true;
		}
	}
	
	int A,B;
	cin>>A>>B;
	
	string D;
	cin>>D;
	
	int ans=0;
	for(int i=A; i<=B; i++) {
		if(check[i]==false) {
			string s=to_string(i);
			if(s.find(D)!=string::npos) ans++;
		}
	}
	cout<<ans;

	return 0;
}
