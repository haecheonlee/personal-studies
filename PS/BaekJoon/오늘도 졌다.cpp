#include <iostream>

using namespace std;

const int N=9;

int a[N], b[N];

int main() {
	for(int i=0; i<N; i++) cin>>a[i];
	for(int i=0; i<N; i++) cin>>b[i];
	
	int A=0, B=0;
	bool is_a_winning=false;
	for(int i=0; i<N; i++) {
		A+=a[i];
		if(A>B) is_a_winning=true;
		B+=b[i];
	}
	
	if(is_a_winning && B>A) cout<<"Yes";
	else cout<<"No";

	return 0;
}
