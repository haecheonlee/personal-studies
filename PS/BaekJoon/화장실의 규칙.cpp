#include <iostream>
#include <vector>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5+1;

vector<pair<pi,pi>> a[MAX];

int main() {
	int N,M,K;
	cin>>N>>M>>K;
	
	for(int i=0; i<N; i++) {
		int D,H;
		cin>>D>>H;
		
		a[i%M].push_back({{D,H}, {i,i%M}});
	}
	
	// min value of D, H of people in front of Deca
	int ranking=1e9, hurry=1e9, pos=-1, how_many=0;
	for(int i=0; i<a[K%M].size(); i++) {
		int r=a[K%M][i].first.first;
		int h=a[K%M][i].first.second;
		int order=a[K%M][i].second.first;
		int p=a[K%M][i].second.second;
		
		if(ranking>r || (ranking==r && hurry>h) || (ranking==r && hurry==h && pos<p)) {
			ranking=r;
			hurry=h;
			pos=p;
		}
			
		if(order==K) break;
		how_many++;
	}
	
	int ans=0;
	for(int i=0; i<M; i++) {
		if(K%M!=i){
			for(auto& y : a[i]) {
				int r=y.first.first;
				int h=y.first.second;
				int p=y.second.second;
				
				if(r>ranking || (r==ranking && h>hurry) || (r==ranking && h==hurry && p<pos)) ans++;
				else break;
			}
		}
	}

	ans+=how_many;
	cout<<ans;

	return 0;
}
