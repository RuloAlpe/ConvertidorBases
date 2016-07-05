//programa que convierte a todas las bases computacionales
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void base2a10();
void base10a2();
void base2a8();
void base2a16();
void base8a2();
void base16a2();

void presentacion()
{
    printf("\n\n\n");
    printf("\t*****CONVERTIDOR DE BASES NUMERICAS*****\n");
    printf("\tAutor:Raul Alanis\n");
    printf("\tEstudiante Universidad Autonoma del Estado de Mexico\n");
    printf("\tIngenieria en Computacion\n");
    printf("\n------------------------------------------------------------------\n");
}

void base2a16()
{
    char digHexa[16] = "0123456789ABCDEF";
    char valorBin[16][4 + 1] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001","1010", "1011", "1100", "1101", "1110", "1111"};
    char cuarteto[4 + 1];
    char cadenaHexa[16 + 1];
    char numBinario[30];
    int a, b, c, indice;
    printf("INTRODUCIR CADENA BINARIA\n");
    scanf("%s",&numBinario);
    a = strlen(numBinario) - 1;
    indice = a / 4;
    cadenaHexa[indice + 1] = 0;

        while(a >= 0)
        {
            cuarteto[4] = 0;
            for(b = 3; b >= 0; b--)
            {
                cuarteto[b] = numBinario[a--];
            }
            for(c = 0; c < 16; c++)
            {
                if(strcmp(cuarteto, valorBin[c]) == 0)
                {
                    cadenaHexa[indice--] = digHexa[c];
                    break;
                }
            }
        }
        printf("EL VALOR HEXADECIMAL ES: %s\n", cadenaHexa);

}

void base2a8()
{
    char digoctales[] = "01234567";
    char valorBin[8][3 + 1] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    char tercia[3 + 1];
    char cadenaOctal[8 + 1];
    char numBinario[30];
    int a, b, c, indice;
    printf("INTRODUCIR CADENA BINARIA\n");
    scanf("%s",&numBinario);
    a = strlen(numBinario) - 1;
    indice = a / 3;
    cadenaOctal[indice + 1] = 0;

        while(a >= 0)
        {
            tercia[3] = 0;
            for(b = 2; b >= 0; b--)
            {
                tercia[b] = numBinario[a--];
            }
            for(c = 0; c < 8; c++)
            {
                if(strcmp(tercia, valorBin[c]) == 0)
                {
                    cadenaOctal[indice--] = digoctales[c];
                    break;
                }
            }
        }
        printf("EL VALOR EN OCTAL ES: %s\n",cadenaOctal);
}

void base10a2()
{
    int numDecimal;
    int cociente;
    int residuo[50 + 1];
    int i,j;

    printf("INGRESA NUMERO EN BASE 10\n");
    scanf("%d",&numDecimal);
    cociente = numDecimal;
    j = 0;
    for(i = cociente; cociente > 0; i--)
    {
        cociente = numDecimal / 2;
        residuo[j] = numDecimal % 2;
        numDecimal = cociente;
        j += 1;
    }
    printf("EL RESULTADO ES:\n ");
    for(i = j - 1; i >= 0; i--)
    {
        printf("%d\n",residuo[i]);
    }
}

void base2a10()
{
    int decimal=0;
    int tamanio;
    int i,valor,valor2;
    valor2 = 0;
    char numBinario[30];
    printf("INTRODUCIR CADENA BINARIA\n");
    scanf("%s",&numBinario);
    tamanio = strlen(numBinario);

    for(i = tamanio - 1; i >= 0; i--)
    {
        if(numBinario[i] == '0')
        {
            valor = 0;
            valor2++;
        }
        else
        {
            valor = 1;
            decimal = decimal + pow(2,valor2);
            valor2++;
        }
    }
    printf("\nEL VALOR EN DECIMAL ES %d\n",decimal);
}


