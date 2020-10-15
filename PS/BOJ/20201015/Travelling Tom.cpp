#include <iostream>

using namespace std;

const int MAX=2e2+1;
const int INF=1e9;

int a[MAX][MAX];
int d[MAX][MAX];
int p[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		for(int i=0; i<N; i++) cin>>p[i];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				cin>>a[i][j];
				
				if(a[i][j]==-1) d[i][j]=INF;
				else d[i][j]=a[i][j];
			}
		}
		
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				if(d[i][k]==INF) continue;
				for(int j=0; j<N; j++) {
					if(d[k][j]==INF) continue;
					d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
		
		int ans=0;
		bool is_possible=true;
		for(int i=0; i<N-1; i++) {
			if(d[p[i]][p[i+1]]==INF) {
				is_possible=false;
				break;
			}

			ans+=d[p[i]][p[i+1]];
		}
        
		if(d[p[N-1]][p[0]]==INF) is_possible=false;
		else ans+=d[p[N-1]][p[0]];
		
		if(is_possible) cout<<ans<<'\n';
		else cout<<"impossible\n";
	}

	return 0;
}
