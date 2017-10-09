#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float modulo(float x);
void apresenta(int N,float M[N][N],float vetorB[N]);

void main(){
  int i,j,k,N,linha;
  float pivo,max,aux,multiplicador;

  printf("METODO DE ELIMINACAO DE GAUSS.\n\n");

  printf("Digite a ordem da matriz:");
  scanf("%d",&N);

  float M[N][N];
  float vetorB[N],vetorR[N];

  for(i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("Elemento [%d][%d]:",i,j);
      scanf("%f",&M[i][j]);
    }
    printf("Posicao %d do vetor B: ",i);
    scanf("%f",&vetorB[i]);
  }

  printf("\nMatriz Original:");
  apresenta(N,M,vetorB);

  for (i=0;i<N;i++){
    max = modulo(M[i][i]);
    linha = i;

    for (j=i+1;j<N;j++){
      if (modulo(M[j][i])>max){
        max = modulo(M[j][i]);
        linha = j;
      }
    }

    if (max == 0){
      printf("\nMatriz sem solucao!!!\n");
      exit(1);
    }


    for(j=0;j<N;j++){ // Pivoteamento parcial
      aux = M[linha][j];
      M[linha][j] = M[i][j];
      M[i][j]=aux;
    }

    aux = vetorB[linha]; // Troca vetor B
    vetorB[linha]= vetorB[i];
    vetorB[i]=aux;

    pivo = M[i][i];

    for (j=i+1;j<N;j++){
      multiplicador = M[j][i]/pivo;
      M[j][i] = 0;
      vetorB[j] -= multiplicador * vetorB[i];
      for (k=i+1;k<=N;k++){
        M[j][k] -= multiplicador * M[i][k];
      }
    }
  }

  vetorR[N-1] = vetorB[N-1] / M[N-1][N-1];
  for(i=(N-2);i>=0;i--){
    aux = vetorB[i];
    for(j=(i+1);j<N;j++){
      aux -= (M[i][j] * vetorR[j]);
    }
    vetorR[i] = aux / M[i][i];
  }

  printf("\nMatriz Triangularizada:");
  apresenta(N,M,vetorB);

  printf("\nVetor Resultado:\n");
  for (i=0;i<N;i++){
    printf("%3.2f\n",vetorR[i]);
  }

}

void apresenta(int N,float M[N][N],float vetorB[N]){
  int i,j;
  printf("\n");
  for(i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("%3.2f\t",M[i][j]);
    }
    printf("|  %3.2f\n",vetorB[i]);
  }
}


float modulo(float x){
  if (x<0)
  return (x * -1);

  else
  return x;
}
