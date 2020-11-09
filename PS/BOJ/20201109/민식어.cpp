#include <iostream>
#include <map>
#include <algorithm>

#define sz(x) (int)(x.size())

using namespace std;

map<char,int> a;
char b[] = {'a', 'b', 'k', 'd', 'e', 'g', 'h', 'i', 'l', 'm',
           'n', 'z', 'o', 'p', 'r', 's', 't', 'u', 'w', 'y'};

bool cmp(const string& L, const string& R) {
    int l = 0, r = 0;

    while(l < sz(L) && r < sz(R)) {
        char nL = ((L[l] == 'n' && L[l + 1] == 'g') ? 'z' : L[l]);
        char nR = ((R[r] == 'n' && R[r + 1] == 'g') ? 'z' : R[r]);
        
        l += (nL == 'z' ? 2 : 1);
        r += (nR == 'z' ? 2 : 1);
        
        if(nL != nR) return a[nL] < a[nR];
    }
    
    return sz(L) <= sz(R);
}
           
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 20; i++) a[b[i]] = i; 
    
    int N;
    cin >> N;

    string s[N];
    for(int i = 0; i < N; i++) cin >> s[i];
    sort(s, s + N, cmp);

    for(int i = 0; i < N; i++) cout << s[i] << '\n';
    
    return 0;
}
