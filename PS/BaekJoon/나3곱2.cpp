#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(const pair<int,long long> &l, const pair<int, long long> &r) {
	if(l.first>r.first) return true;
	else if(l.first==r.first) return l.second<r.second;
	return false;
}

int main() {
	vector<pair<int, long long>> list;
	
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		long long a;
        cin>>a;
		list.push_back(make_pair(0,a));
        
        while(a%3==0) {
			a/=3;
			list[i].first++;
		}

	}
		
	sort(list.begin(), list.end(), sorting);
	
	for(int i=0; i<n; i++) cout<<list[i].second<<" ";
	
	return 0;
}

/*
INPUT:
6
4 8 6 3 12 9

OUTPUT:
9 3 6 12 4 8
*/
