#include <iostream>
#include "Complex.h"
using namespace std;
#define TEST1
#define TEST2
#define TEST3

int main()
{
    Complex c1( 3, 4 );
    Complex c2( 1 );
    Complex c3;
    cout << "Podaj trzecia liczbe zespolona: ";
    cin >> c3;
    Complex c4( c3 );
#ifdef TEST1
    cout << " c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << " c4 = " << c4 << endl;
    cout << "c1 + c3 =  " << c1 + c3 << endl;
    cout << "c1 - c3 =  " << c1 - c3 << endl;
    cout << "c1 * c3 =  " << c1 * c3 << endl;
#endif 
#ifdef TEST3
    cout << "c1 / c3 =  " << c1 / c3 << endl;
    cout << " - c1 = " << -c1 << endl;
#endif
#ifdef TEST2
    double modul = c1.absolute();
    cout << "Modul c1 = " << modul << endl;
    Complex sprzezenie = conjugate( c1 );
    cout << "Sprzezenie c1 = " << sprzezenie << endl; 
    cout << "Does c1 equal c3? " << ( c1 == c3 ) << endl;
    cout << "Does c3 equal c4? " << ( c4 == c3 ) << endl;
#endif 
    cout << "Konwersja c1 na double: (double)c1 =  " << ( double )c1 << endl;
    return 0;
}