#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n,l;
	cin>>n>>l;
	
	unordered_map<int,pair<int,int>> mp;
	for(int i=0; i<n; i++) {
		int d,r,g;
		cin>>d>>r>>g;
		
		mp[d]=make_pair(r,g);
	}
	
	int cur_location=0, time=0;
	while(cur_location<l) {
		if(mp.find(cur_location+1)!=mp.end()) {
			int red=mp[cur_location+1].first;
			int green=mp[cur_location+1].second;
			
			cur_location++;
			int t=time%(red+green);
			if(t>=0 && t<=red) time+=(red-t+1);
			else time++;
		} else {
			cur_location++;
			time++;
		}
	}
	
	cout<<time-1;
	
	return 0;
}

/*
INPUT:
2 10
3 5 5
5 2 2

OUTPUT:
12
*/
