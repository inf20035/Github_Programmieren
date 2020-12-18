/*Die ausgelagerten Funktionen werden mit ihren Parametern und ihrem Rückgabetyp deklariert*/
#ifndef MATHE_BIBLIOTHEK
#define MATHE_BIBLIOTHEK

double ableitung_nummerisch(double (*funktion)(double), double x_Wert);
void Newton_Raphson_Verfahren(int Ableitungsart, double (*funktion_prt)(double),
double (*ableitung_analytisch_prt)(double), double (*ableitung_nummerisch_prt)(double (*funktion_prt)(double), double),
double* x_Wert_prt);

#endif