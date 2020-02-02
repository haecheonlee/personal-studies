#include <iostream>
#include <queue>

using namespace std;


const int MAX=100001;
int a,b,n,m;
int dist[MAX];
bool check[MAX];

void bfs(int index) {
	dist[index]=0;
	check[index]=true;
	queue<int> q;
	q.push(index);
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		if(now-1>=0) {
			if(check[now-1]==false) {
				q.push(now-1);
				check[now-1]=true;
				dist[now-1]=dist[now]+1;
			}
		}
		
		if(now+1<MAX) {
			if(check[now+1]==false) {
				q.push(now+1);
				check[now+1]=true;
				dist[now+1]=dist[now]+1;
			}
		}
		
		if(now+a<MAX) {
			if(check[now+a]==false) {
				q.push(now+a);
				check[now+a]=true;
				dist[now+a]=dist[now]+1;
			}
		}
		
		if(now-a>=0) {
			if(check[now-a]==false) {
				q.push(now-a);
				check[now-a]=true;
				dist[now-a]=dist[now]+1;
			}
		}
		
		if(now+b<MAX) {
			if(check[now+b]==false) {
				q.push(now+b);
				check[now+b]=true;
				dist[now+b]=dist[now]+1;
			}
		}
		
		if(now-b>=0) {
			if(check[now-b]==false) {
				q.push(now-b);
				check[now-b]=true;
				dist[now-b]=dist[now]+1;
			}
		}
		
		if(now*a<MAX) {
			if(check[now*a]==false) {
				q.push(now*a);
				check[now*a]=true;
				dist[now*a]=dist[now]+1;
			}
		}
		
		if(now*b<MAX) {
			if(check[now*b]==false) {
				q.push(now*b);
				check[now*b]=true;
				dist[now*b]=dist[now]+1;
			}
		}
	}
}

int main() {
	cin>>a>>b>>n>>m;
	
	bfs(n);	
	cout<<dist[m];
	
	return 0;
}

/*
boj.kr/12761

INPUT:
3 7 2 98500

OUTPUT:
10
*/
