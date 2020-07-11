/* Codeforces */
// reference: https://www.youtube.com/watch?v=ZN3nvL4-v74

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    
    while(T--) {
        int N;
        cin>>N;
        
        vector<int> a;
        for(int i=1; i*i<=N; i++) {
            if(N%i==0) {
                a.push_back(i);
                
                if(i!=N/i) a.push_back(N/i);
            }
        }
        
        sort(a.begin(), a.end());
        
        int r=a[1];
        
        int x1=N/r;
        int x2=(r-1)*x1;
        cout<<x1<<" "<<x2<<'\n';
    }

	return 0;
}
