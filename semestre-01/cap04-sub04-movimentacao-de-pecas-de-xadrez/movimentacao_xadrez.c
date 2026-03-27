#include <stdio.h>

/*
    Função recursiva para simular o movimento da Torre.
    Move-se apenas para a direita, imprimindo "Direita" a cada chamada.
*/
void moverTorreRecursivo(int casasRestantes) 
{
    if (casasRestantes <= 0) return;
    printf("Direita\n");
    moverTorreRecursivo(casasRestantes - 1);
}



/*
    Função recursiva para simular o movimento da Rainha.
    Move-se apenas para a esquerda, imprimindo "Esquerda" a cada chamada.
*/
void moverRainhaRecursivo(int casasRestantes) 
{
    if (casasRestantes <= 0) return;
    printf("Esquerda\n");
    moverRainhaRecursivo(casasRestantes - 1);
}



/*
    Função recursiva para simular o movimento do Bispo.
    Utiliza loops aninhados: o loop externo representa o movimento vertical (cima),
    e o loop interno representa o movimento horizontal (direita).
    A cada passo, imprime "Cima Direita".
*/
void moverBispoRecursivo(int casasVerticais, int casasHorizontais) 
{
    if (casasVerticais <= 0 || casasHorizontais <= 0) return;


    for (int v = 0; v < casasVerticais; v++) 
    {
        for (int h = 0; h < casasHorizontais; h++) 
        {
            printf("Cima Direita\n");
        }
    }
}



/*
    Função para simular o movimento do Cavalo usando loops aninhados e múltiplas condições.
    O Cavalo move-se em "L": duas casas para cima e uma para a direita.
    Utiliza break e continue para controlar o fluxo.
*/
void moverCavaloL(int movimentos) 
{
    int casasCima = 2;
    int casasDireita = 1;


    printf("Movimento do Cavalo:\n");
    for (int m = 0; m < movimentos; m++) 
    {
        int cima = 0, direita = 0;


        for (cima = 0; cima < casasCima + 1; cima++) 
        {
            if (cima == casasCima) break;
            printf("Cima\n");
        }


        for (direita = 0; direita < casasDireita + 1; direita++) {
            if (direita == casasDireita) break;


            if (direita == 0) 
            {
                printf("Direita\n");
                continue;
            }
        }
    }
}



int main() 
{
    // Número de casas para cada peça
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;
    int movimentosCavalo = 1; // Quantas vezes o cavalo fará o movimento em "L"


    // Torre (recursivo)
    printf("Movimento da Torre:\n");
    moverTorreRecursivo(casasTorre);


    // Bispo (recursivo + loops aninhados)
    printf("\nMovimento do Bispo:\n");
    moverBispoRecursivo(1, casasBispo); // 1 movimento vertical, 5 horizontais (diagonal para cima e direita)


    // Rainha (recursivo)
    printf("\nMovimento da Rainha:\n");
    moverRainhaRecursivo(casasRainha);


    // Cavalo (loops aninhados, múltiplas variáveis e condições)
    printf("\n");
    moverCavaloL(movimentosCavalo);

    
    return 0;
}
