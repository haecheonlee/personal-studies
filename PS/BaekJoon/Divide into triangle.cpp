#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<tuple<int,int,int>> a;
	for(int i=1; i<=N*3; i++) {
		int x,y;
		cin>>x>>y;
		
		a.push_back(make_tuple(x,y,i));
	}
	
	sort(a.begin(), a.end());
	for(int i=0; i<N; i++) {
		for(int j=i*3; j<i*3+3; j++) {
			int x,y,index;
			tie(x,y,index)=a[j];
			
			cout<<index<<" ";
		}
		cout<<'\n';
	}

	return 0;
}
