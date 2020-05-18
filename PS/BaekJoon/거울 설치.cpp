#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n;
	cin>>n;
	
	vector<string> s(n);
	vector<vector<int>> b(n, vector<int>(n));
	vector<pair<int,int>> v;
	
	int start=-1, end=-1;
	for(int i=0; i<n; i++) {
		cin>>s[i];
		
		for(int j=0; j<n; j++) {
			if(s[i][j]=='#') {
				if(start==-1) start=v.size();
				else end=v.size();
				
				v.push_back(make_pair(i,j));
				b[i][j]=v.size()-1;
			} else if(s[i][j]=='!') {
				v.push_back(make_pair(i,j));
				b[i][j]=v.size()-1;
			}
		}
	}
	
	int m=v.size();
	vector<vector<bool>> a(m, vector<bool>(m, false));
	for(int i=0; i<v.size(); i++) {
		for(int k=0; k<4; k++) {
			int x=v[i].first+dx[k];
			int y=v[i].second+dy[k];
			
			while(0<=x && x<n && 0<=y && y<n) {
				if(s[x][y]=='*') break;
				if(s[x][y]=='!' || s[x][y]=='#') a[i][b[x][y]]=true;
				
				x+=dx[k];
				y+=dy[k];
			}
		}
	}
	
	queue<int> q;
	vector<int> dist(m,-1);
	q.push(start);
	dist[start]=0;
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		for(int i=0; i<m; i++) {
			if(a[now][i] && dist[i]==-1) {
				dist[i]=dist[now]+1;
				q.push(i);
			}
		}
	}
	cout<<dist[end]-1;
	
	return 0;
}
