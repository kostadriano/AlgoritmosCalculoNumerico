#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float modulo(float x);
float func(float x);

void main(){
  int N,k=0;
  float f0=0,f1=0,f2=0,x0,x1,x2,delta,raiz,aux;

  printf("METODO DA SECANTE. f(x) = x^3 - 1/2\n\n");

  printf("Aproximacao Inicial:");
  scanf("%f",&x0);
  printf("Aproximacao Inicial:");
  scanf("%f",&x1);

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

  f1 = func(x1);

  if (modulo(f1)<delta){
    raiz = x1;
    printf("Aproximacao Inicial eh Raiz : %.2f\n",raiz);
    exit(1);
  }

  k=1;

  while (1){
    x2 = x1-((func(x1)*(x1-x0))/(func(x1)-func(x0)));

    f2 = modulo(func(x2));

    printf("\nInteração:%d\nAproximacao:%.4f\nx0:%4.2f\tF(x0):%.4f\nx1:%4.2f\tF(x1)%.4f\nx2:%4.2f\tF(x2)%.4f\n",k,modulo(x1-x2),x0,func(x0),x1,func(x1),x2,func(x2));

    if ((f2<=delta)||(modulo(x1-x2)<delta)||(k>N)){
      raiz = x2;
      break;
    }

    x0=x1;
    x1=x2;
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


float func(float x){
  float resultado;
  resultado = ((x*x*x)-(0.5));
  return resultado;
}
