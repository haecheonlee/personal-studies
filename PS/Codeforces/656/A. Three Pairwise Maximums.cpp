/* Codeforces */

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
        vector<int> a(3);
        for(int i=0; i<3; i++) cin>>a[i];
        sort(a.begin(), a.end());
        
        if(a[1]!=a[2]) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            cout<<a[0]<<" "<<a[0]<<" "<<a[2]<<endl;
        }
    }

	return 0;
}
