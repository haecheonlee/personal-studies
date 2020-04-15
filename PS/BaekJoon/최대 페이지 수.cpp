#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,x,p;
vector<pair<int,int>> list;
int ans=-1;

void go(int index, int day, int sum) {
	if(day<=n) ans=max(ans,sum);
	if(day>n || index>=list.size()) return;
	
	go(index+1,day+list[index].first,sum+list[index].second);
	go(index+1,day,sum);
}

int main() {
	cin>>n>>m;

	for(int i=0; i<m; i++) {
		cin>>x>>p;
		list.push_back(make_pair(x,p));
	}	
	
	sort(list.begin(),list.end());
	go(0,0,0);
	
	cout<<ans;
	
	return 0;
}

/*
INPUT:
7 7
3 10
5 20
1 10
1 20
2 15
4 40
2 200

OUTPUT:
260
*/
