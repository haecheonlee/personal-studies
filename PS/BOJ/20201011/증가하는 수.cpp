/* reference: https://organize-study.tistory.com/115 */
#include <iostream>

using namespace std;
using ll=long long;

const int MAX=82;

ll cache[MAX][11];

int main() {
    for(int j=1; j<=9; j++) cache[1][j]=1;

    for(int i=2; i<MAX; i++) {
        for(int j=1; j<=9; j++) {
            for(int k=j; k<=9; k++) {
                cache[i][j]+=cache[i-1][k];
            }
        }
    }

    int T;
    cin>>T;

    while(T--) {
        string s;
        cin>>s;

        int L=s.size(), X=s.back()-'0';

        // check if possible
        bool is_possible=true;
        for(int i=0; i<L-1; i++) {
            if(s[i]>s[i+1]) { is_possible=false; break; }
        }

        if(is_possible) {
            ll ans=0;
            for(int i=0; i<L; i++) {
                if(s[i]=='9') ans += cache[L + 1 - i][1];
                else ans += cache[L + 1 - i][1] - cache[L + 1 - i][s[i] - '0' + 1];
            }
            cout<<ans<<'\n';
        } else {
            cout<<-1<<'\n';
        }
    }

    return 0;
}
