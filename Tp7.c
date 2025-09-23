/******************************************************************************
 *                      Maximo A. Toranzo 418617 1R1                          *
 *                 https://github.com/UsualTori/Tp-7.git                      *
 ******************************************************************************/
#include <stdio.h>
#define TAM 3

int cod[TAM] = {0};
float pre[TAM] = {0};

void mayor_menor(int x[], float y[], int n)
{
    float c = 0; //Mas Caro
    float b = 999999999999999999; //Mas Barato
    int A = 0;//Pocision en la tabla del mas Caro
    int E = 0;//Pocision en la tabla del mas Barato
    
    for (int i = 0; i < n; i++)
    {
        if(c < y[i])
        {
            A = i;
            c = y[i];
        }
        
        if(b > y[i])
        {
            E = i;
            b = y[i];
        }
    }
    
    printf("\n+-------+----+------------+----------------------+\n");
    printf(  "|       | N° |   CODIGO   |        PRECIO        |\n");
    printf(  "+-------+----+------------+----------------------+\n");
    printf(  "| Mayor | %-2d | %10d | $%20.2f|\n", A+1, x[A], c);
    printf(  "+-------+----+------------+----------------------+\n");
    printf(  "| Menor | %-2d | %10d | $%20.2f|\n", E+1, x[E], b);
    printf(  "+-------+----+------------+----------------------+\n");
}

void tabla(int x[], float y[], int n)
{
    printf("\n+----+------------+----------------------+\n");
    printf(  "| N° |   CODIGO   |        PRECIO        |\n");
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
    
    printf("Ingrese 10 productos, se solicita el codigo y precio:\n");
    
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
    mayor_menor(cod, pre, TAM);

    return 0;
}
