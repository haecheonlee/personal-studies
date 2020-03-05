#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vec;
map<int,int> dict;
map<int,int> dict2;

int main() {
	int n,c,num;
	cin>>n>>c;
	
	for(int i=0; i<n; i++) {
		cin>>num;
		
		dict[num]++;
		if(dict2.find(num)==dict2.end()) dict2[num]=i+1;
	}
	
	for(auto it : dict) {
		vec.push_back({it.first, it.second});
	}
	
	sort(vec.begin(), vec.end(), [](const pair<int,int> &l, const pair<int,int> &r) {
		if(l.second==r.second) return dict2[l.first]<dict2[r.first];
		return l.second>r.second;
	});
	
	for(int i=0; i<vec.size(); i++) {
		
		for(int j=0; j<vec[i].second; j++) {
			cout<<vec[i].first<<" ";
		}
	}
	
	return 0;
}

/*
boj.kr/2910

INPUT:
5 2
2 1 2 1 2

OUTPUT:
2 2 2 1 1
*/
