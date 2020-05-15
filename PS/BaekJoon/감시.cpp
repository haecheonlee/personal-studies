#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void check(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y, int dir) {
	int n=a.size();
	int m=a[0].size();
	int i=x;
	int j=y;
	
	while(0<=i && i<n && 0<=j && j<m) {
		if(a[i][j]==6) break;
		b[i][j]=a[x][y];
		
		i+=dx[dir];
		j+=dy[dir];
	}
}

int go(vector<vector<int>> &a, vector<tuple<int,int,int>> &cctv, int index, vector<int> dirs) {
	if(cctv.size()==index) {
		vector<vector<int>> b(a);
		
		for(int i=0; i<cctv.size(); i++) {
			int what,x,y;
			tie(what,x,y)=cctv[i];
			
			if(what==1) {
				check(a,b,x,y,dirs[i]);
			} else if(what==2) {
				check(a,b,x,y,dirs[i]);
				check(a,b,x,y,(dirs[i]+2)%4);
			} else if(what==3) {
				check(a,b,x,y,dirs[i]);
				check(a,b,x,y,(dirs[i]+1)%4);
			} else if(what==4) {
				check(a,b,x,y,dirs[i]);
				check(a,b,x,y,(dirs[i]+1)%4);
				check(a,b,x,y,(dirs[i]+2)%4);
			} else if(what==5) {
				check(a,b,x,y,dirs[i]);
				check(a,b,x,y,(dirs[i]+1)%4);
				check(a,b,x,y,(dirs[i]+2)%4);
				check(a,b,x,y,(dirs[i]+3)%4);
			}
		}
		
		int cnt=0;
		int n=a.size();
		int m=a[0].size();
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(b[i][j]==0) cnt+=1;
			}
		}
		
		return cnt;
	}
	
	int ans=100;
	for(int i=0; i<4; i++) {
		dirs[index]=i;
		int temp=go(a,cctv,index+1,dirs);
		if(ans>temp) ans=temp;
	}
	return ans;
}

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> a(n, vector<int>(m));
	vector<tuple<int,int,int>> cctv;
	vector<int> dirs;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
			
			// cctv
			if(a[i][j]>=1 && a[i][j]<=5) {
				cctv.emplace_back(a[i][j], i, j);
				dirs.push_back(0);
			}
		}
	}
	
	cout<<go(a, cctv, 0, dirs);

	return 0;
}
