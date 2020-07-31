#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());

	int ans=0;
	for(int i=0; i<N-2; i++) {
		for(int j=i+1; j<N-1; j++) {
			for(int k=j+1; k<N; k++) {
				int throw1=a[j]-a[i];
				int throw2=a[k]-a[j];
				
				if(throw1<=throw2 && throw1*2>=throw2) ans++;
			}
		}
	}
	cout<<ans;

	return 0;
}
