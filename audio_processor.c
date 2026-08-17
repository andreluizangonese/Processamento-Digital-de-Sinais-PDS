// Autor: Andre Angonese 

#include <stdio.h>
#include<stdlib.h>

/* Multiplica todas as posicoes do vetor pelo ganho */
void mudaGanho(double* dados, int n_amostras, double ganho)
{
    int i;

    for(i = 0; i < n_amostras; i++)
    {
        dados[i] *= ganho;
    }
}

/* Soma dois vetores e guarda o resultado em "saida" */
void misturaDados(double* dados1, double* dados2, double* saida, int n_amostras)
{
    int i;

    for(i = 0; i < n_amostras; i++)
    {
        saida[i] = dados1[i] + dados2[i];
    }
}

/* Inverte as posicoes  do vetor */
void inverteSinal(double* dados, int n_amostras)
{
    int i;
    double aux;

    /* Vai somente ate a metade */
    for(i = 0; i < n_amostras / 2; i++)
    {
        // Guarda o valor atual
        aux = dados[i];

        // Troca os elementos
        dados[i] = dados[n_amostras - 1 - i];
        dados[n_amostras - 1 - i] = aux;
    }
}

/* Desloca os valores do vetor */
void atrasaSinal(double* dados, int n_amostras, int atraso)
{
    int i;

    /* Desloca para direita */
    if(atraso > 0)
    {
        /* Move de tres para frente
        para nao sobrescrever valores */
        for(i = n_amostras - 1; i >= atraso; i--)
        {
            dados[i] = dados[i - atraso];
        }

        /* Preenche o comeco com 0 */
        for(i = 0; i < atraso; i++)
        {
            dados[i] = 0;
        }
    }

    /* Desloca para esquerda */
    else if(atraso < 0)
    {
        /* Move da frente para tres */
        for(i = 0; i < n_amostras + atraso; i++)
        {
            dados[i] = dados[i - atraso];
        }

        /* Preenche o final com 0 */
        for(i = n_amostras + atraso; i < n_amostras; i++)
        {
            dados[i] = 0;
        }
    }
}

void filtroDaMedia (double* dados, int n_amostras, int largura)
{
    int i, j, k;

    // Soma dos valores na faixa
    double soma;
    double* aux;

    aux = malloc(sizeof(double) * n_amostras);

    // Largura minima 3 e maxima igual a n_amostras
    if(largura>=3 && largura%2!=0 && largura<=n_amostras)
    {
        // Aux copia o vetor dados
        for(i=0; i<n_amostras; i++)
        {
            aux[i]=dados[i];
        }

        // Posicao que atende aos requisitos da largura
        i=0;
        while(largura-i>i+1)
        {
            i++;
        }

        /* So considera valores validos para o calculo da media */
        for(k=i; k<n_amostras-i; k++)
        {
            soma=0;

            /* Soma dos valores na faixa
            determinados pela largura */
            for(j=k-(largura-1)/2; j<=k+(largura-1)/2; j++)
            {
                soma+=aux[j];
            }

            // Calculo da media e armazenado em dados
            dados[k]=soma/largura;
        }
    }

    free(aux);
}

void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso, int abafamento, double decaimento)
{
    int i;
    double* aux;

    aux = malloc(sizeof(double) * n_amostras);

    // Aux copia dados
    for(i=0; i<n_amostras; i++)
    {
        aux[i]=dados[i];
    }

    for(i=0; i<n_repeticoes; i++)
    {

        /* Primeiro o sinal  atrasado para
        nao atrapalhar no filtroDaMedia */
        atrasaSinal (aux, n_amostras, atraso);

        // Realiza o filtroDaMedia
        filtroDaMedia (aux, n_amostras, abafamento);

        // Multiplica a repeticao pelo decaimento
        mudaGanho (aux, n_amostras, decaimento);

        // Mistura o dados com a repeticao
        misturaDados (aux, dados, dados, n_amostras);
    }

    free(aux);
}
