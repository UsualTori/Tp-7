/******************************************************************************
 *                      Maximo A. Toranzo 418617 1R1                          *
 *                 https://github.com/UsualTori/Tp-7.git                      *
 ******************************************************************************/
#include <stdio.h>
#define TAM 3

int cod[TAM] = {0};
float pre[TAM] = {0};

void tabla(int x[], float y[], int n)
{
    printf("\n+----+------------+----------------------+\n");
    printf(  "| N  |   CODIGO   |        PRECIO        |\n");
    printf(  "+----+------------+----------------------+\n");
        
    for (int i = 0; i < n; i++)
    {
        printf("| %-2d | %10d | $%20.2f|\n", i+1, x[i], y[i]);
    }
        
    printf(  "+----+------------+----------------------+\n");
}

int main()
{
    int basura;
    
    printf("Ingrese %d productos, se solicitara el codigo y precio:\n", TAM);
    
    for(int i=0;i<TAM;i++)
    {
        //Codigo de barras
        do{
            printf("\nIngrese el codigo de barras (1-999999999): ");
            basura = scanf("%d",&cod[i]);
            
            if(cod[i] < 1 ||cod[i] > 999999999||basura != 1) //Detecta >1 o caracter
            {
                printf("\n-----------------------------ERROR-----------------------------");
                while (getchar() != '\n');
            }
        }while(cod[i] < 1 ||cod[i] > 999999999||basura != 1);
        
        //Precio
        do{
            printf("Ingrese el precio: ");
            basura = scanf("%f", &pre[i]);
            
            if(pre[i] < 0||basura != 1) //Detecta >0 o caracter
            {
                printf("\n-----------------------------ERROR-----------------------------\n");
                while (getchar() != '\n');
            }
        }while(pre[i] < 0||basura != 1);
    }
    
    tabla(cod, pre, TAM);

    return 0;
}
