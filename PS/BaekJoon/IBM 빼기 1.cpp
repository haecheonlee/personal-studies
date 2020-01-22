#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	string name;
	for(int i=1; i<=n; i++) {
		cin>>name;
		
		cout<<"String #"<<i<<'\n';
		for(int i=0; i<name.size(); i++) {
			if(name[i]!='Z') cout<<++name[i];
			else cout<<'A';
		}
		
		if(i<n) cout<<"\n\n";
	}
	
	return 0;
}

/*
boj.kr/6321

INPUT:
2
HAL
SWERC

OUTPUT:
String #1
IBM

String #2
TXFSD
*/
