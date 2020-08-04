/* https://sejinik.tistory.com/15 */

#include <iostream>
#include <vector>

using namespace std;

int pre[1001];
int in[1001];
int p[1001];

void go(int s, int e, int x, int y) {
	if(s>e || x>y) return;
	
	int root=pre[s];
	int pos=p[pre[s]];

	go(s+1, s+(pos-x), x, pos-1);
	go(s+(pos-x)+1, e, pos+1, y);
	cout<<root<<' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		for(int i=0; i<N; i++) cin>>pre[i];
		for(int i=0; i<N; i++) {
			cin>>in[i];
			p[in[i]]=i;	
		}
		
		go(0, N-1, 0, N-1);
		cout<<'\n';
	}
	
	return 0;
}
