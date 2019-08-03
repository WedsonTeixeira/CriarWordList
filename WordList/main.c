#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *WordList = fopen("WordList.txt","w");
    char Letras[] = {'a','b','c','d','e','1','2','3','4','5',
                     '!','@','#','$','%','\0'};
    // Em Letras[] adicione ou remova numeros, caracteres especiais,
    // letras maiusculas ou minusculas se necessario
    // Obs. Obrigatorio o uso do '\0' no final
    // Obs. Nao repita as letras de forma alguma
    // Obs. Nao use a letra ' ' em Letras[]

    int TamanhoMaximo = 3; // mude conforme necessario.
    int Verificar = 1;
    int Controle = 0;
    int Indice1 = 0;
    int Indice2 = 0;

    char Palavra[TamanhoMaximo];
    char PalavraFinal[TamanhoMaximo];
    char PalavraAuxiliar[TamanhoMaximo];

    int TotalLetras = sizeof(Letras)/sizeof(char)-1;
    char UltimaLetra = Letras[TotalLetras-1];

    for(int i = 0; i < TamanhoMaximo; i++)
    {
        // Palavra[i] = ' ';         primeira Palavra = 'a';
        // Palavra[i] = UltimaLetra; primeira Palavra = 'aaa' se TamanhoMaximo for igual a 3

        Palavra[i] = ' ';

        PalavraFinal[i] = UltimaLetra;
    }
    Palavra[TamanhoMaximo]= '\0';
    PalavraFinal[TamanhoMaximo]= '\0';

    while(Verificar != 0)
    {
        for(int i = 0; i < TotalLetras; i++)
        {
            Palavra[TamanhoMaximo-1] = Letras[i];
            Indice1 = 0;

            for(int j = 0; j < TamanhoMaximo; j++)
            {
                if(Palavra[j] != ' ')
                {
                    PalavraAuxiliar[Indice1++] = Palavra[j];
                }
            }
            PalavraAuxiliar[Indice1] = '\0';

            fprintf(WordList,"%s",PalavraAuxiliar);
            fprintf(WordList,"%s","\n");
        }

        for(Controle = TamanhoMaximo-1; Controle > 0; Controle--)
        {
            if(Palavra[Controle] != UltimaLetra)
            {
                break;
            }
        }

        Verificar = strcmp(Palavra,PalavraFinal);

        if(Palavra[Controle] == ' ')
        {
            for(int i = Controle; i < TamanhoMaximo; i++)
            {
                Palavra[i] = Letras[0];
            }
        }
        else
        {
            for(Indice2 = 0; Indice2 < TotalLetras; Indice2++)
            {
                if(Palavra[Controle] == Letras[Indice2])
                {
                    break;
                }
            }
            Palavra[Controle] = Letras[Indice2+1];

            for(int i = Controle+1; i < TamanhoMaximo; i++)
            {
                Palavra[i] = Letras[0];
            }
        }
    }
    fclose(WordList);
    printf("Word List Criada com Sucesso\n");
}
