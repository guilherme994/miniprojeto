#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

  char* p_end;
  int calculo;

  if(argc != 4) {
    printf("Para utilizar insira o primeiro numero, espaco, operador, espaco e por fim o segundo numero.\n");
    printf("Ficando assim:\n5 + 5\n5 -5\n5 x 5\n5 / 5");
    return 1;
  }
  int n_1 = strtol(argv[1], &p_end, 10);
  int n_2 = strtol(argv[3], &p_end, 10);


  if(!strcmp(argv[2], "+")) {
    calculo = n_1 + n_2;
  }
  else if(!strcmp(argv[2], "-")) {
    calculo = n_1 - n_2;
  }
  else if(!strcmp(argv[2], "/")) {
    if(n_2 == 0){
      printf("Nao e possivel fazer divisao por 0.");
      return 1;
    }
    else calculo = n_1 / n_2;
  }
  else if(!strcmp(argv[2], "x")) {
    calculo = n_1 * n_2;
  }
  else {
    printf("Para utilizar insira o primeiro numero, espaco, operador, espaco e por fim o segundo numero.\n");
    printf("Ficando assim:\n5 + 5\n5 -5\n5 x 5\n5 / 5");
    return 1;
  }

  printf("Resultado: %d\n", calculo);

  return 0;
  }
