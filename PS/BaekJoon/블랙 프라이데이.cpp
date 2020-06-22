#include <iostream>
#include <vector>

using namespace std;

int N,C;
vector<int> a;
bool check[100000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>C;

	a.resize(N);	
	for(int i=0; i<N; i++) {
		cin>>a[i];
		check[a[i]]=true;
	}
	
	bool ans=check[C];

	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
			if(a[i]+a[j]==C) {
				ans=true;
				break;
			} else if(a[i]+a[j]<C) {
				int diff=C-a[i]-a[j];
				if(check[diff] && diff!=a[i] && diff!=a[j]) {
					ans=true;
					break;
				}
			}
			if(ans) break;
		}
	}

	if(ans) cout<<1;
	else cout<<0;
	
	return 0;
}
