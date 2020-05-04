#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dist[10001];
int from[10001];
char how[10001];
bool check[10001];

void print(int n, int m) {
	if(n==m) return;
	print(n, from[m]);
	cout<<how[m];
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		memset(check, false, sizeof(check));
		memset(dist,0,sizeof(dist));
		memset(from,0,sizeof(from));
		memset(how,0,sizeof(how));
		
		check[n]=true;
		dist[n]=0;
		from[n]=-1;

		queue<int> q;
		q.push(n);
		
		while(!q.empty()) {
			int now=q.front();
			q.pop();
			
			int next=(now*2)%10000;
			if(check[next]==false) {
				check[next]=true;
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='D';
				
				q.push(next);
			}
			
			next=now-1;
			if(next==-1) next=9999;
			if(check[next]==false) {
				check[next]=true;
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='S';
				
				q.push(next);
			}
			
			next=((now%1000)*10)+(now/1000);
			if(check[next]==false) {
				check[next]=true;
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='L';
				
				q.push(next);
			}
			
			next=(now/10)+(now%10)*1000;
			if(check[next]==false) {
				check[next]=true;
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='R';
				
				q.push(next);
			}
		}
		
		print(n,m);
		cout<<'\n';
	}

	return 0;
}

/*
INPUT:
3
1234 3412
1000 1
1 16

OUTPUT:
LL
L
DDDD
*/
