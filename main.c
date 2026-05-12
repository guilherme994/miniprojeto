#include <stdio.h>
#include "parser.h"
#include "operacoes.h"

int main(int argc, char* argv[])  {

  if(argc != 4) {
    printf("Para utilizar insira o primeiro numero, espaco, operador, espaco e por fim o segundo numero.\n");
    printf("Ficando assim:\n5 + 5\n5 - 5\n5 x 5\n5 / 5");
    return 1;
  }

  int n_1, n_2;
  if(parser_num(argv[1], &n_1) != 0){
    printf("O valor do primeiro NUMERO inserido nao e valido.\nDeve conter o seguinte formato 'NUMERO' espaco 'OPERADOR' espaco 'NUMERO'.\n");
    return 1;
  }

  if(parser_num(argv[3], &n_2) != 0){
    printf("O valor do segundo NUMERO inserido nao e valido.\nDeve conter o seguinte formato 'NUMERO' espaco 'OPERADOR' espaco 'NUMERO'.\n");
    return 1;
  }
  char operator = parser_operator(argv[2]);
  int resultado;
  switch (operator) {
    case '+': resultado = soma(n_1, n_2);       break;
    case '-': resultado = subtrai(n_1, n_2);     break;
    case 'x': resultado = multiplica(n_1, n_2); break;
    case '/':
      if(n_2 == 0){
        printf("Erro: Nao e possivel fazer divisao por 0.\n");
        return 1;
      }
      resultado = divide(n_1, n_2);
      break;
    default:
      printf("O operador inserido nao e valido.\nDeve conter o seguinte formato 'NUMERO' espaco 'OPERADOR' espaco 'NUMERO'.\nOperadores validos '+', '-', '/', 'x'.\n");
      return 1;
  }
  
  printf("A operacao %d %c %d = %d\n",n_1, operator, n_2, resultado);
  return 0;
}
