#include <iostream>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int d[10001];

int main() {
	while(1) {
		memset(d,0,sizeof(d));
		
		int N;
		double m;
		cin>>N>>m;
		
		int M=(int)(m*100+0.5);
		if(N==0 && M==0) break;
		
		while(N--) {
			int C;
			double p;
			cin>>C>>p;
			
			int P=(int)(p*100+0.5);
			for(int i=0; i<=M; i++) {
				if(i+P>M) break;
				d[i+P]=max(d[i+P], d[i]+C);
			}
		}
		
		cout<<d[M]<<'\n';
	}

	return 0;
}
