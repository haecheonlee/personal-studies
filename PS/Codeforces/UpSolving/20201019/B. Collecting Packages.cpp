#include <iostream>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		pii p[N];
		for(int i=0; i<N; i++) cin>>p[i].first>>p[i].second;
		sort(p, p+N);
		
		int X=0, Y=0;	// X: R(RIGHT), Y: U(UP)
		string path="";
		bool is_possible=true;
		
		for(int i=0; i<N; i++) {
			if(X<=p[i].first && Y<=p[i].second) {
				int dX=p[i].first-X;
				int dY=p[i].second-Y;
				X=p[i].first, Y=p[i].second;
				
				while(dX--) path+="R";
				while(dY--) path+="U";
			} else {
				is_possible=false;
				break;
			}
		}
		
		if(is_possible) cout<<"YES"<<'\n'<<path<<'\n';
		else cout<<"NO\n";
	}

	return 0;
}
