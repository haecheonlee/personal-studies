#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

const int MAX=100001;
int n,t,g;
int dist[MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start]=t;
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		if(dist[current]-1>=0) {
			int a=current+1;
			if(dist[a]==-1) {
				dist[a]=dist[current]-1;
				q.push(a);
			}
			
			int b=current*2;
			if(b<=99999) {
				int digit=to_string(b).length()-1;
				b=b-pow(10,digit);
				
				if(dist[b]==-1) {
					dist[b]=dist[current]-1;
					q.push(b);
				}
			}
		}
	}
}

int main() {
	cin>>n>>t>>g;
	
	fill(dist, dist+MAX, -1);
	bfs(n);
	
	if(dist[g]==-1) cout<<"ANG";
	else cout<<t-dist[g];

	return 0;
}

/*
INPUT:
7142 10 7569

OUTPUT:
3
*/
