#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;

vector<pair<int,pii>> a;

int main() {
	int N;
	cin>>N;

	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second.first>>a[i].second.second;
	a.push_back(make_pair(0, make_pair(0, 10000))); 
	sort(a.begin(), a.end());

	int ans=0;
	for(int i=1; i<=N; i++) {
		int H=a[i].first, L=a[i].second.first, R=a[i].second.second;
		int sL=-1, sR=-1;

		for(int j=i-1; j>=0 && (sL==-1 || sR==-1); j--) {
			int nH=a[j].first;
			int nL=a[j].second.first;
			int nR=a[j].second.second;

			if(H==nH) continue;
			if(sL==-1 && nL <= L && L < nR) sL=j, ans+=(H-nH);
			if(sR==-1 && nL < R && R <= nR) sR=j, ans+=(H-nH);
		}
	} 
	cout<<ans;

	return 0;
}
