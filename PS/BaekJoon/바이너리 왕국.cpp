#include <iostream>

using namespace std;

bool check[1000001];
int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;

	int cnt=0;
	for(int i=1; i<=N; i++) {
		cin>>check[i];
		
		if(check[i]) {
			if(i==1) cnt++; 
			else if(check[i-1]!=check[i]) cnt++;
		}
	}
	
	while(M--) {
		int K;
		cin>>K;
		
		if(K==0) {
			// print
			cout<<cnt<<'\n';
		} else {
			int x;
			cin>>x;

			if(check[x]) continue;
			check[x]=true;
			if(x==1) {
				if(check[x+1]==false) cnt++;
			} else if(x==N) {
				if(check[x-1]==false) cnt++;
			} else {
				if(check[x-1]==false && check[x+1]==false) cnt++;
				else if(check[x-1] && check[x+1]) cnt--;
			}
		}
	}
	
	return 0;
}
