#include <iostream>

using namespace std;

int N;
int a[11][11];
bool check[11][11];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool is_possible(int x, int y) {
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(nx>=0 && nx<N && ny>=0 && ny<N) {
			if(check[nx][ny]) return false;
		} else {
			return false;
		}
	}
	
	return true;
}

int update(int x, int y, bool status) {
	int sum=a[x][y];
	
	check[x][y]=status;
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		check[nx][ny]=status;
		sum+=a[nx][ny];
	}
	
	return sum;
}

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}

	int ans=1e9;
	int len=N*N;
	for(int i=0; i<len; i++) {
		int ix=i/N, iy=i%N, iSum=0;
		if(is_possible(ix,iy)) iSum=update(ix,iy,true);
		else continue;
		
		for(int j=0; j<len; j++) {
			if(i==j) continue;
			
			int jx=j/N, jy=j%N, jSum=0;
			if(is_possible(jx,jy)) jSum=update(jx,jy,true);
			else continue;
			
			for(int k=0; k<len; k++) {
				if(i==k || k==j) continue;
				
				int kx=k/N, ky=k%N, kSum=0;
				if(is_possible(kx,ky)) kSum=update(kx,ky,true);
				else continue;
				
				ans=min(ans,iSum+jSum+kSum);
				update(kx,ky,false);
			}
			update(jx,jy,false);
		}
		update(ix,iy,false);
	}
	
	cout<<ans;

	return 0;
}
