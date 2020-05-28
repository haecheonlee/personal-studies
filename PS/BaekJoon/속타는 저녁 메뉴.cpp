#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preprocessing(string &p) {
	int m=p.size();
	
	vector<int> fail(m);
	fail[0]=0;
	
	int j=0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i]!=p[j]) j=fail[j-1];
		
		if(p[i]==p[j]) {
			fail[i]=j+1;
			j++;
		} else {
			fail[i]=0;
		}
	}
	
	return fail;
}

int main() {
	int n;
	scanf("%d\n", &n);

	string s,p;
	getline(cin,s);
	getline(cin,p);

	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	p.erase(remove(p.begin(), p.end(), ' '), p.end());

	s=s+s;	// make it double
	vector<int> fail=preprocessing(p);

	// kmp
	n=n*2;
	int m=p.size();
	int j=0;
	
	vector<int> pos;
	for(int i=0; i<n-1; i++) {
		while(j>0 && s[i]!=p[j]) j=fail[j-1];
		
		if(s[i]==p[j]) {
			if(j==m-1) {
				pos.push_back(i-j);	// get position of start index
				j=fail[j];
			} else {
				j++;
			}
		}
	}

	int cnt=0;
	for(int i=0; i<pos.size(); i++) {
		if(i==0) cnt+=m;
		else cnt+=min((pos[i]+m)-(pos[i-1]+m), m);
	}
	cout<<"1/"<<n-cnt;

	return 0;
}
