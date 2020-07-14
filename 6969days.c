#include <stdio.h>
#include <stdlib.h>

int main()
{
    int date(char string[]);
    int dia, mes, ano;
    int alvo, target;
    int calen[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int bicalen[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    char a[15], letra;

    printf("Insira a data atual no formato 01/01/2000:\n");
    do
    {
        letra = getchar();
        a[i] = letra;
        i++;
    } while (letra != '\n');
    a[i-1] = '\0';

    printf("Agora insira quantos dias quer voltar no tempo:\n");
    scanf("%d", &alvo);
    
    dia = date(a, 0);
    mes = date(a, 1);
    ano = date(a, 2);

    target = alvo;

    mes--;
    if (mes == 0)
    {
        mes = 12;
        ano--;
    }

    int dias = 0;
    int meses = 0;
    int anos = 0;

    while (alvo > 0)
    {
        dias = alvo;
        if (ano % 4 == 0)
        {
            alvo = alvo - bicalen[mes-1];
        } else
        {
            alvo = alvo - calen[mes-1];
        }
        meses++;
        mes--;
        if (mes == 0)
        {
            mes = 12;
            ano--;
        }
    }
    meses--;
    if (meses > 12)
    {
        anos = meses / 12;
        meses = meses % 12;
    }

    int hjdia = date(a, 0) - dias;
    int hjmes = date(a, 1) - meses;
    int hjano = date(a, 2) - anos;

    if (hjmes <= 0)
    {
        hjmes = hjmes + 12;
        hjano--;
    }
    if (hjdia <= 0 && hjano % 4 == 0)
    {
        hjdia = hjdia + bicalen[hjmes-2];
        hjmes--;
    } else if (hjdia <= 0 && hjano % 4 != 0)
    {
        hjdia = hjdia + calen[hjmes-2];
        hjmes--;
    }
    if (hjmes == 0)
        {
            hjmes = 12;
            hjano--;
        }
    
    if (hjdia > 9 && hjmes > 9)
    {
        printf("\nHa %d dias atras era o dia: %d/%d/%d\n\n", target, hjdia, hjmes, hjano);
    } else if (hjdia < 10 && hjmes > 9)
    {
        printf("\nHa %d dias atras era o dia: 0%d/%d/%d\n\n", target, hjdia, hjmes, hjano);
    } else if (hjdia > 9 && hjmes < 10)
    {
        printf("\nHa %d dias atras era o dia: %d/0%d/%d\n\n", target, hjdia, hjmes, hjano);
    } else if (hjdia < 10 && hjmes < 10)
    {
        printf("\nHa %d dias atras era o dia: 0%d/0%d/%d\n\n", target, hjdia, hjmes, hjano);
    }

    system("pause");
    
    return 0;
}

int date(char string[], int num)
{
    int data[3], i, j, k, m;
    i = 0;
    k = 0;
    m = 0;
    char nums[] = "0123456789";

    while (string[i] != '\0')
    {
        for (j = 0; j < 11; j++)
        {
            switch (i)
            {
            case 0:
                if (nums[j] == string[i])
                {
                    data[k] = j * 10;
                
                }
                break;
            case 1:
                if (nums[j] == string[i])
                {
                    data[k] = data[k] + j;
                    k++;
                
                }
                break;
            case 3:
                if (nums[j] == string[i])
                {
                    data[k] = j * 10;
                
                }
                break;
            case 4:
                if (nums[j] == string[i])
                {
                    data[k] = data[k] + j;
                    k++;
                
                }
                break;
            case 6:
                if (nums[j] == string[i])
                {
                    data[k] = j * 1000;
                
                }
                break;
            case 7:
                if (nums[j] == string[i])
                {
                    data[k] = data[k] + j * 100;
                
                }
                break;
            case 8:
                if (nums[j] == string[i])
                {
                    data[k] = data[k] + j * 10;
                
                }
                break;
            case 9:
                if (nums[j] == string[i])
                {
                    data[k] = data[k] + j;
                
                }
                break;
            default:
                break;
            }
            
        }

        i++;   
    }
    return data[num];   
}