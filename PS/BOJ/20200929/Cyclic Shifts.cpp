#include <iostream>
#include <vector>

using namespace std;

vector<int> preprocessing(string& T) {
	int M=T.size();
	vector<int> pi(M,0);
	
	int j=0;
	for(int i=1; i<M; i++) {
		while(j>0 && T[j]!=T[i]) j=pi[j-1];
		
		if(T[i]==T[j]) {
			pi[i]=j+1;
			j++;
		} else {
			pi[i]=0;
		}
	}
	
	return pi;
}

bool kmp(string& s, string& p, vector<int>& pi) {
	int N=s.size();
	int M=p.size();
	int j=0;
	
	for(int i=0; i<N; i++) {
		while(j>0 && s[i]!=p[j]) j=pi[j-1];
		
		if(s[i]==p[j]) {
			if(j==M-1) return true;
			else j++;
		}
	}
	
	return false;
}

int main() {
	string T,S;
	cin>>T>>S;
	
	for(int i=0; i<S.size(); i++) {
		string x=S.substr(i) + S.substr(0,i);
		vector<int> pi=preprocessing(x);

		if(kmp(T,x,pi)) {
			cout<<"yes";
			return 0;
		}
	}
	
	cout<<"no";
	
	return 0;
}
