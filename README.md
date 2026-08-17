# Audio Signal Processing in C

Biblioteca e conjunto de rotinas em C para **Processamento Digital de Sinais (PDS)** focadas em manipulação de vetores de áudio/amostras. 

O projeto implementa desde operações elementares de manipulação de amplitude e tempo até filtros de suavização e algoritmos para geração de efeitos de eco gradual.

---

## Funcionalidades e Algoritmos Implementados

- **Controle de Ganho (`mudaGanho`):** Amplificação/atenuação do sinal por fator escalar.
- **Mixagem de Sinais (`misturaDados`):** Somatório ponto a ponto de dois canais de áudio.
- **Inversão Temporal (`inverteSinal`):** Reversão do vetor de dados (*reverse audio*) com algoritmo in-place de complexidade $O(N/2)$.
- **Deslocamento/Atraso (`atrasaSinal`):** Aplicação de delay positivo/negativo com preenchimento em zero (*zero-padding*).
- **Filtro de Média Móvel (`filtroDaMedia`):** Filtro passa-baixas para atenuação de ruídos de alta frequência.
- **Efeito de Eco Simulado (`ecos`):** Encadeamento de delay, filtragem e atenuação exponencial de decaimento.

---

## 💻 Tecnologias

- **Linguagem em C
- **Gerenciamento Dinâmico de Memória** (`stdlib.h` - `malloc`/`free`)
- **Ponteiros & Manipulação de Vetores**

---

##  Estrutura das Funções

```c
Exemplo da assinatura principal para cálculo de ecos encadeados
void ecos(double* dados, int n_amostras, int n_repeticoes, int atraso, int abafamento, double decaimento);
