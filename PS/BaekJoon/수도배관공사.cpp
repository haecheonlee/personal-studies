/* reference: geunu3751 */

#include <iostream>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5+1;
const int INF=1e9;

int d[MAX];

int main() {
	int D,N;
	cin>>D>>N;
	
	pi a[N];
	for(int i=0; i<N; i++) 
		cin>>a[i].first>>a[i].second;
	
	d[0]=INF;
	for(int i=0; i<N; i++) {
		for(int j=D; j>=0; j--) {
			int K=j+a[i].first;
			if(K>D) continue;
			d[K]=max(min(d[j], a[i].second), d[K]);
		}	
	}
	cout<<d[D];
	
	return 0;
}
