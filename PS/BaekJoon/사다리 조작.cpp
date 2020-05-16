#include <iostream>
#include <vector>

using namespace std;

int garo[100][100];
int w,h;

int start(int c) {
	int r=1;
	
	while(r<=h) {
		if(garo[r][c]==1) c+=1;
		else if(garo[r][c]==2) c-=1;
		r+=1;
	}
	
	return c;
}

bool go() {
	for(int i=1; i<=w; i++) {
		int res=start(i);
		if(res!=i) return false;
	}
	return true;
}

int main() {
	int m;
	cin>>w>>m>>h;
	
	while(m--) {
		int x,y;
		cin>>x>>y;
		
		garo[x][y]=1;
		garo[x][y+1]=2;
	}
	
	vector<pair<int,int>> a;
	for(int i=1; i<=h; i++) {
		for(int j=1; j<=w-1; j++) {
			if(garo[i][j]!=0) continue;
			if(garo[i][j+1]!=0) continue;
			
			a.emplace_back(i,j);
		}
	}
	
	int ans=-1;
	if(go()) {
		cout<<0;
		return 0;
	}

	int len=a.size();
	for(int i=0; i<len; i++) {
		int x1=a[i].first;
		int y1=a[i].second;
		
		if(garo[x1][y1]!=0 || garo[x1][y1+1]!=0) continue;
		garo[x1][y1]=1;
		garo[x1][y1+1]=2;
		
		if(go()) {
			if(ans==-1 || ans>1) ans=1;
		}
		
		for(int j=i+1; j<len; j++) {
			int x2=a[j].first;
			int y2=a[j].second;
			
			if(garo[x2][y2]!=0 || garo[x2][y2+1]!=0) continue;
			garo[x2][y2]=1;
			garo[x2][y2+1]=2;
			
			if(go()) {
				if(ans==-1 || ans>2) ans=2;
			}
			
			for(int k=j+1; k<len; k++) {
				int x3=a[k].first;
				int y3=a[k].second;
				
				if(garo[x3][y3]!=0 || garo[x3][y3+1]!=0) continue;
				garo[x3][y3]=1;
				garo[x3][y3+1]=2;
				
				if(go()) {
					if(ans==-1 || ans>3) ans=3;
				}
				
				garo[x3][y3]=0;
				garo[x3][y3+1]=0;
			}
			garo[x2][y2]=0;
			garo[x2][y2+1]=0;
		}
		garo[x1][y1]=0;
		garo[x1][y1+1]=0;
	}

	cout<<ans;

	return 0;
}
