#include <iostream>
/*
    Autor: Manuel Cris�logo
*/
using namespace std;

double EvaluarPolinomio(const double P[], const int nP, const double x);

int main()
{
    // Ejemplo: f(x) = 1.1x^10 + 3x^5 + 9.31x^4 + 21x^3 + 3x + 4, x = 4.45
    int nP = 10;
    double P[nP + 1] = {4, 3, 0, 21, 9.31, 3, 0, 0, 0, 0, 1.1};

    cout << std::fixed << "f(x) = " << EvaluarPolinomio(P, nP, 4.45) << endl;

    return 0;
}


inline double Elevar(const double x, const int n, double *conocidos[]){
    double resultado = 0;

    if (conocidos[n])
        resultado = *conocidos[n];

    else{
        if (n == 0) resultado = 1; //Se puede quitar predefiniendo como 0 el primer n�mero de los conocidos
        else if (n % 2 == 1) resultado = x * Elevar(x, n - 1, conocidos);
        else{
            resultado = Elevar(x, n / 2, conocidos);
            resultado *= resultado;
        }

        conocidos[n] = new double;
        *conocidos[n] = resultado;
    }

    return resultado;
}


double EvaluarPolinomio(const double P[], const int nP, const double x){
    double *xn_conocidos[nP + 1];
    double resultado = 0;
    double nuevo = 0; // Solo para versi�n ilustrativa.

    for (int i = 0 ; i <= nP ; ++i)
        xn_conocidos[i] = NULL;

    //  C�lculos
    for (int i = nP ; i >= 0 ; --i)
        if (P[i] != 0){
            // Ilustrativo. La �nica instrucci�n para implementarlo es la �ltima (comentada)
            nuevo = P[i] * Elevar(x, i, xn_conocidos);
            cout << "+" << nuevo << endl;
            resultado += nuevo;
            // resultado += P[i] * Elevar(x, i, xn_conocidos); // Solo esto es necesario
        }

    //  Elimina los datos temporales de la funci�n auxiliar
    for (int i = 0 ; i <= nP ; ++i)
        if (xn_conocidos[i]) delete xn_conocidos[i];

    return resultado;
}
