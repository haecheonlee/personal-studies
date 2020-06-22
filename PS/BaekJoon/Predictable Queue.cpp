#include <iostream>
#include <vector>

using namespace std;

int N,K,T;
vector<int> p;

bool go(int M) {
	int sum=p[M];
	return sum<=T;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>K;
	
	p.resize(N+1);
	for(int i=1; i<=N; i++) {
        int x;
        cin>>x;
        
        if(i==1) p[i]=x;
		else p[i]+=p[i-1]+x;
    }
	
	while(K--) {
		cin>>T;
	
		int L=1, R=N;
		int ans=0;
		while(L<=R) {
			int M=(L+R)/2;

			if(go(M)) {
				L=M+1;
				ans=M;
			} else {
				R=M-1;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
