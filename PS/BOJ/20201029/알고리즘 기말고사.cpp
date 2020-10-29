#include <iostream>

using namespace std;

int main() {
	  ios_base::sync_with_stdio(false);
	  cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    int a[N+1];
	  for(int i=1; i<=N; i++) {
        int x;
		    cin>>x;
        
        a[x] = i;
    }
    
    for(int i=1; i<=N; i++) cout<<i - a[i]<<'\n';

	  return 0;
}
