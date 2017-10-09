#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float modulo(float x);
void apresenta(int N,float M[N][N]);
void apresentaV(int N,float V[N]);

void main(){
  int i,j,k,N,linha;
  float pivo,max,aux,multiplicador;

  printf("METODO FATORACAO LU.\n\n");

  printf("Digite a ordem da matriz:");
  scanf("%d",&N);

  float M[N][N],L[N][N],U[N][N];
  float vetorB[N],vetorY[N],vetorX[N];

  for(i=0;i<N;i++){ // Ler a Matriz
    for (j=0;j<N;j++){
      printf("Elemento [%d][%d]:",i,j);
      scanf("%f",&M[i][j]);
      L[i][j] = 0;
    }

    printf("Posicao %d do vetor B: ",i);
    scanf("%f",&vetorB[i]);
    L[i][i] = 1;
  }

  for (i=0;i<N;i++){
    pivo = M[i][i];

    for (j=i+1;j<N;j++){

      multiplicador = M[j][i]/pivo;
      L[j][i] = multiplicador;
      M[j][i] = 0;
      vetorB[j] -= multiplicador * vetorB[i];

      for (k=i+1;k<=N;k++){
        M[j][k] -= multiplicador * M[i][k];
      }
    }
  }

  // LY = B;
  vetorY[0] = vetorB[0];
  for (i = 1;i < N;i++){
    aux = 0;
    for (j = 0; j < i; j++){
      aux += M[i][j] * vetorY[j];
      vetorY[i] = (vetorB[i] - aux);
    }
  }

  //UX = Y;
  vetorX[N-1] = vetorY[N-1] / M[N-1][N-1];
  for (i = N-2; i >= 0; i--){
    aux = 0;
    for (j = i; j < N; j++){
      aux += M[i][j] * vetorX[j];
      vetorX[i] = (vetorY[i] - aux)/M[i][i];
    }
  }

  printf("Matriz U:\n");
  apresenta(N,U);

  printf("Matriz L:\n");
  apresenta(N,L);

  printf("Matriz M:\n");
  apresenta(N,M);

  printf("Vetor X:\n");
  apresentaV(N,vetorX);

  printf("Vetor Y:\n");
  apresentaV(N,vetorY);
}

void apresentaV(int N,float V[N]){
  int i;
  for (i=0;i<N;i++){
    printf("%3.2f\n",V[i]);
  }
}

void apresenta(int N,float M[N][N]){
  int i,j;
  for(i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("%3.2f\t",M[i][j]);
    }
    printf("\n");
  }
}


float modulo(float x){
  if (x<0)
  return (x * -1);

  else
  return x;
}
