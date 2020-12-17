/*Das Programm wendet das Newton-Raphson-Verfahren auf die Funktion f(x)=(x-3)^2 an.
einen x_Wert einzulesen hat leider nur zu Problemen geführt, daher habe ich alles hart codiert.*/

/*notwendige Bibliotheken werden importiert*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "16_Newton_Raphson_Verfahren_Header.h"


void main()
{   
    /*Eine Variable für den einzusetzenden x Wert wird festgelegt,
    in diesem Fall wird sie auf 5 gesetzt.
    Außerdem wird ein Pointer erstellt der die Adresse der Variable speichert.*/
    double x_Wert = 5;
    double *x_Wert_prt;
    x_Wert_prt = &x_Wert;

    /*In dieser Variable wird das Ergebnis der Funktion f(x)=(x-3)^2 eingespeichert, 
    in die man den x Wert einsetzt. Auch auf diese verweist ein Pointer*/
    double ergebnis_F = 0;
    double *ergebnis_F_prt;
    ergebnis_F_prt = &ergebnis_F;

    /*In dieser Variable wird das Ergebnis der Ableitung f'(x)=2*(x-3) eingespeichert, 
    in die man den x Wert einsetzt. Auch auf diese verweist ein Pointer*/
    double ergebnis_A = 0;
    double *ergebnis_A_prt;
    ergebnis_A_prt = &ergebnis_A;

    /*Die ausgelagerte Funktion in der das Newton Raphson Verfahren angewandt wird wird aufgerufen.
    mit den Pointern der Variablen die in der Main angelgt wurden als Parameter*/
    Newton_Raphson_Verfahren(x_Wert_prt, ergebnis_F_prt, ergebnis_A_prt);

    /*Das Ergebnis das durch die ausgelagerte Funktion ermittelt wurde wird ausgegeben*/
    printf("Eine mögliche Nullstelle der Funktion f(x)=(x-3)^2 liegt bei X = %lf\n", (*x_Wert_prt));
}
