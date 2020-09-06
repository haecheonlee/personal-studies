/* reference: nlog */
 
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		vector<int> a(N);
		int m=1e9, M=0;
		for(int i=0; i<N; i++) {
			cin>>a[i];
			
			m=min(m, a[i]);
			M=max(M, a[i]);
		}
		
		int ans=0;
		for(int sum=m; sum<=M*2; sum++) {
			vector<bool> check(N, false);
			int temp=0;
			
			for(int i=0; i<N; i++) {
				if(check[i]) continue;
				for(int j=i+1; j<N; j++) {
					if(a[i]+a[j]!=sum || check[j]) continue;
					check[i]=check[j]=true;
					temp++;
					break;
				}
			}
			
			ans=max(ans, temp);
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
