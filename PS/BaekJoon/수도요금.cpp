#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D, P;
    cin>>A>>B>>C>>D>>P;
    
    int X_result = A * P;
    int Y_result = B + ((P >= C) ? ((P - C) * D) : 0);
    
    if(X_result < Y_result) cout<<X_result;
    else cout<<Y_result;

    return 0;
}

/*
boj.kr/10707

INPUT:
8
300
100
10
250

OUTPUT:
1800

*/
