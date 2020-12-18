/*notwendige Bibliotheken werden importiert*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*X wird in die Funktion f(x)=(x-3)^2 eingesetzt*/
double funktion(double x_Wert)
{
    return ((x_Wert - 3) * (x_Wert - 3));
}

/*X wird in die Ableitung f'(x)=2*(x-3) eingesetzt*/
double ableitung_analytisch(double x_Wert)
{
    return (2 * (x_Wert - 3));
}


