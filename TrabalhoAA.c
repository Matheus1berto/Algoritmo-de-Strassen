#include<stdio.h>
#include<math.h>
#include<time.h>
#define n 16


//GRUPO
//ALUNO: MATHEUS HUMBERTO G. F. COSTA
//MATRICULA: 11811BCC006
//ALUNO : JOÃO ANTÔNIO NARDINI ROMANIELLO
//MATRICULA : 11811BCC028

//O TAMANHO DA MATRIZ PODE SER MODIFICADO ATRAVÉS DO DEFINE INCLUSO NO TOPO DO PROGRAMA
//PARA TER UMA VISUALIZAÇÃO MELHOR DE CADA MATRIZ BASTA TIRAR OS COMENTARIOS NOS CÓDIGOS FORNECIDOS

 static int matX[n][n]; //Matriz 1
 static int matY[n][n];  //Matriz 2
 static int x[n][n],y[n][n],matZ[n][n];


 int AlgStrassen(int *A, int *B, int *C, int m, int n1){
    if(m==2){
        int P1=(*A+*(A+n1+1))*(*B+*(B+n1+1));  
        int P2=(*(A+n1)+*(A+n1+1))*(*B);   
        int P3=(*A)*(*(B+1)-*(B+n1+1));   
        int P4=(*(A+n1+1))*(*(B+n1)-*B);   
        int P5=(*A+*(A+1))*(*(B+n1+1));   
        int P6=(*(A+n1)-*A)*(*B+*(B+1));  
        int P7=(*(A+1)-*(A+n1+1))*(*(B+n1)+*(B+n1+1));  

        *C=*C+P1+P4-P5+P7;  
        *(C+1)=*(C+1)+P3+P5;  
        *(C+n1)=*(C+n1)+P2+P4;  
        *(C+n1+1)=*(C+n1+1)+P1+P3-P2+P6;  
    }
    else{
        m=m/2;
        AlgStrassen(A,B,C,m,n1);

        AlgStrassen(A,B+m,C+m,m,n1);

        AlgStrassen(A+m,B+m*n1,C,m,n1);

        AlgStrassen(A+m,B+m*(n1+1),C+m,m,n1);

        AlgStrassen(A+m*n1,B,C+m*n1,m,n1);

        AlgStrassen(A+m*n1,B+m,C+m*(n1+1),m,n1);

        AlgStrassen(A+m*(n1+1),B+m*n1,C+m*n1,m,n1);

        AlgStrassen(A+m*(n1+1),B+m*(n1+1),C+m*(n1+1),m,n1);
    }



      return 0; //Caso retornou , o programa funcionou

}

int potencia(int x){
    int i,p=1;
    for(i=0;i<x;i++)
        p=2*p;
    return(p);
}

int alg1(int vet1[n][n],int vet2[n][n]) {

         int vet3[n][n];
         int i = 0;
         int j = 0;
         int k = 0;
         for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                vet3[i][j] = 0; //ZERA TODAS AS POSIÇÕES DA MATRIZ
            }
         }

      clock_t Ticks[2];
      Ticks[0] = clock();


        for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                        for(k=0; k<n; k++){
                                vet3[i][j] = vet3[i][j] + vet1[i][k] * vet2[k][j];
        }
     }

}


               Ticks[1] = clock();
              double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
              printf("Tempo gasto no algoritimo 1: %g ms.\n", Tempo);

                printf("\nMatriz resultante alg 1\n");
                print_matriz(&vet3);

        return vet3;
}

int print_matriz( int vet[n][n]){

int i = 0;
int j = 0;

printf("\n");

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
            printf(" %i ",vet[i][j]);
    }
    printf("\n");
 }

 printf("\n");
 return 0;


}

int main(){

//O tamanho da matriz é indicado pela variavel n no #Define

int i = 0;
int j = 0;
int m = 0;

for(i = 0;i<n;i++){
    for(j=0;j<n;j++){
        matX[i][j] =  rand()%10;//Gera a matrizX
        matY[i][j] =  rand()%10;//Gera a matrizY

    }
 }


    int P=1;
    while(n>potencia(P))
        P=P+1;
    m=potencia(P);
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            x[i][j]=0;
            y[i][j]=0;
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            x[i][j]=matX[i][j]; //copia matX para x
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            y[i][j]=matY[i][j]; //copia matY para y



    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            matZ[i][j]=0; //Inicializa a matriz auxiliar Z


//printf("Matriz X\n");               //PARA VISUALIZAR AS MATRIZES
//print_matriz(matX);                 //BASTA TIRAR O COMENTARIO
//printf("Matriz Y\n");               //DAS FUNCOES ANTERIORES
//print_matriz(matY);

     alg1(matX,matY);

     clock_t Ticks[2];
     Ticks[0] = clock();


      AlgStrassen(matX,matY,matZ,m,m);
      Ticks[1] = clock();
      double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
       printf("Tempo gasto no strassen: %g ms.\n\n", Tempo);

       //printf("Matriz resultante (Alg strassen) ==>\n");

      // print_matriz(matZ);


return 0;



}
