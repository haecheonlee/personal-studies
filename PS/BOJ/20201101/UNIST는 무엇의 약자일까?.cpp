#include <iostream>
#include <cstring>

#define sz(x) (int)x.size()

using namespace std;

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;

int N;
string a[MAX];
int d[MAX][6];
string result = "UNIST";

int go(int now, int L, string& s) {   
    // base case
    if(L >= 5 || now >= N) {
        if(L == 5) {
            if(s == result) return 1;
            else return 0;
        } else {
            return 0;
        }
    }
    
    int& ret = d[now][L];
    if(ret != -1) return ret;
    ret = 0;

    string ns = s;
    for(int i = -1; i < sz(a[now]) && L + i < sz(result); i++) {
        if(i == -1) {
            // skip a[now]
            ret += go(now + 1, L, s) % MOD;
            ret %= MOD;
        } else {            
            if(a[now][i] == result[L + i]) {
                s += result.substr(L, i + 1);
                
                ret += go(now + 1, L + i + 1, s) % MOD;
                ret %= MOD;
                
                s = ns;
            } else {
                break;
            }
        }
    }
    
    return ret;
}

int main() {
    cin>>N;
    for(int i = 0; i < N; i++) cin >> a[i];    
    
    memset(d, -1, sizeof(d));
    string s = "";    
    cout<<go(0, 0, s);
    
	return 0;
}
