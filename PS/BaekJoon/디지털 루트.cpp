#include <iostream>

using namespace std;

int main() {
	string n="";
	
	while(1) {
		cin>>n;
		if(n=="0") break;
		
		int sum=0;
		while(1) {
			sum=0;
			for(int i=0; i<n.size(); i++) sum+=(int)(n[i]-'0');
			n=to_string(sum);
			if(sum<10) break;
		}
		cout<<sum<<'\n';
	}

	return 0;
}

/*
boj.kr/6738

INPUT:
24
39
0

OUTPUT:
6
3
*/
