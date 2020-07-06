/* BOJ */

#include <iostream>

using namespace std;

int d[1000001];
int v[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    
    d[1]=0;
    for(int i=2; i<=N; i++) {
        d[i]=d[i-1]+1;
        v[i]=i-1;
        
        if(i%3==0) {
            if(d[i]>d[i/3]+1) {
                d[i]=d[i/3]+1;
                v[i]=i/3;
            }
        }
        
        if(i%2==0) {
            if(d[i]>d[i/2]+1) {
                d[i]=d[i/2]+1;
                v[i]=i/2;
            }
        }
    }
    
    cout<<d[N]<<'\n';
    while(1) {
        cout<<N<<" ";
        N=v[N];
        
        if(N==0) break;
    }
    
    return 0;
}
