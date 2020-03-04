#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t,n;
	cin>>t;
	
	string s;
	int l;
	while(t--) {
		cin>>n;
		
		vector<pair<string,int>> vec;
		while(n--) {
			cin>>s>>l;
			vec.push_back({s,l});
		}
		
		sort(vec.begin(), vec.end(), [](const pair<string,int> &l, const pair<string,int> &r){
			return l.second>r.second;	
		});
		
		cout<<vec[0].first<<'\n';
	}

	return 0;
}

/*
boj.kr/11557

INPUT:
2
3
Yonsei 10
Korea 10000000
Ewha 20
2
Yonsei 1
Korea 10000000

OUTPUT:
Korea
Korea
*/
