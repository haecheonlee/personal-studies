#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

map<string,int> cnt;

int main() {
	int n;
	cin>>n;
	
	vector<int> vec(n,0);
	vector<pair<int, int>> vec2;
	
	int total=0,largest=-4001,smallest=4001;
	for(int i=0; i<n; i++) {
		cin>>vec[i];
		
		total+=vec[i];
		string cnt_key=to_string(vec[i]);
		cnt[cnt_key]++;
		largest=max(largest,vec[i]);
		smallest=min(smallest,vec[i]);

		if(vec2.empty()) {
			vec2.push_back({vec[i], cnt[cnt_key]});
		} else {
			int current_value=vec2[vec2.size()-1].first;
			int current_occurence=vec2[vec2.size()-1].second;
			
			if(cnt[cnt_key]>current_occurence) {
				vec2.clear();
				vec2.push_back({vec[i], cnt[cnt_key]});
			} else if(cnt[cnt_key]==current_occurence) {
				vec2.push_back({vec[i], cnt[cnt_key]});
			}
		}
	}
	
	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end(), [](const pair<int,int> &l, const pair<int,int> &r){
		return l.first<r.first;	
	});
	
	cout<<round(((double)total)/n)<<endl;
	cout<<vec[vec.size()/2]<<endl;
	if(vec2.size()==1) cout<<vec2[0].first<<endl;
	else cout<<vec2[1].first<<endl;
	cout<<largest-smallest<<endl;
	
	return 0;
}

/*
boj.kr/2108

INPUT:
5
1
3
8
-2
2

OUTPUT:
2
2
1
10
*/
