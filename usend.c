#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

# define BUFLEN 1024
int main( int argc, char* argv[])
{
 int  portnumber = atoi(argv[1]);
  
  int sockfd;
  char buffer[BUFLEN];
  char *messageStr= argv[2];
  struct sockaddr_in   receiverAddr;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  memset(&receiverAddr, 0, sizeof(receiverAddr));
  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_port = htons(portnumber);
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  sendto(sockfd, (const char *)messageStr, strlen(messageStr), 0, (const struct sockaddr *) &receiverAddr, sizeof(receiverAddr));
  printf(" Data Sent....\n");
  close(sockfd);
  return 0;
}

