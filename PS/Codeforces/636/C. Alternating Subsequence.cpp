/* Codeforces */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        vector<long long> a;
        
        long long x;
        for(int i=0; i<n; i++) {
            cin>>x;
            
            if(a.empty()) a.push_back(x);
            else {
                // check if the last index of vector is positvie
                int l= a.size()-1;
                
                if(x>0) {
                    if(a[l]<0) {
                        a.push_back(x);
                    } else {
                        if(x>a[l]) a[l]=x;
                    }
                } else {
                    if(a[l]>0) {
                        a.push_back(x);
                    } else {
                        if(x>a[l]) a[l]=x;
                    }                
                }
            }
        }
        
        long long sum=0;
        for(auto x : a) sum+=x;
        cout<<sum<<'\n';
    }

	return 0;
}
