#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

char a[1000001];
char b[100];
bool erased[1000001];

int main() {
	cin>>a>>b;
	
	int n=strlen(a);
	int m=strlen(b);
	
	if(m==1) {
		for(int i=0; i<n; i++) {
			if(a[i]==b[0]) erased[i]=true;
		}
	} else {
		stack<pair<int,int>> s;
		for(int i=0; i<n; i++) {
			if(a[i]==b[0]) {
				s.push(make_pair(i,0));
			} else { 
				if(!s.empty()) {
					auto p=s.top();
					int next_index=p.second+1;
					
					if(a[i]==b[next_index]) {
						s.push(make_pair(i,next_index));
						if(next_index==m-1) {
							for(int k=0; k<m; k++) {
								auto x=s.top();
								erased[x.first]=true;
								s.pop();
							}
						}
					} else {
						while(!s.empty()) s.pop();
					}
				}
			}
		}
	}
	
	bool printed=false;
	for(int i=0; i<n; i++) {
		if(erased[i]) continue;
		cout<<a[i];
		printed=true;
	}
	if(printed==false) cout<<"FRULA";
	
	return 0;
}

/*
INPUT:
mirkovC4nizCC44
C4

OUTPUT:
mirkovniz
*/
