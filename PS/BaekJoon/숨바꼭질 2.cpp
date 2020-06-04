#include <iostream>
#include <queue>

using namespace std;

const int MAX=200001;
bool check[MAX];
int dist[MAX];
long long cnt[MAX];

int main() {
	int n,k;
	cin>>n>>k;
	
	check[n]=true;
	dist[n]=0;
	cnt[n]=1;
	
	queue<int> q;
	q.push(n);
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		for(int next : {now-1, now+1, now*2}) {
			if(0<=next && next<MAX) {
				if(check[next]==false) {
					check[next]=true;
					dist[next]=dist[now]+1;
					cnt[next]=cnt[now];
					
					q.push(next);
				} else if(dist[next]==dist[now]+1) {
					cnt[next]+=cnt[now];
				}
			}
		}
	}
	
	cout<<dist[k];
	cout<<'\n';
	cout<<cnt[k];
	
	return 0;
}
