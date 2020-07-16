#include <iostream>

using namespace std;
const int MAX=1025;

int N;
int a[MAX];
bool is[MAX];

bool check(int k) {
	for(int i=0; i<N; i++) {
		if(!is[a[i]^k]) return false;
	}
	return true;
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		for(int i=0; i<MAX; i++) is[i]=false;
		
		cin>>N;
		for(int i=0; i<N; i++) {
			cin>>a[i];
			is[a[i]]=true;
		}
		
		int k;
		for(k=1; k<1024; k++) {
			if(check(k)) break;
		}
		
		if(k==1024) cout<<-1<<'\n';
		else cout<<k<<'\n';
	}

	return 0;
}
