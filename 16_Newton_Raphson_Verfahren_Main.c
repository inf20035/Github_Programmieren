/*notwendige Bibliotheken werden importiert*/
#include <stdio.h>
#include <stdlib.h>
#include "16_Newton_Raphson_Verfahren_Header.h"
#include "17_Mathe_Bibliothek_Header.h"


int main()
{   
    /*Variable die den *x_Wert trägt wird initialisiert und ein Pointer darauf angelegt*/
    double x_Wert = 0;
    double* x_Wert_prt = &x_Wert;

    /*Pointer auf die Funktion: funktion*/
    double (*funktion_prt)(double) = &funktion;
    /*Pointer auf die Funktion: ableitung_analytisch*/
    double (*ableitung_analytisch_prt)(double) = &ableitung_analytisch;
    /*Pointer auf die Funktion: ableitung_nummerisch*/
    double (*ableitung_nummerisch_prt)(double (*funktion_prt)(double), double) = &ableitung_nummerisch;

    /*Variable um die Ableitnugsart festzulegen*/
    int Ableitungart = 0;

    /*einleitende print Befehle um die Ableitungsart und Startwert von x festzulegen*/
    printf("Dies ist ein Programm zur Ermittlung einer Nullstelle mit dem Newton Raphson Verfahren.\n");
    printf("Soll die Ableitung analytisch(1) oder nummerisch(2) ermittelt werden?\n");
    scanf("%d", &Ableitungart);
    if(Ableitungart !=1 && Ableitungart != 2)
    {
        printf("Fehler: Falsche Ableitungsart!\n");
        return 0;
    }
    printf("Mit welchem Wert für x soll gestartet werden? (auch Dezimalzahlen möglich)\n");
    scanf("%lf", x_Wert_prt);

    /*Der Newton Raphson Funktion werden die passenden Parameter übergeben*/
    Newton_Raphson_Verfahren(Ableitungart, (*funktion_prt),
    (*ableitung_analytisch_prt), (*ableitung_nummerisch_prt), x_Wert_prt);

    /*finales print Statement um das fertige Ergebnis auszugeben*/
    printf("Eine mögliche Nullstelle der Funktion f(x)=(x-3)^2 liegt bei X = %lf\n", (*x_Wert_prt));
    return 1;
}
/* 
 * total: 10/10 
 */ 