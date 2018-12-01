/*
	Algoritmo de Boyer-Moore-Horspool para busca em texto
	Complexidade: O(n)

    Implementa��o feita por: Giovanni Rebou�as
    Universidade Federal de Itajub� - UNIFEI
	https://github.com/Giorox
    13/05/2016
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*
	Fun��o que retorna a posi��o relativa no texto em que se encontra a primeira palavra do padr�o.
	
	@param string texto, onde ser� feito a busca; string padr�o, o que ser� buscado.
	@return int posi��o da primeira letra do padr�o no texto; Caso n�o encontre o retorno padr�o � -1.
*/
int BMH(string texto, string padrao) //Texto � o texto onde a busca ser� feita, e padrao � oque ser� buscado
{
    int distpadrao[padrao.size()]; //Vetor de distancias da palavra

    for (int i = 0; i <padrao.size(); i++) //Definindo as distancias iniciais
    {
        if(i+1 == padrao.size())
            distpadrao[i] = padrao.size();
        else
            distpadrao[i] = padrao.size() - (1+i);
    }

    for (int i = 0; i <padrao.size(); i++) //Fazendo o minimo das distancias para eliminar duplicatas
        for(int j = 0; j <padrao.size(); j++)
        {
            if(padrao[i] == padrao[j])
                if(distpadrao[i] < distpadrao[j])
                    distpadrao[j] = distpadrao[i];
                else
                    distpadrao[i] = distpadrao[j];
        }

    int pulo = 0; //Seta o valor do pulo pra 0 no in�cio

    while(texto.size() - pulo >= padrao.size()) //Certifica que o texto ser� todo analisado sem desperd�cios e evitando erros de limites.
    {
        int i = padrao.size() - 1; //Iterador para andar na string de tr�s para frente em que ser� buscado
        bool contem = false;
        while(texto[pulo+i] == padrao[i]) //Analisa se na posi��o analisada do texto se encontra o padr�o
        {
            if (i == 0)
                return pulo;
            i = i - 1;
        }

        for(int j = 0; j<=padrao.size(); j++) //Analisa se ele encontra alguma letra que possui c�lculo de dist�ncia e redefine o valor do pulo
        {
            if(texto[pulo+i] == padrao[j])
            {
                pulo = pulo + distpadrao[j];
                contem = true;
                break;
            }
        }
        if(contem == false) //Se n�o contiver, o pulo recebe o tamanho do padr�o
            pulo = pulo + padrao.size();
    }
    return -1; //Caso n�o retorne nada, o padr�o � retornar -1, ou seja, n�o foi encontrado o padr�o no texto.
}

int main ()
{
    string texto, padrao;

    cout<<"Entre com o texto: ";
    getline(cin,texto);
    cout<<"Entre com o padrao: ";
    getline(cin,padrao);

    int distancia = BMH(texto,padrao);

	if( distancia != -1 )
	{
		cout<<"A posicao da primeira letra do padrao esta na posicao " <<distancia <<" do texto." <<endl;
		cout<<"Posicao: "<<texto <<endl;
		
		for(int i = 0; i < distancia+9; i++) //Pula dist�ncia + 9 para imprimir um "^" como se fosse uma seta para simplificar a visualiza��o.
			cout<<" ";
		cout<<"^";
	}
	else
		cout<<"O padrao nao foi encontrado no texto.";

    return 0;
}
