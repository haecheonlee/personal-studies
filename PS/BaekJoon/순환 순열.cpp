#include <iostream>
#include <vector>

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

int kmp(string &s, string &p) {
	vector<int> fail=preprocessing(p);
	
	int n=s.size();
	int m=p.size();
	int j=0, cnt=0;
	
	for(int i=0; i<n-1; i++) {
		while(j>0 && s[i]!=p[j]) j=fail[j-1];
		
		if(s[i]==p[j]) {
			if(j==m-1) {
				cnt++;
				j=fail[j];
			} else {
				j++;
			}
		}
	}
	
	return cnt;
}

int main() {
	string a, b;
	cin>>a>>b;

	b+=b;
	
	cout<<kmp(b,a);

	return 0;
}
