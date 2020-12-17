/*notwendige Bibliotheken werden importiert*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Die Funktion verlangt die Pointer der Variablen aus der Main um in diese direkt schreiben zu können*/
void Newton_Raphson_Verfahren(double *x_Wert_prt, double *ergebnis_F_prt, double *ergebnis_A_prt)
{
    for(int i = 0; i < 1000; i++)/*Es werden 1000 Durchläufe gestartet außer das andere Abbruchkriterium tritt in Kraft*/
    { 
        /*Es wird brechnet was herrauskommt wenn man x in die Funktion f(x)=(x-3)^2 einsetzt*/
        *ergebnis_F_prt = ((*x_Wert_prt - 3) * (*x_Wert_prt - 3));
        /*Es wird brechnet was herrauskommt wenn man x in die Ableitung f'(x)=2*(x-3) einsetzt*/
        *ergebnis_A_prt = (2 * (*x_Wert_prt - 3));
        /*Das Newton Raphson Verfahren wird angewandt*/
        *x_Wert_prt = (*x_Wert_prt - (*ergebnis_F_prt / *ergebnis_A_prt));
        /*Ein weiteres Abruchskriterium bricht die Schleife ab, 
        wenn sich durch die Anwendung des Verfahrens kaum noch ein Unterschied ermitteln lässt*/
        if(*ergebnis_F_prt < 0.0000000000001)
        {
            break;
        }
   }
}