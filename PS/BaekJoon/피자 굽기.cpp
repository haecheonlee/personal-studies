#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int N,M;
	cin>>N>>M;
	
	vector<int> a(N);
	vector<int> b(N);		// to check max allowed size of each row
	for(int i=0; i<N; i++) {
		cin>>a[i];
		if(i==0) b[i]=a[i];
		else b[i]=min(b[i-1], a[i]);
	}
	
	int j=N-1;
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		        
		while(1) {
			if(b[j]>=x) {
				if(i!=M-1) j--;
				break;
			}
			
			j--;
            
      if(j<0) {
        cout<<0;
        return 0;
      }
		}
	}
	
	cout<<j+1;

	return 0;
}
