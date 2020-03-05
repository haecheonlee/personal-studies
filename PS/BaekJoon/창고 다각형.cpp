#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<pair<int,int>> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i].first>>vec[i].second;
	sort(vec.begin(), vec.end(), [](const pair<int,int> &l, const pair<int,int> &r) {
		return l.first<r.first;
	});	
	
	int result=0;
	for(int i=0; i<n; i++) {
		int index=-1;
		int pos=i+1;
		
		for(int j=i+1; j<n; j++) {
			if(vec[j].second>=vec[i].second) {
				int sum=(vec[j].first-vec[i].first)*vec[i].second;
				result+=sum;
				index=j-1;
				break;
			}
			
			if(vec[pos].second<vec[j].second) pos=j;
		}
		
		if(index!=-1) {
			i=index;
		}
		else {
			result+=vec[i].second;
			result+=(vec[pos].first-vec[i].first)*vec[pos].second-vec[pos].second;
			i=pos-1;
		}
	}

	cout<<result;
	
	return 0;
}

/*
boj.kr/2304

INPUT:
7
2 4
11 4
15 8
4 6
5 3
8 10
13 6

OUTPUT:
98
*/
