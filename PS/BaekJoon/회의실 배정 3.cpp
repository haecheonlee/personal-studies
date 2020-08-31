#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5;

vector<pair<pi,int>> a;
int d[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int s,e,p;
		cin>>s>>e>>p;
		
		a.push_back({{s,e}, p});
	}
	sort(a.begin(), a.end());
	
	if(N>=1) d[0]=a[0].second;
	if(N>=2) d[1]=max(a[0].second, a[1].second);
	if(N>=3) d[2]=max(d[1], d[0]+a[2].second);
	
	for(int i=3; i<N; i++) {
		d[i]=max({d[i-1], d[i-2]+a[i].second, d[i-3]+a[i].second});
	}
	cout<<d[N-1];
	
	return 0;
}
