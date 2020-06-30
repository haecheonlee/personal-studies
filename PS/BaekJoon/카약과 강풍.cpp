#include <iostream>

using namespace std;

bool broken[12];
bool extra[12];

int main() {
	int N,S,R;
	cin>>N>>S>>R;
	
	for(int i=0; i<S; i++) {
		int x;
		cin>>x;
		
		broken[x]=true;
	}
	
	for(int i=0; i<R; i++) {
		int x;
		cin>>x;
		
		extra[x]=true;
	}
	
	for(int i=1; i<=N; i++) {
		if(broken[i]) {
			if(extra[i-1]) { 
				broken[i]=false;
				extra[i-1]=false;
				continue;
			}
			
			if(extra[i+1]) {
				broken[i]=false;
				extra[i+1]=false;
				continue;
			}
		}
	}
	
	int ans=0;
	for(int i=1; i<=N; i++) {
		if(broken[i]) ans++;
	}
	cout<<ans;
	
	return 0;
}
