#ifdef __MSDOS__
    #include <iostream.h>
    #include <stdlib.h>
    #include <math.h>
    #include <cmath>
#else
    #include <iostream>
    #include <cstdlib>
    #include <cmath>
    using namespace std;
#endif

double funcion (double x)
{
    return cos (x) - x * x ;
}

double derivada (double x)
{
    return -sin (x) - 2.0 * x ;
}

int main (void)
{
    double x, x_1, err;
    int i=0;
    cout << "M\202todo de Newton-Raphson, C\240lculo de la funci\242n: cos(x) - x2 " << endl << endl;
    cout << "Ingrese el valor inicial de x0: ";
    cin >> x;
    cout << endl;
    do {
        x_1 = x;
        x = x - funcion (x) / derivada (x);
        err = fabs ((x - x_1) / x);
        cout << "x" << i << " = " << x << "\t\terror = " << err << endl;
        i++;
    } while (x!=x_1 && i<100);
    if (i==100)
        cout << endl << "La soluci\242n no es convergente." << endl << endl;
    else
        cout << endl << "La soluci\242n es " <<abs(x)<< endl << endl;
    system ("pause");
    return EXIT_SUCCESS;
}

