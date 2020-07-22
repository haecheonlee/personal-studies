#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	
	int ans[N];
	int t=1, index=0, finished=0;
	while(finished<N) {
		if(a[index]!=0) {
			a[index]--;
			if(a[index]==0) {
				ans[index]=t;
				finished++;
			}
			t++;
		}
		
		index++;
		if(index==N) index=0;
	}
	
	for(int i=0; i<N; i++) cout<<ans[i]<<" ";
	
	return 0;
}
