#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p[101];
int l[101];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		int x;
		cin>>x>>l[i];
		
		p[i].resize(x);
		for(int j=0; j<x; j++) cin>>p[i][j];
	}
	
	vector<int> credit;
	for(int i=0; i<N; i++) {
		sort(p[i].rbegin(), p[i].rend());
		if(p[i].size()>=l[i]) credit.push_back(p[i][l[i]-1]);
		else credit.push_back(1);
	}
	sort(credit.begin(), credit.end());
	
	int sum=0, ans=0;
	for(int i=0; i<credit.size(); i++) {
		if(sum+credit[i]>M) {
			cout<<i;
			return 0;
		}
		sum+=credit[i];
	}
	cout<<credit.size();
	
	return 0;
}
