#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	vector<int> vec[101];
	int n,k,a,b;
	
	cin>>n>>k;
	
	for(int i=0; i<k; i++) {
		cin>>a>>b;
		
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	int dist[101] {0};
	int result=0, components=0;
	for(int i=1; i<=n; i++) {
		queue<int> q;
		if(dist[i]==0) {
			q.push(i);
			if(result!=0) dist[i]=result+1;
			components++;
		}
		
		while(!q.empty()) {
			int current=q.front();
			q.pop();
			
			for(int i=0; i<vec[current].size(); i++) {
				int next=vec[current][i];
				if(dist[next]==0) {
					dist[next]=dist[current]+1;
					q.push(next);
				}
			}
	
			result=max(result, dist[current]);	
		}
	}
	
	if(components>1 || result>6) cout<<"Big World!";
	else cout<<"Small World!";
	
	return 0;
}

/*
boj.kr/18243

INPUT:
10 8
1 2
2 3
3 4
4 5
6 7
7 8
8 9
9 10

OUTPUT:
Big World!
*/
