#include <iostream>

using namespace std;

long long calc(long long a, long long b, long long c) {
    return abs(a-b)+abs(a-c)+abs(b-c);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin>>q;
    
    while(q--) {
        long long a,b,c;
        cin>>a>>b>>c;
        
        int p[3]={-1,0,1};

        long long ans=-1;        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    int _a=a+p[i];
                    int _b=b+p[j];
                    int _c=c+p[k];
                    
                    long long sum=calc(_a, _b, _c);
                    if(ans==-1 || ans>sum) ans=sum;
                }
            }
        }
        cout<<ans<<'\n';
    }
    
	return 0;
}