void base8a2()
{
    char cadenaoctal[20];
    int x,y,z;

    printf("INGRESA CADENA OCTAL\n");
    scanf("%s",&cadenaoctal);
    x = strlen(cadenaoctal);

    printf("EL RESULTADO ES: ");
    for(y = 0; y <= x; y++)
    {
        z = cadenaoctal[y];
        switch(z)
        {
            case '0': printf("000");
                    break;
            case '1': printf("001");
                    break;
            case '2': printf("010");
                    break;
            case '3': printf("011");
                    break;
            case '4': printf("100");
                    break;
            case '5': printf("101");
                    break;
            case '6': printf("110");
                    break;
            case '7': printf("111");
                    break;
        }
    }
}


void base16a2()
{
   char numHexa[20];
   int i,j,k;

   printf("INGRESA NUMERO HEXADECIMAL CON MAYUSCULAS\n");
   scanf("%s",&numHexa);
   i = strlen(numHexa);

   printf("EL RESULTADO ES: ");
   for(j = 0; j <= i; j++)
   {
       k = numHexa[j];
       switch(k)
       {
           case '0': printf("0000");
                    break;
            case '1': printf("0001");
                    break;
            case '2': printf("0010");
                    break;
            case '3': printf("0011");
                    break;
            case '4': printf("0100");
                    break;
            case '5': printf("0101");
                    break;
            case '6': printf("0110");
                    break;
            case '7': printf("0111");
                    break;
            case '8': printf("1000");
                    break;
            case '9': printf("1001");
                    break;
            case 'A': printf("1010");
                    break;
            case 'B': printf("1011");
                    break;
            case 'C': printf("1100");
                    break;
            case 'D': printf("1101");
                    break;
            case 'E': printf("1110");
                    break;
            case 'F': printf("1111");
                    break;
       }
   }
}


int main(void)
{
    int opcion,opcion2,elegir;

    do
    {
        system("cls");
        //printf("***CONVERTIDOR DE BASES***\n\n");
        presentacion();

        printf("\n\nBASE EN LA QUE ESTA EL NUMERO QUE VA A INTRODUCIR\n");
        printf("2.-BASE 2\n8.-BASE 8\n10.-BASE 10\n16.-BASE 16\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        printf("BASE A LA QUE SE DESEA CONVERTIR\n");
        printf("2.-BASE 2\n8.-BASE 8\n10.-BASE 10\n16.-BASE 16\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion2);

        if(opcion == 2 && opcion2 == 10)
            base2a10();
        else if(opcion == 10 && opcion2 == 2)
            base10a2();
        else if(opcion == 2 && opcion2 == 8)
            base2a8();
        else if(opcion == 2 && opcion2 == 2)
            printf("NO SE PUEDE CONVERTIR NUMERO BINARIO A NUMERO BINARIO\n");
        else if(opcion == 2 && opcion2 == 16)
            base2a16();
        else if(opcion == 8 && opcion2 == 2)
            base8a2();
        else if(opcion == 8 && opcion2 == 8)
            printf("NO SE PUEDE CONVERTIR NUMERO OCTAL A NUMERO OCTAL\n");
        else if(opcion == 8 && opcion2 == 10)
            printf("ERROR\n");
        else if(opcion == 8 && opcion2 == 16)
            printf("ERROR\n");
        else if(opcion == 10 && opcion2 == 8)
            printf("ERROR\n");
        else if(opcion == 10 && opcion2 == 10)
            printf("NO SE PUEDE CONVERTIR NUMERO DECIIMAL A NUMERO DECIMAL\n");
        else if(opcion == 10 && opcion2 == 8)
            printf("ERROR\n");
        else if(opcion == 16 && opcion2 == 2)
            base16a2();
        else if(opcion == 16 && opcion2 == 8)
            printf("ERROR\n");
        else if(opcion == 16 && opcion2 == 10)
            printf("ERROR\n");
        else if(opcion == 16 && opcion2 == 16)
            printf("NO SE PUEDE CONVERTIR NUMERO HEXADECIMAL A NUMERO HEXADECIMAL\n");

        printf("\nDESEA SALIR 0-SI, 1-NO\n");
        scanf("%d",&elegir);
    }while(elegir == 1);


 return EXIT_SUCCESS;
}
