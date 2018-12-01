/*
    Distância de Levenshtein usando Programação Dinâmica
	Complexidade: O(n^2-x) onde x é um inteiro menor que 0
	
	Implementação feita por: Giovanni Rebouças
    Universidade Federal de Itajubá - UNIFEI
	https://github.com/Giorox
    22/04/2017
*/
#include <iostream>
using namespace std;

/*
	Função que retorna o número de alterações de digito único (inserção, deleção e substituição) necessárias para transforma uma string em outra
	
	@param string s, primeira string; string t, segunda string; int m, tamanho da string s; int n, tamanho da string t
	@return int o número de operações necessário para transforma a string "s" na string "t"
*/
int algoritmoPD(string s, string t, int m, int n)
{
    int d[m][n];
    int i, j, subst;

    for(i=0; i <= m; i++)
        for(j=0; j <= n; j++)
            d[i][j] = 0;

    for(i = 1; i<=m; i++)
        d[0][i] = i;

    for(j = 1; j <= n; j++)
        d[j][0] = j;

    for(j = 1; j <= n; j++)
        for(i=1; i<= m; i++)
        {
            if(s[i] == t[j])
                subst = 0;
            else
                subst = 1;

            d[i][j] =std::min(std::min(d[i-1][j] + 1, d[i][j-1] + 1), d[i-1][j-1] + subst);
        }
    return d[m][n];
}

int main ()
{
    int m = 0, n = 0;
    string s, t;

    cin>>s;
    cin>>t;

    m = s.size();
    n = t.size();

    cout<<"RESULTADO: " <<algoritmoPD(s, t, m, n);

    return 0;
}
