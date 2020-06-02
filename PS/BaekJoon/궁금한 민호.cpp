#include <iostream>

using namespace std;

int d[20][20];
bool unused[20][20];

int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>d[i][j];
	}
	
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			if(i==k) continue;
			for(int j=0; j<n; j++) {
				if(i==j || k==j) continue;
				
				if(d[i][j]>d[i][k]+d[k][j]) {
					cout<<-1<<'\n';
					return 0;
				}
				
				if(d[i][j]==d[i][k]+d[k][j]) unused[i][j]=true;
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(unused[i][j]==false) ans+=d[i][j];
		}
	}
	ans/=2;
	cout<<ans;
	
	return 0;
}
