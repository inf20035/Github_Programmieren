/*notwendige Bibliotheken werden importiert*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Das Ergebnis einer Fukntion und der x Wert werden übergeben und in die Formel für nummerische Differenzierung eingesetzt,
um die Ableitung nummerisch zu bestimmen*/
double ableitung_nummerisch(double (*funktion)(double), double x_Wert)
{
    return ( ( ((*funktion)(x_Wert + 0.00000001)) - ((*funktion)(x_Wert)) ) / 0.00000001);
}

/*Das Newton Raphson Verfahren wird entweder mit der nummerischen oder analytischen Ableitung angewendet,
um eine mögliche Nullstelle anzunähern*/
void Newton_Raphson_Verfahren(int Ableitungsart, double (*funktion_prt)(double),
double (*ableitung_analytisch_prt)(double), double (*ableitung_nummerisch_prt)(double (*funktion_prt)(double), double),
double* x_Wert_prt)
{
    /*Eine Variable die das Ergebnis der analytischen oder nummerischen Ableitung speichert*/
    double ableitung = 0;

    /*Wenn das andere Abbruchkriterium nicht vorher eintritt werden 1000 Durchläufe durchgeführt*/
    for(int i = 0; i < 1000; i++)
    { 
        /*entweder wird das Ergebnis der nummerischen oder analytischen Ableitung in die Variable ableitung gespeichert,
        zum ermitteln verwendet man die Funktionen auf die die Funktionspointer verweisen*/
        if(Ableitungsart == 1)
        {
            ableitung = (*ableitung_analytisch_prt)(*x_Wert_prt);
        }
        else
        {
            ableitung = (*ableitung_nummerisch_prt)((*funktion_prt),*x_Wert_prt);  
        }
        
        /*Der Durchlauf wird ausgegeben*/
        printf("%dter Versuch\n", i+1);

        /*Das Newton Raphson Verfahren wird angewendet*/
        *x_Wert_prt = (*x_Wert_prt - ( (*funktion_prt)(*x_Wert_prt) / ableitung ) );

        /*Der vorläufige x Wert des Durchlaufs wird ausgegeben*/
        printf("x = %lf\n",*x_Wert_prt);

        /*Sollte sich der ermittelte x Wert nur noch um 10^(-12) unterscheiden, 
        ist der Unterschied kaum noch relevant und die Schleife wird abgebrochen*/
        if((*funktion_prt)(*x_Wert_prt) < 0.000000000001)
        {
           break;
        }  
    }
}