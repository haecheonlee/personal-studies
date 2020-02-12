#include <iostream>

using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	
	int cnt=51;
	for(int i=0; i<=b.size()-a.size(); i++) {
		int counted=0;
		for(int j=0; j<a.size(); j++) {
			if(a[j]!=b[i+j]) counted++;
		}

		cnt=min(cnt,counted);
	}

	cout<<cnt;

	return 0;
}

/*
boj.kr/1120

INPUT:
adaabc aababbc

OUTPUT:
2
*/
