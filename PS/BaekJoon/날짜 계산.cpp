#include <iostream>

using namespace std;

int main()
{
    int E_year = 15, S_year = 28, M_year = 19;
    int E, S, M;
    
    cin>>E>>S>>M;
    
    int year = 1;
    while(true) {
        int E_remainder = year%E_year;
        int S_remainder = year%S_year;
        int M_remainder = year%M_year;
        
        bool E_check = (E_remainder == E) || (E_remainder == 0 && E == E_year);
        bool S_check = (S_remainder == S) || (S_remainder == 0 && S == S_year);
        bool M_check = (M_remainder == M) || (M_remainder == 0 && M == M_year);
        
        if(E_check && S_check && M_check) {
            cout<<year<<endl;
            break;
        } else {
            year++;
        }
    }

    return 0;
}

/*
boj.kr/1476

INPUT: 
15 28 19

OUTPUT:
7980
*/
