#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    int A, B, C;
    int result = 0;
    
    while(T != 0) {
        A = T / 300;
        T %= 300;
        B = T / 60;
        T %= 60;
        C = T / 10;
        T %= 10;
        
        if(T != 0) { 
            result = -1;
            break;
        }
    }
    
    if(result == -1) cout << result << endl;
    else cout << A << " " << B << " " << C << endl;
    
    return 0;
}
