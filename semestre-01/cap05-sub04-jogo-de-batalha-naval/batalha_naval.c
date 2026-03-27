#include <stdio.h>
#include <stdlib.h>


#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)



// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) 
{
    // Percorre todas as linhas e colunas, preenchendo com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) 
    {
        for (int j = 0; j < TAM_TABULEIRO; j++) 
        {
            tabuleiro[i][j] = 0;
        }
    }
}



// Função para exibir o tabuleiro no console, mostrando água (0), navio (3) e área de habilidade (5)
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) 
{
    printf("Tabuleiro Batalha Naval:\n\n");
    // Exibe cada linha do tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++) 
    {
        for (int j = 0; j < TAM_TABULEIRO; j++) 
        {
            // Exibe diferentes caracteres para cada elemento
            if (tabuleiro[i][j] == 0)
                printf("~ ");

            else if (tabuleiro[i][j] == 3)
                printf("N "); 

            else if (tabuleiro[i][j] == 5)
                printf("* ");

            else
                printf("? ");
        }
        printf("\n");
    }
}


// Função para construir matriz de habilidade em cone (ponta para baixo)
void construirCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            cone[i][j] = 0;


    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        int meio = TAM_HABILIDADE / 2;
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if ( (j >= meio - i) && (j <= meio + i) )
                cone[i][j] = 1;
        }
    }
}


// Função para construir matriz de habilidade em cruz
void construirCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            cruz[i][j] = 0;

    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            if (i == meio || j == meio)
                cruz[i][j] = 1;
}


// Função para construir matriz de habilidade em octaedro (losango)
void construirOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            octaedro[i][j] = 0;

    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            if (abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
}


// Função para sobrepor matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna)
{
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            int linha = origem_linha - meio + i;
            int coluna = origem_coluna - meio + j;
            if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO)
            {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

int main() 
{
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];


    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);


    // Vetor representando as partes do navio (valor 3)
    int navio[TAM_NAVIO] = {3, 3, 3};

    // Navio 1: horizontal
    int navio1_linha = 2, navio1_coluna = 4;


    // Navio 2: vertical
    int navio2_linha = 6, navio2_coluna = 1;


    // Navio 3: diagonal principal (linha e coluna aumentam)
    int navio3_linha = 0, navio3_coluna = 0;


    // Navio 4: diagonal secundária (linha aumenta, coluna diminui)
    int navio4_linha = 7, navio4_coluna = 2;


    // 1. Navio horizontal
    int pode_horizontal = 1;


    for (int i = 0; i < TAM_NAVIO; i++) 
    {
        int coluna = navio1_coluna + i;


        // Verifica se está dentro dos limites e se não há sobreposição
        if (coluna >= TAM_TABULEIRO || tabuleiro[navio1_linha][coluna] != 0) 
        {
            pode_horizontal = 0;
            break;
        }
    }



    if (pode_horizontal) 
    {
        for (int i = 0; i < TAM_NAVIO; i++) 
        {
            tabuleiro[navio1_linha][navio1_coluna + i] = navio[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }



    // 2. Navio vertical
    int pode_vertical = 1;


    for (int i = 0; i < TAM_NAVIO; i++) 
    {
        int linha = navio2_linha + i;


        if (linha >= TAM_TABULEIRO || tabuleiro[linha][navio2_coluna] != 0) 
        {
            pode_vertical = 0;
            break;
        }
    }



    if (pode_vertical) 
    {
        for (int i = 0; i < TAM_NAVIO; i++) 
        {
            tabuleiro[navio2_linha + i][navio2_coluna] = navio[i];
        }
    } else 
    {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }



    // 3. Navio diagonal principal (linha e coluna aumentam)
    int pode_diagonal_principal = 1;


    for (int i = 0; i < TAM_NAVIO; i++)
    {
        int linha = navio3_linha + i;
        int coluna = navio3_coluna + i;


        if (linha >= TAM_TABULEIRO || coluna >= TAM_TABULEIRO || tabuleiro[linha][coluna] != 0)
        {
            pode_diagonal_principal = 0;
            break;
        }
    }


    
    if (pode_diagonal_principal)
    {
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            tabuleiro[navio3_linha + i][navio3_coluna + i] = navio[i];
        }
    }
    else
    {
        printf("Erro ao posicionar navio diagonal principal!\n");
        return 1;
    }



    // 4. Navio diagonal secundária (linha aumenta, coluna diminui)
    int pode_diagonal_secundaria = 1;


    for (int i = 0; i < TAM_NAVIO; i++)
    {
        int linha = navio4_linha + i;
        int coluna = navio4_coluna - i;


        if (linha >= TAM_TABULEIRO || coluna < 0 || tabuleiro[linha][coluna] != 0)
        {
            pode_diagonal_secundaria = 0;
            break;
        }
    }



    if (pode_diagonal_secundaria)
    {
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            tabuleiro[navio4_linha + i][navio4_coluna - i] = navio[i];
        }
    }
    else
    {
        printf("Erro ao posicionar navio diagonal secundaria!\n");
        return 1;
    }



    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];


    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);




    int origem_cone_linha = 3, origem_cone_coluna = 6;
    int origem_cruz_linha = 7, origem_cruz_coluna = 7;
    int origem_octaedro_linha = 5, origem_octaedro_coluna = 3;



    aplicarHabilidade(tabuleiro, cone, origem_cone_linha, origem_cone_coluna);
    aplicarHabilidade(tabuleiro, cruz, origem_cruz_linha, origem_cruz_coluna);
    aplicarHabilidade(tabuleiro, octaedro, origem_octaedro_linha, origem_octaedro_coluna);



    exibirTabuleiro(tabuleiro);


    return 0;
}
