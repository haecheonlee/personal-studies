#include <iostream>
#include <vector>

using namespace std;

int cnt[100001];

vector<int> preprocessing(string &p) {
	int m=p.size();
	
	vector<int> pi(m);
	pi[0]=0;
	
	int j=0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i]!=p[j]) j=pi[j-1];
		
		if(p[i]==p[j]) {
			pi[i]=j+1;
			j++;
		} else {
			pi[i]=0;
		}
	}
	
	return pi;
}

int main() {
	string s;
	cin>>s;
	
	int n=s.size();
	vector<int> pi=preprocessing(s);

	for(int i=0; i<n; i++) cnt[pi[i]]++;
	for(int i=n; i>0; i--) cnt[pi[i-1]]+=cnt[i];

	vector<pair<int,int>> ans;
	for(int i=n; i>0; i=pi[i-1]) {
		ans.push_back(make_pair(i, cnt[i]+1));
	}
	
	cout<<ans.size()<<'\n';
	for(int i=ans.size()-1; i>=0; i--) {
		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	}
	
	return 0;
}
