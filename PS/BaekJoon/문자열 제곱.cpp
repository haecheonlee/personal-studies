#include <iostream>
#include <vector>

using namespace std;

vector<int> preprocessing(string p) {
	int m=p.size();
	
	vector<int> pi(m,0);
	int j=0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i]!=p[j]) j=pi[j-1];
		
		if(p[i]==p[j]) pi[i]=++j;
		else pi[i]=0;
	}
	
	return pi;
}

int main() {
	while(1) {
		string s;
		cin>>s;
		
		if(s==".") break;
		vector<int> pi=preprocessing(s);
		
		int n=s.size();
		if(pi[n-1]==0 || pi[n-1]%(n-pi[n-1])) cout<<1<<'\n';
		else cout<<(n/(n-pi[n-1]))<<'\n';
	}
	
	return 0;
}
