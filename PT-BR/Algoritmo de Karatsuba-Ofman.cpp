/*
    Algoritmo de Karatsuba-Ofman para multiplicação rápida de grandes inteiros
	Complexidade: O(n^log3)
	
	Implementação feita por: Giovanni Rebouças
    Universidade Federal de Itajubá - UNIFEI
	https://github.com/Giorox
    22/04/2017
*/
#include <iostream>
#include <cmath>
using namespace std;

/*
	Função que retorna a multiplicação de 2 inteiros de tamanho n
	
	@param int u, primeiro inteiro; int v, segundo inteiro; int n, tamanho de ambos
	@return int resultado da multiplicação de u por v
*/
int KaratsubaOfman (int u, int v, int n)
{
    if (n < 3)
        return u*v;
    else
    {
        int m = n/2;
        int p = u/pow(10,m);
        int q = u*pow(10,m);
        int r = v/pow(10,m);
        int s = v*pow(10,m);
        int pr = KaratsubaOfman (p, r, m);
        int qs = KaratsubaOfman (q, s, m);
        int y = KaratsubaOfman (p+q, r+s, m+1);
        int x = (pr*pow(10,2*m)) + ((y-pr-qs)*pow(10,m)) + qs;
        return  x;
    }
}

int main()
{
    int u = 10, v = 11, n = 2;

    cout <<KaratsubaOfman(u, v, n);
}
