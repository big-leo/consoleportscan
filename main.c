#include "main.h"

int main (int argc, char * argv[])
{
int p1, p2, socket1, port1 = 0, port2 = 0, ip1,   ip2,   ip3,   ip4,
                           ip1_1, ip1_2, ip1_3, ip1_4,
                           ip2_1, ip2_2, ip2_3, ip2_4;
char ipaddress1[16], ipaddress2[16];
struct sockaddr_in server1;

/*ip1 = (int *) malloc(sizeof(int));
ip2 = (int *) malloc(sizeof(int));
ip3 = (int *) malloc(sizeof(int));
ip4 = (int *) malloc(sizeof(int));

ip1_1 = (int *) malloc(sizeof(int));
ip1_2 = (int *) malloc(sizeof(int));
ip1_3 = (int *) malloc(sizeof(int));
ip1_4 = (int *) malloc(sizeof(int));

ip2_1 = (int *) malloc(sizeof(int));
ip2_2 = (int *) malloc(sizeof(int));
ip2_3 = (int *) malloc(sizeof(int));
ip2_4 = (int *) malloc(sizeof(int));

ipaddress1 = (char *) malloc(sizeof(char) * 16);
ipaddress2 = (char *) malloc(sizeof(char) * 16);
*/

if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
 {
 printf ("ERROR socket1\n");
 return 1;
 }

if (argc < 3)
 {
 printf("You most enter ipaddress(es) and/or port(s) computers for find his!\n");
 return 1;
 }

memset(ipaddress1, '\0', sizeof(char) * 16);
memset(ipaddress2, '\0', sizeof(char) * 16);
ip1_1 = ip1_2 = ip1_3 = ip1_4 =
ip2_1 = ip2_2 = ip2_3 = ip2_4 = 0;


 while (argc > 1)
  {
  ip1 = ip2 = ip3 = ip4 = 0;
  addr_to_int(argv[argc - 1], &ip1, &ip2, &ip3, &ip4);
  addr_to_int(argv[argc - 1], &ip1, &ip2, &ip3, &ip4);
  printf("argv[%d] = %s\n",(argc - 1),argv[argc - 1]);
  printf("ip1 = %d, ip2 = %d, ip3 = %d, ip4= %d\n", ip1, ip2, ip3, ip4);

//read ports
  if (ip4 == 0)
   {
   if (ip1 > 0)
    {
    if (port2 == 0)
     {
      port2 = ip1;
      printf ("port2 = %d\n", port2);
     }
    else
    {
    if (port1 == 0)
     {
      port1 = ip1;
      printf ("port1 = %d\n", port1);
     }
    }
    }
   }

//read addreses
  if (ip4 > 0)
   {
//for second address
   printf("ip1_4 = %d, ip2_4 = %d\n", ip1_4, ip2_4);
    if (ip2_4 == 0)
     {
     ip2_1 = ip1;
     ip2_2 = ip2;
     ip2_3 = ip3;
     ip2_4 = ip4;
     memset(ipaddress2, '\0', sizeof(char) * 16);
     memcpy(ipaddress2, argv[argc - 1], strlen(argv[argc -1]));
     printf("ip2_4 = %d\n", ip2_4);
     }
//for first address
    else
    {
    if (ip1_4 == 0)
     {
     ip1_1 = ip1;
     ip1_2 = ip2;
     ip1_3 = ip3;
     ip1_4 = ip4;
     memset(ipaddress1, '\0', sizeof(char) * 16);
     memcpy(ipaddress1, argv[argc - 1], strlen(argv[argc -1]));
     printf("ip1_4 = %d\n", ip1_4);
     }
    }
   }

  printf("argc = %d\n", argc);
  argc--;
  }

if ((port1 == 0)&&(ipaddress1[0] == '\0'))
 {
 //printf("From if OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
 memset(&server1, '0', sizeof(server1));
 server1.sin_family = AF_INET;
 server1.sin_port = htons(port2);
 server1.sin_addr.s_addr = inet_addr(ipaddress2);

 printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);

 if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1))  >= 0)
  {
  printf("connect to %d port on %s\n", port2, ipaddress2);
  }
 else
  {
  printf ("ERROR connect\n");
  return 1;
  }

 close(socket1);
 return 0;
 }

if (ipaddress1[0] == '\0')
 {
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 if (port2 > port1)
  {
  p1 = port1;
  p2 = port2;
  }
 else
  {
  p1 = port2;
  p2 = port1;
  }
 while (p1 <= p2)
 {
 if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
  {
  printf ("ERROR socket1\n");
  return 1;
  }
 
 memset(&server1, '0', sizeof(server1));
 server1.sin_family = AF_INET;
 server1.sin_port = htons(p1);
 server1.sin_addr.s_addr = inet_addr(ipaddress2);

 if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
  {
  printf("connect to %d port on %s\n", p1, ipaddress2);
  }

 close(socket1);
 p1++;
 }
 return 0;
 }


if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 == 0)&&(port2 != 0))
 {
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 if (ip1_4 < ip2_4)
  {
  p1 = ip1_4;
  p2 = ip2_4;
  }
 else
  {
  p1 = ip2_4;
  p2 = ip1_4;
  }
 while (p1 <= p2)
 {
 if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
  {
  printf ("ERROR socket1\n");
  return 1;
  }
 
 memset(ipaddress2, '\0', sizeof(char) * 16);
 sprintf(ipaddress2, "%d.%d.%d.%d", ip1_1, ip1_2, ip1_3, p1);

 memset(&server1, '0', sizeof(server1));
 server1.sin_family = AF_INET;
 server1.sin_port = htons(port2);
 server1.sin_addr.s_addr = inet_addr(ipaddress2);

 if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
  {
  printf("connect to %d port on %s\n", port2, ipaddress2);
  }

 close(socket1);
 p1++;
 }
 return 0;
 }

return 0;
}