/* reference: portableangel's comments */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e6+1;

int d[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	int N;
	cin>>N;
	
	memset(d,-1,sizeof(d));
  int mx=0;
	for(int i=1; i<=N; i++) {
		int x;
		cin>>x;
		
		// previous number => x-1
		if(d[x-1]!=-1) d[x]=d[x-1]+1;
		else d[x]=1;
        
    mx=max(mx, d[x]);
	}	
	cout<<N-mx;
	
	return 0;
}
