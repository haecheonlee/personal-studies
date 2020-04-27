#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> list[20001];
int d[20001];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) d[i]=-1;
	
	int p1,p2;
	for(int i=0; i<m; i++) {
		cin>>p1>>p2;
		
		list[p1].push_back(p2);
		list[p2].push_back(p1);
	}

	queue<int> q;
	q.push(1);
	d[1]=0;
	
	int distance=-1;
	while(!q.empty()) {
		int here=q.front();
		q.pop();
		
		for(auto &next : list[here]) {
			if(d[next]==-1 || d[next]>d[here]+1) {
				d[next]=d[here]+1;
				q.push(next);

				distance=max(distance,d[next]);
			}
		}
	}
	
	vector<int> result;
	for(int i=1; i<=n; i++) {
		if(d[i]==distance) result.push_back(i);
	}

	cout<<result[0]<<" "<<distance<<" "<<result.size();

	return 0;
}

/*
INPUT:
6 7
3 6
4 3
3 2
1 3
1 2
2 4
5 2

OUTPUT:
4 2 3
*/
