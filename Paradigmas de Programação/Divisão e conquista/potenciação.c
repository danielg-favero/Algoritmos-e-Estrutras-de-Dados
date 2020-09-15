#include <stdio.h>
#include <stdlib.h>

//a função recebe dois número inteiros, a base e o expoente respectivamente
int power(int a, int n){
  int x;
  
  //3 casos bases
  //1 - O expoente for 0
  //2 - O expoente for 1
  //3 - O expoente for diferente de 0 e 1
  if(n == 0){
    return 1;
  } else if (n == 1){
    return a;
  } else {
  
    //É possível dividir o problema em dois casos
    //se n for par e se n for ímpar
    if(n % 2 == 0){
      x = power(a, n / 2);
      
      return x * x;
    } else {
      x = power(a, (n-1)/2);

      return x * x * a;
    }
  }

}
