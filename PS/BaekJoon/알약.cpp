#include <iostream>
#include <cstring>

using namespace std;

long long d[31][31];
long long go(int F, int H) {
	if(d[F][H]!=-1) return d[F][H];
	if(F==0) return 1;
	if(H==0) return d[F][H]=go(F-1,H+1);
	return d[F][H]=go(F-1,H+1)+go(F,H-1);
}

int main() {
	memset(d,-1,sizeof(d));
	int n;
	
	while(cin>>n) {
		if(n==0) break;
		cout<<go(n,0)<<'\n';
	}

	return 0;
}
