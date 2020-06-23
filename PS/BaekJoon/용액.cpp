#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
    
	int i=0, j=N-1;
	int total=2e9+1;
	pair<int,int> ans;
	
	while(i<j) {
		int x=a[i];
		int y=a[j];

		if(abs(x+y)<total) {
			total=abs(x+y);
			ans.first=a[i];
			ans.second=a[j];
		}
		
		if((x+y)<0) i++;
		else j--;
	}

	cout<<ans.first<<" "<<ans.second;

	return 0;
}
