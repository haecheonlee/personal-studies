#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    while(T--) {
        int n;
        cin>>n;
        
        int two=0, three=0;
        while(n%2==0) {
            n/=2;
            two++;
        }
        
        while(n%3==0) {
            n/=3;
            three++;
        }
    
        if(n!=1 || two>three) cout<<"-1\n";
        else if(three==0 && two==0) cout<<"0\n";
        else {
            if(two==0) cout<<three*2<<'\n';
            else cout<<three+(three-two)<<'\n';
        }
    }
    
	return 0;
}
