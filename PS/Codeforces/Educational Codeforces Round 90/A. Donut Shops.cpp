#include <iostream>
 
using namespace std;
 
int main() {    
    int t;
    cin>>t;
    
    while(t--) {
        long long a,b,c;
        cin>>a>>b>>c;
        
        if(a<c) cout<<1<<' ';
        else cout<<-1<<' '; 
            
        if(c<a*b) cout<<b;
        else cout<<-1;
        
        cout<<endl;
    }
    
	return 0;
}
