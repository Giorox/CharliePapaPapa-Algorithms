/*
	Algoritmo de Boyer-Moore-Horspool para busca em texto
	Complexidade: O(n)

    Implementação feita por: Giovanni Rebouças
    Universidade Federal de Itajubá - UNIFEI
	https://github.com/Giorox
    13/05/2016
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*
	Função que retorna a posição relativa no texto em que se encontra a primeira palavra do padrão.
	
	@param string texto, onde será feito a busca; string padrão, o que será buscado.
	@return int posição da primeira letra do padrão no texto; Caso não encontre o retorno padrão é -1.
*/
int BMH(string texto, string padrao) //Texto é o texto onde a busca será feita, e padrao é oque será buscado
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

    int pulo = 0; //Seta o valor do pulo pra 0 no início

    while(texto.size() - pulo >= padrao.size()) //Certifica que o texto será todo analisado sem desperdícios e evitando erros de limites.
    {
        int i = padrao.size() - 1; //Iterador para andar na string de trás para frente em que será buscado
        bool contem = false;
        while(texto[pulo+i] == padrao[i]) //Analisa se na posição analisada do texto se encontra o padrão
        {
            if (i == 0)
                return pulo;
            i = i - 1;
        }

        for(int j = 0; j<=padrao.size(); j++) //Analisa se ele encontra alguma letra que possui cálculo de distância e redefine o valor do pulo
        {
            if(texto[pulo+i] == padrao[j])
            {
                pulo = pulo + distpadrao[j];
                contem = true;
                break;
            }
        }
        if(contem == false) //Se não contiver, o pulo recebe o tamanho do padrão
            pulo = pulo + padrao.size();
    }
    return -1; //Caso não retorne nada, o padrão é retornar -1, ou seja, não foi encontrado o padrão no texto.
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
		
		for(int i = 0; i < distancia+9; i++) //Pula distância + 9 para imprimir um "^" como se fosse uma seta para simplificar a visualização.
			cout<<" ";
		cout<<"^";
	}
	else
		cout<<"O padrao nao foi encontrado no texto.";

    return 0;
}
