#include <iostream>
#include <vector>

using namespace std;

struct Term {
	int num;
	int op;
};

int main() {
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	vector<Term> a(n);
	for(int i=0; i<n; i++) {
		if(i%2==0) a[i]={s[i]-'0',0};
		else {
			int op=1;
			
			if(s[i]=='-') op=2;
			else if(s[i]=='*') op=3;
			
			a[i]={0,op};
		}
	}

	int m=(n-1)/2;
	int ans=-2e9;
	
	for(int i=0; i<(1<<m); i++) {
		bool ok=true;
		
		for(int j=0; j<m-1; j++) {
			if((i&(1<<j))>0 && (i&(1<<(j+1)))>0) ok=false;
		}
		
		if(!ok) continue;
		vector<Term> b(a);
		
		for(int j=0; j<m; j++) {
			if((i&(1<<j))>0) {
				int k=2*j+1;
				
				if(b[k].op==1) {
					b[k-1].num+=b[k+1].num;
					b[k+1].num=0;
				} else if(b[k].op==2) {
					b[k-1].num-=b[k+1].num;
					b[k].op=1;
					b[k+1].num=0;
				} else if(b[k].op==3) {
					b[k-1].num*=b[k+1].num;
					b[k].op=1;
					b[k+1].num=0;
				}
			}
		}
		
		int res=b[0].num;
		for(int j=0; j<m; j++) {
			int k=2*j+1;
			
			if(b[k].op==1) res+=b[k+1].num;
			else if(b[k].op==2) res-=b[k+1].num;
			else if(b[k].op==3) res*=b[k+1].num;
		}
		
		if(ans<res) ans=res;
	}

	cout<<ans;

	return 0;
}

/*
INPUT:
9
3+8*7-9*2

OUTPUT:
136
*/
