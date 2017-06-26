#include "common-server.h"

int handle_connection(int sockfd, per_connection_handler_t handler) {
  setvbuf(stdout, NULL, _IONBF, 0);

  dup2(sockfd, STDIN_FILENO);
  dup2(sockfd, STDOUT_FILENO);
  dup2(sockfd, STDERR_FILENO);

  handler();

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  return 0;
}

int serve_forever(unsigned short port, per_connection_handler_t handler) {
  int sck = 0;
  int client = 0;
  int addrlen = 0;
  struct sockaddr_in this_addr, peer_addr;
  pid_t child_pid;

  addrlen = sizeof( struct sockaddr_in );
  memset( &this_addr, 0, addrlen );
  memset( &peer_addr, 0, addrlen );

  this_addr.sin_port        = htons(port);
  this_addr.sin_family      = AF_INET;
  this_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  sck = socket( AF_INET, SOCK_STREAM, IPPROTO_IP);
  setsockopt( sck, SOL_SOCKET, SO_REUSEADDR, (int[]){1}, sizeof(int));
  if ( bind( sck, (struct sockaddr*) &this_addr, addrlen ) != 0) {
    perror("Error binding socket");
    exit(1);
  }
  if ( listen( sck, 5 ) ) {
    perror("Error listening on socket");
    exit(1);
  }

  signal(SIGCHLD, SIG_IGN);

  while( -1 != (client = accept( sck, (struct sockaddr*) &peer_addr, &addrlen ) ) ) {
    child_pid = fork();
    
    if ( child_pid < 0 ) {
      perror("Error forking");
      close(client);
      exit(1);
    } else if ( child_pid > 0 ) {
      close(client);
    } else { // child_pid == 0
      handle_connection(client, handler);
      close(client);
      exit(1);
    }
  }
}
