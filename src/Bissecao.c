#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float func(float x);
float modulo(float x);

void main(){
  int N,k=0;
  float fa=0,fm=0,a,b,m,delta,raiz;

  printf("METODO DA BISSECCAO. f(x) = x^3 - 1/2\n");

do{
  printf("\nIntervalo Inferior:");
  scanf("%f",&a);
  printf("Intervalo Superior:");
  scanf("%f",&b);

  if (func(a)*func(b)>0)
  printf("Intervalo Invalido digite novamente.\n");
  else
  break;

}while (1);


  printf("Numero MAX de interacoes:");
  scanf("%d",&N);

  printf("Precisao:");
  scanf("%f",&delta);

  if (modulo(b-a) < delta)
  raiz = (b+a)/2;

  while ((modulo(b-a) > delta) && (k<N)){

    k++;
    fa = func(a);
    m = ((b+a)/2);
    fm = func(m);

    printf("\nInteração:%d\nAproximacao:%.4f\nA:%.2f\tF(a):%.4f\nB:%.2f\nM:%.2f\tF(M)%.4f\n",k,modulo(b-a),a,fa,b,m,fm);

    if ((fa*fm) > 0){
      a = m;
    }
    else{
      b = m;
    }
  }

  raiz = ((a+b)/2);
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
