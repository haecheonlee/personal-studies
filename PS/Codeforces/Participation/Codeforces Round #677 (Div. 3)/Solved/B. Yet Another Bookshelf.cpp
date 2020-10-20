#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		vector<int> p;
		for(int i=0; i<N; i++) {
			cin>>a[i];
			if(a[i]==1) p.push_back(i);	
		}
		
		
		if(p.size()==1) {
			cout<<0<<'\n';
		} else {
			int ans=0;
			for(int i=0; i<(int)p.size()-1; i++) {
				if(p[i]+1 == p[i]) continue;
				ans+=(p[i+1]-p[i]-1);
			}
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}
