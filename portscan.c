#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int meuSocket; //variável que representa o socket na máquina cliente e que recebe um inteiro que representa a porta
  int conecta; //recebe 0 se a conexão com o servidor foi feita com sucesso
  int porta; //indica a porta do servidor a ser conectada
  int inicio = 0; //menor valor de porta possível
  int fim = 65535; //maior valor de porta possível
  char *destino; //variável que recebe o endereço IP passado pelo usuário
  
  if(argc < 2){ //verifica se o argumento, endereço IP do servidor, foi passado pelo usuário
    printf("Exemplo de uso: %s \"IP_ALVO\" \n", argv[0]);
    exit(1);
  }
  destino = argv[1]; //passa o IP passado pelo usuário para a variável destino
  struct sockaddr_in alvo; //estrutura do socket, que recebe os dados do servidor a ser conectado e o tipo de socket
  
  //loop para incrementar o número de porta e tentar conectar em todas as portas que estiverem disponíveis no servidor
  for(porta=inicio; porta<=fim; porta++) {
    //cria o socket
    meuSocket = socket(AF_INET, SOCK_STREAM, 0);
    alvo.sin_family = AF_INET;
    alvo.sin_addr.s_addr = inet_addr(destino); //passa o endereço IP do servidor
    alvo.sin_port = htons(porta); //passa a porta do servidor
    //conecta com o servidor
    conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo); //cast
    if(conecta == 0){ //se conectou ao servidor, significa que a porta está aberta
      printf("Porta %d - status [Aberta] \n", porta);
    }
    close(meuSocket); //fecha o socket
    close(conecta); //fecha a conexão
  }
  return 1;
}
