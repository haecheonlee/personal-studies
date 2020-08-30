#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX=1e5+1;

int d[MAX];
bool check[MAX];	// police

int main() {
	int N,S,D,F,B,K;
	cin>>N>>S>>D>>F>>B>>K;
	
	for(int i=0; i<K; i++) {
		int x;
		cin>>x;
		
		check[x]=true;
	}
	
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(S);
	d[S]=0;
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		int forward=now+F;
		if(forward<=N) {
			if(check[forward]==false && d[forward]==-1) {
				d[forward]=d[now]+1;
				q.push(forward);
			}
		}
		
		int backward=now-B;
		if(1<=backward) {
			if(check[backward]==false && d[backward]==-1) {
				d[backward]=d[now]+1;
				q.push(backward);
			}
		}
	}
	
	if(d[D]==-1) cout<<"BUG FOUND";
	else cout<<d[D];

	return 0;
}
