#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int list[10];
int cnt[10] {0};

void show(int index, int start, int n, int m) {
	if(index==m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=start; i<n; i++) {
		if(cnt[v[i]]>0) {
			list[index]=v[i];
			cnt[v[i]]--;
			show(index+1,i,n,m);
			cnt[v[i]]++;
		}
	}
}

int main() {
	int n,m,num;
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		cin>>num;
		if(find(v.begin(), v.end(), num) == v.end()) v.push_back(num);
		cnt[num]++;
	}
	
	sort(v.begin(), v.end());
	
	show(0,0,n,m);
	
	return 0;
}

/*
boj.kr/15664

INPUT:
4 2
9 7 9 1

OUTPUT:
1 7
1 9
7 9
9 9
*/
