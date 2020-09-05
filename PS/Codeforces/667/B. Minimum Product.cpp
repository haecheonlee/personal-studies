#include <iostream>
 
using namespace std;
using UL=unsigned long long;
 
UL INF=1e18;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		UL a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;
 
		UL a_max=min(a-x, n);
		UL b_max=min(b-y, n);
		
		UL an=(n-a_max>=0 && b-y>=n-a_max) ? ((a-a_max) * (b-(n-a_max))) : INF; 
		UL bn=(n-b_max>=0 && a-x>=n-b_max) ? ((b-b_max) * (a-(n-b_max))) : INF;
		UL cn=((a-x)+(b-y)<=n) ? x*y : INF;
		cout<<min(min(an,bn),cn)<<'\n';
	}
 
	return 0;
}
