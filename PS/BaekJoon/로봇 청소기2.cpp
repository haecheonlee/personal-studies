
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<vector<int>> bfs(vector<string> &a, int sx, int sy) {
	int n=a.size();
	int m=a[0].size();
	
	vector<vector<int>> dist(n, vector<int>(m,-1));
	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	dist[sx][sy]=0;
	
	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(dist[nx][ny]==-1 && a[nx][ny]!='x') {
					dist[nx][ny]=dist[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	return dist;
}


int main() {
	while(true) {
		int n,m;
		cin>>m>>n;
		if(n==0 && m==0) break;
		
		vector<string> a(n);
		for(int i=0;i <n; i++) cin>>a[i];
		
		vector<pair<int,int>> b(1);
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='o') b[0]=make_pair(i,j);
				else if(a[i][j]=='*') b.push_back(make_pair(i,j));
			}
		}
		
		int l=b.size();
		vector<vector<int>> d(l, vector<int>(l));
		bool ok=true;
		for(int i=0; i<l; i++) {
			auto dist=bfs(a, b[i].first, b[i].second);
			for(int j=0; j<l; j++) {
				d[i][j]=dist[b[j].first][b[j].second];
				if(d[i][j]==-1) ok=false;
			}
		}
		
		if(ok==false) {
			cout<<-1<<'\n';
			continue;
		}
		
		vector<int> p(l-1);
		for(int i=0; i<l-1; i++) p[i]=i+1;
		
		int ans=-1;
		do {
			int now=d[0][p[0]];
			for(int i=0; i<l-2; i++) {
				now+=d[p[i]][p[i+1]];
			}
			
			if(ans==-1 || ans>now) ans=now;
		} while(next_permutation(p.begin(), p.end()));
		cout<<ans<<'\n';
	}

	return 0;
}
