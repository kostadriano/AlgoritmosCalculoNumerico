#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float modulo(float x);
float func(float x);
float funclinha(float x);

void main(){
  int N,k=0;
  float f0=0,flinha=0,x0,x1,delta,raiz,aux;

  printf("METODO DE NEWTON. f(x) = x³ - 1/2  . f'(x) = 3*x² \n\n");

  do {
    printf("Aproximacao Inicial (Diferente de 0):");
    scanf("%f",&x0);
  }while(x0 == 0);

  printf("Numero MAX de interacoes:");
  scanf("%d",&N);

  printf("Precisao:");
  scanf("%f",&delta);

  f0 = func(x0);

  if (modulo(f0)<delta){
    raiz = x0;
    printf("Aproximacao Inicial eh Raiz : %.2f\n",raiz);
    exit(1);
  }

  k=1;

  while (1){
    flinha = funclinha(x0);
    f0 = func(x0);

    x1 =(x0-(f0/flinha));

    printf("\nInteração:%d\nAproximacao:%.4f\nx0:%4.2f\tF(x0):%.4f\nx1:%4.2f\tF(x1)%.4f\n",k,modulo(x0-x1),x0,func(x0),x1,func(x1));

    if (modulo((func(x1))<=delta)||(modulo(x0-x1)<delta)||(k>N)){
      raiz = x1;
      break;
    }

    x0=x1;
    k++;
  }
  printf("\nInteracoes = %d\nRaiz aproximada = %.3f\n",k,raiz);
}

float modulo(float x){
  if (x<0)
  return (x * -1);

  else
  return x;
}

float funclinha(float x){
  float resultado;
  resultado  = 3*(x*x);
  return resultado;
}

float func(float x){
  float resultado;
  resultado = ((x*x*x)-(0.5));
  return resultado;
}
