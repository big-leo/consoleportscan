#include "main.h"
<<<<<<< HEAD
#define MAXPORT 1024

FILE *pFile;
int p1, p2, p3, p4, socket1, i = 1, temp = 1, port1 = 0, port2 = 0, ip1,   ip2,   ip3,   ip4,
=======

int main (int argc, char * argv[])
{
int p1, p2, socket1, port1 = 0, port2 = 0, ip1,   ip2,   ip3,   ip4,
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
                           ip1_1, ip1_2, ip1_3, ip1_4,
                           ip2_1, ip2_2, ip2_3, ip2_4;
char ipaddress1[16], ipaddress2[16];
struct sockaddr_in server1;

<<<<<<< HEAD
int main (int argc, char * argv[])
{
pFile = fopen ("log.txt","w");

if (argc < 2)
 {
 printf("You most enter ipaddress(es) up to two and/or port(s) of computers up to two for find his or these ranges!\n");
 return 1;
 }

if (argc > 5)
 {
 printf("Very much arguments! Only 1-2(from one to two) port(s) and address(es)\n");
=======
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
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
 return 1;
 }

memset(ipaddress1, '\0', sizeof(char) * 16);
memset(ipaddress2, '\0', sizeof(char) * 16);
ip1_1 = ip1_2 = ip1_3 = ip1_4 =
ip2_1 = ip2_2 = ip2_3 = ip2_4 = 0;

<<<<<<< HEAD
=======

>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
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
<<<<<<< HEAD
//for second port
=======
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
   if (ip1 > 0)
    {
    if (port2 == 0)
     {
      port2 = ip1;
      printf ("port2 = %d\n", port2);
     }
<<<<<<< HEAD
//for first port
=======
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
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

<<<<<<< HEAD
//for find when bee enter only one address
if ((port1 == 0)&&(port2 == 0)&&(ipaddress1[0] == '\0')&&(ipaddress2[0] != '\0'))
 {
 printf("for find when bee enter only one address\n");
 printf ("port1 = %d, port2 = %d, ipaddress1 = %s, ip1_1-4 = %d.%d.%d.%d, ipaddress2 = %s, ip2_1-4 = %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);

 i = 1;
 while (i <= MAXPORT)
  {
  if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
   {
   printf ("ERROR socket1\n");
   return 1;
   }

  memset(&server1, '0', sizeof(server1));
  server1.sin_family = AF_INET;
  server1.sin_port = htons(i);
  server1.sin_addr.s_addr = inet_addr(ipaddress2);

  if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1)) >= 0)
   {
   printf("connect to %d port on %s\n", i, ipaddress2);
   fprintf(pFile, "connect to %d port on %s\n", i, ipaddress2);
   }

  close(socket1);
  //printf("ip: %s	port: %d\n", ipaddress2, i);
  i++;
  }
 fclose (pFile);
 return 0;
 }

//for find when bee enter two addreses
if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 == 0)&&(port2 == 0))
 {
 printf("for find when bee enter two addreses\n");
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 if (ip1_1 < ip2_1)
  {
  p1 = ip1_1;
  ip1 = ip2_1;
  p2 = ip1_2;
  ip2 = ip2_2;
  p3 = ip1_3;
  ip3 = ip2_3;
  p4 = ip1_4;
  ip4 = ip2_4;
  }
 if (ip1_1 > ip2_1)
  {
  p1 = ip2_1;
  ip1 = ip1_1;
  p2 = ip2_2;
  ip2 = ip1_2;
  p3 = ip2_3;
  ip3 = ip1_3;
  p4 = ip2_4;
  ip4 = ip1_4;
  }
 if (ip1_1 == ip2_1)
  {
  if (ip1_2 < ip2_2)
   {
   p1 = ip1_1;
   ip1 = ip2_1;
   p2 = ip1_2;
   ip2 = ip2_2;
   p3 = ip1_3;
   ip3 = ip2_3;
   p4 = ip1_4;
   ip4 = ip2_4;
   }
  if (ip1_2 > ip2_2)
   {
   p1 = ip2_1;
   ip1 = ip1_1;
   p2 = ip2_2;
   ip2 = ip1_2;
   p3 = ip2_3;
   ip3 = ip1_3;
   p4 = ip2_4;
   ip4 = ip1_4;
   }
  if (ip1_2 == ip2_2)
   {
   if (ip1_3 < ip2_3)
    {
    p1 = ip1_1;
    ip1 = ip2_1;
    p2 = ip1_2;
    ip2 = ip2_2;
    p3 = ip1_3;
    ip3 = ip2_3;
    p4 = ip1_4;
    ip4 = ip2_4;
    }
   if (ip1_3 > ip2_3)
    {
    p1 = ip2_1;
    ip1 = ip1_1;
    p2 = ip2_2;
    ip2 = ip1_2;
    p3 = ip2_3;
    ip3 = ip1_3;
    p4 = ip2_4;
    ip4 = ip1_4;
    }
   if (ip1_3 == ip2_3)
    {
    if (ip1_4 < ip2_4)
     {
     p1 = ip1_1;
     ip1 = ip2_1;
     p2 = ip1_2;
     ip2 = ip2_2;
     p3 = ip1_3;
     ip3 = ip2_3;
     p4 = ip1_4;
     ip4 = ip2_4;
     }
    if (ip1_4 > ip2_4)
     {
     p1 = ip2_1;
     ip1 = ip1_1;
     p2 = ip2_2;
     ip2 = ip1_2;
     p3 = ip2_3;
     ip3 = ip1_3;
     p4 = ip2_4;
     ip4 = ip1_4;
     }
    if (ip1_4 == ip2_4)
     {
     p1 = ip1 = ip1_1;
     p2 = ip2 = ip1_2;
     p3 = ip3 = ip1_3;
     p4 = ip4 = ip1_4;
     }
    }
   }
  }
  
 while (p1 != (ip1 + 1))
  {
  while (!((p2 == (ip2 + 1))&(p1 == ip1)))
    {
    while (!((p3 == (ip3 + 1))&(p2 == ip2)))
     {
     while (!((p4 == (ip4 + 1))&(p3 == ip3)))
      {
      i = 1;
      while (i <= MAXPORT)
       {
       if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
        {
        printf ("ERROR socket1\n");
        return 1;
        }
       memset(ipaddress2, '\0', sizeof(char) * 16);
       sprintf(ipaddress2, "%d.%d.%d.%d", p1, p2, p3, p4);

       memset(&server1, '0', sizeof(server1));
       server1.sin_family = AF_INET;
       server1.sin_port = htons(i);
       server1.sin_addr.s_addr = inet_addr(ipaddress2);

       if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
        {
        printf("connect to %d port on %s\n", i, ipaddress2);
        fprintf(pFile, "connect to %d port on %s\n", i, ipaddress2);
        }

       close(socket1);
       //printf("ip: %d.%d.%d.%d port: %d\n", p1, p2, p3, p4, i);
       //fprintf(pFile, "ip: %d.%d.%d.%d port: %d\n", p1, p2, p3, p4, i);
       i++;
       }
      printf("Whill bee from 4\n");
      if ((p4 == ip4)&(p3 == ip3)&(p2 == ip2)&(p1 == ip1))
       {
       break;
       }
      p4++;
      if (p4 == 255)
       {
       p4 = 1;
       break;
       }
      }
     //printf("p3 = %d\n", p3);
     //fprintf(pFile, "p3 = %d\n", p3);
     printf("Whill bee from 3\n");
     if ((p3 == ip3)&(p2 == ip2)&(p1 == ip1))
      {
      break;
      }
     p3++;
     if (p3 == 255)
      {
      p3 = 0;
      break;
      }
     }
    //printf("p2 = %d\n", p2);
    //fprintf(pFile, "p2 = %d\n", p2);
    printf("Whill bee from 2\n");
    if ((p2 == ip2)&(p1 == ip1))
      {
      break;
      }
    p2++;
    if (p2 == 255)
     {
     p2 = 0;
     break;
     }
    }
  //printf("p1 = %d\n", p1);
  //fprintf(pFile, "p1 = %d\n", p1);
  printf("Whill bee from 1\n");
  if (p1 == ip1)
   {
   break;
   }
  p1++;
  if (p1 == 255)
   {
   p1 = 0;
   break;
   }
  }
 fclose (pFile);
 return 0;
 }


//for find when bee enter only one port
if ((ipaddress1[0] == '\0')&&(ipaddress2[0] == '\0')&&(port1 == 0)&&(port2 != 0))
 {
 printf("for find when bee enter one port\n");
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 
 p1 = 1;	ip1 = 255;
 p2 = 0;	ip2 = 255;
 p3 = 0;	ip3 = 255;
 p4 = 1;	ip4 = 255;

 while (p1 != (ip1 + 1))
  {
  while (!((p2 == (ip2 + 1))&(p1 == ip1)))
    {
    while (!((p3 == (ip3 + 1))&(p2 == ip2)))
     {
     while (!((p4 == (ip4 + 1))&(p3 == ip3)))
      {
      i = port2;
       if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
        {
        printf ("ERROR socket1\n");
        return 1;
        }
       memset(ipaddress2, '\0', sizeof(char) * 16);
       sprintf(ipaddress2, "%d.%d.%d.%d", p1, p2, p3, p4);

       memset(&server1, '0', sizeof(server1));
       server1.sin_family = AF_INET;
       server1.sin_port = htons(i);
       server1.sin_addr.s_addr = inet_addr(ipaddress2);

       if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
        {
        printf("connect to %d port on %s\n", i, ipaddress2);
        fprintf(pFile, "connect to %d port on %s\n", i, ipaddress2);
        }

       close(socket1);
       printf("ip: %d.%d.%d.%d port: %d\n", p1, p2, p3, p4, i);
       //fprintf(pFile, "ip: %d.%d.%d.%d port: %d\n", p1, p2, p3, p4, i);
       i++;
      printf("Whill bee from 4\n");
      if ((p4 == ip4)&(p3 == ip3)&(p2 == ip2)&(p1 == ip1))
       {
       break;
       }
      p4++;
      if (p4 == 255)
       {
       p4 = 1;
       break;
       }
      }
     //printf("p3 = %d\n", p3);
     //fprintf(pFile, "p3 = %d\n", p3);
     printf("Whill bee from 3\n");
     if ((p3 == ip3)&(p2 == ip2)&(p1 == ip1))
      {
      break;
      }
     p3++;
     if (p3 == 255)
      {
      p3 = 0;
      break;
      }
     }
    //printf("p2 = %d\n", p2);
    //fprintf(pFile, "p2 = %d\n", p2);
    printf("Whill bee from 2\n");
    if ((p2 == ip2)&(p1 == ip1))
      {
      break;
      }
    p2++;
    if (p2 == 255)
     {
     p2 = 0;
     break;
     }
    }
  //printf("p1 = %d\n", p1);
  //fprintf(pFile, "p1 = %d\n", p1);
  printf("Whill bee from 1\n");
  if (p1 == ip1)
   {
   break;
   }
  p1++;
  if (p1 == 255)
   {
   p1 = 0;
   break;
   }
  }
 fclose (pFile);
 return 0;
 }


//for find when bee enter one port and one address
if ((port1 == 0)&&(port2 > 0)&&(ipaddress1[0] == '\0')&&(ipaddress2[0] != '\0'))
=======
if ((port1 == 0)&&(ipaddress1[0] == '\0'))
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
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
<<<<<<< HEAD
  fprintf(pFile, "connect to %d port on %s\n", port2, ipaddress2);
  }
 else
  {
  printf ("ERROR connect to %d port on %s\n", port2, ipaddress2);
  fprintf(pFile, "ERROR connect to %d port on %s\n", port2, ipaddress2);
=======
  }
 else
  {
  printf ("ERROR connect\n");
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
  return 1;
  }

 close(socket1);
<<<<<<< HEAD
 fclose (pFile);
 return 0;
 }

//for find when bee enter one port and two addreses
if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 == 0)&&(port2 > 0))
 {
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 if (ip1_1 < ip2_1)
  {
  p1 = ip1_1;
  ip1 = ip2_1;
  p2 = ip1_2;
  ip2 = ip2_2;
  p3 = ip1_3;
  ip3 = ip2_3;
  p4 = ip1_4;
  ip4 = ip2_4;
  }
 if (ip1_1 > ip2_1)
  {
  p1 = ip2_1;
  ip1 = ip1_1;
  p2 = ip2_2;
  ip2 = ip1_2;
  p3 = ip2_3;
  ip3 = ip1_3;
  p4 = ip2_4;
  ip4 = ip1_4;
  }
 if (ip1_1 == ip2_1)
  {
  if (ip1_2 < ip2_2)
   {
   p1 = ip1_1;
   ip1 = ip2_1;
   p2 = ip1_2;
   ip2 = ip2_2;
   p3 = ip1_3;
   ip3 = ip2_3;
   p4 = ip1_4;
   ip4 = ip2_4;
   }
  if (ip1_2 > ip2_2)
   {
   p1 = ip2_1;
   ip1 = ip1_1;
   p2 = ip2_2;
   ip2 = ip1_2;
   p3 = ip2_3;
   ip3 = ip1_3;
   p4 = ip2_4;
   ip4 = ip1_4;
   }
  if (ip1_2 == ip2_2)
   {
   if (ip1_3 < ip2_3)
    {
    p1 = ip1_1;
    ip1 = ip2_1;
    p2 = ip1_2;
    ip2 = ip2_2;
    p3 = ip1_3;
    ip3 = ip2_3;
    p4 = ip1_4;
    ip4 = ip2_4;
    }
   if (ip1_3 > ip2_3)
    {
    p1 = ip2_1;
    ip1 = ip1_1;
    p2 = ip2_2;
    ip2 = ip1_2;
    p3 = ip2_3;
    ip3 = ip1_3;
    p4 = ip2_4;
    ip4 = ip1_4;
    }
   if (ip1_3 == ip2_3)
    {
    if (ip1_4 < ip2_4)
     {
     p1 = ip1_1;
     ip1 = ip2_1;
     p2 = ip1_2;
     ip2 = ip2_2;
     p3 = ip1_3;
     ip3 = ip2_3;
     p4 = ip1_4;
     ip4 = ip2_4;
     }
    if (ip1_4 > ip2_4)
     {
     p1 = ip2_1;
     ip1 = ip1_1;
     p2 = ip2_2;
     ip2 = ip1_2;
     p3 = ip2_3;
     ip3 = ip1_3;
     p4 = ip2_4;
     ip4 = ip1_4;
     }
    if (ip1_4 == ip2_4)
     {
     p1 = ip1 = ip1_1;
     p2 = ip2 = ip1_2;
     p3 = ip3 = ip1_3;
     p4 = ip4 = ip1_4;
     }
    }
   }
  }
  
 while (p1 != (ip1 + 1))
  {
  while (!((p2 == (ip2 + 1))&(p1 == ip1)))
    {
    while (!((p3 == (ip3 + 1))&(p2 == ip2)))
     {
     while (!((p4 == (ip4 + 1))&(p3 == ip3)))
      {
      if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
       {
       printf ("ERROR socket1\n");
       return 1;
       }
 
      memset(ipaddress2, '\0', sizeof(char) * 16);
      sprintf(ipaddress2, "%d.%d.%d.%d", p1, p2, p3, p4);

      memset(&server1, '0', sizeof(server1));
      server1.sin_family = AF_INET;
      server1.sin_port = htons(port2);
      server1.sin_addr.s_addr = inet_addr(ipaddress2);

      if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
       {
       printf("connect to %d port on %s\n", port2, ipaddress2);
       fprintf(pFile, "connect to %d port on %s\n", port2, ipaddress2);
       }

      close(socket1);
      //printf("ip: %d.%d.%d.%d\n", p1, p2, p3, p4);
      //fprintf(pFile, "ip: %d.%d.%d.%d\n", p1, p2, p3, p4);
      if ((p4 == ip4)&(p3 == ip3)&(p2 == ip2)&(p1 == ip1))
       {
       break;
       }
      p4++;
      if (p4 == 255)
       {
       p4 = 1;
       break;
       }
      }
     //printf("p3 = %d\n", p3);
     //fprintf(pFile, "p3 = %d\n", p3);
     if ((p3 == ip3)&(p2 == ip2)&(p1 == ip1))
      {
      break;
      }
     p3++;
     if (p3 == 255)
      {
      p3 = 0;
      break;
      }
     }
    //printf("p2 = %d\n", p2);
    //fprintf(pFile, "p2 = %d\n", p2);
    if ((p2 == ip2)&(p1 == ip1))
      {
      break;
      }
    p2++;
    if (p2 == 255)
     {
     p2 = 0;
     break;
     }
    }
  //printf("p1 = %d\n", p1);
  //fprintf(pFile, "p1 = %d\n", p1);
  if (p1 == ip1)
   {
   break;
   }
  p1++;
  if (p1 == 255)
   {
   p1 = 0;
   break;
   }
  }
 fclose (pFile);
 return 0;
 }

//for find when bee enter two ports
if ((ipaddress1[0] == '\0')&&(ipaddress2[0] == '\0')&&(port1 != 0)&&(port2 != 0))
 {
 printf("for find when bee enter two ports\n");
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 
 p1 = 1;	ip1 = 255;
 p2 = 0;	ip2 = 255;
 p3 = 0;	ip3 = 255;
 p4 = 1;	ip4 = 255;

 temp = port2;
 if(port1 < port2)
  {
  temp = port1;
  port1 = port2;
  }

 while (p1 != (ip1 + 1))
  {
  while (!((p2 == (ip2 + 1))&(p1 == ip1)))
    {
    while (!((p3 == (ip3 + 1))&(p2 == ip2)))
     {
     while (!((p4 == (ip4 + 1))&(p3 == ip3)))
      {
      i = temp;
      while (i <= port1)
       {
       if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
        {
        printf ("ERROR socket1\n");
        return 1;
        }
       memset(ipaddress2, '\0', sizeof(char) * 16);
       sprintf(ipaddress2, "%d.%d.%d.%d", p1, p2, p3, p4);

       memset(&server1, '0', sizeof(server1));
       server1.sin_family = AF_INET;
       server1.sin_port = htons(i);
       server1.sin_addr.s_addr = inet_addr(ipaddress2);

       if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
        {
        printf("connect to %d port on %s\n", i, ipaddress2);
        fprintf(pFile, "connect to %d port on %s\n", i, ipaddress2);
        }

       close(socket1);
       printf("ip: %d.%d.%d.%d port: %d\n", p1, p2, p3, p4, i);
       //fprintf(pFile, "ip: %d.%d.%d.%d port: %d\n", p1, p2, p3, p4, i);
       i++;
       }
      //printf("Whill bee from 4\n");
      if ((p4 == ip4)&(p3 == ip3)&(p2 == ip2)&(p1 == ip1))
       {
       break;
       }
      p4++;
      if (p4 == 255)
       {
       p4 = 1;
       break;
       }
      }
     //printf("p3 = %d\n", p3);
     //fprintf(pFile, "p3 = %d\n", p3);
     //printf("Whill bee from 3\n");
     if ((p3 == ip3)&(p2 == ip2)&(p1 == ip1))
      {
      break;
      }
     p3++;
     if (p3 == 255)
      {
      p3 = 0;
      break;
      }
     }
    //printf("p2 = %d\n", p2);
    //fprintf(pFile, "p2 = %d\n", p2);
    //printf("Whill bee from 2\n");
    if ((p2 == ip2)&(p1 == ip1))
      {
      break;
      }
    p2++;
    if (p2 == 255)
     {
     p2 = 0;
     break;
     }
    }
  //printf("p1 = %d\n", p1);
  //fprintf(pFile, "p1 = %d\n", p1);
  //printf("Whill bee from 1\n");
  if (p1 == ip1)
   {
   break;
   }
  p1++;
  if (p1 == 255)
   {
   p1 = 0;
   break;
   }
  }
 fclose (pFile);
 return 0;
 }


//for find when bee enter two ports and one address
if ((port1 > 0)&&(port2 > 0)&&(ipaddress1[0] == '\0')&&(ipaddress2[0] != '\0'))
=======
 return 0;
 }

if (ipaddress1[0] == '\0')
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
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
<<<<<<< HEAD
  fprintf(pFile, "connect to %d port on %s\n", p1, ipaddress2);
=======
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
  }

 close(socket1);
 p1++;
 }
<<<<<<< HEAD
 fclose (pFile);
 return 0;
 }

//for find when bee enter two ports and two addreses
if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 > 0)&&(port2 > 0))
 {
 printf("for find when bee enter two ports and two addreses\n");
 //printf ("port1 = %d, port2 = %d, ipaddress1 = %s, %d.%d.%d.%d, ipaddress2 = %s, %d.%d.%d.%d\n", port1, port2, ipaddress1, ip1_1, ip1_2, ip1_3, ip1_4, ipaddress2, ip2_1, ip2_2, ip2_3, ip2_4);
 if (ip1_1 < ip2_1)
  {
  p1 = ip1_1;
  ip1 = ip2_1;
  p2 = ip1_2;
  ip2 = ip2_2;
  p3 = ip1_3;
  ip3 = ip2_3;
  p4 = ip1_4;
  ip4 = ip2_4;
  }
 if (ip1_1 > ip2_1)
  {
  p1 = ip2_1;
  ip1 = ip1_1;
  p2 = ip2_2;
  ip2 = ip1_2;
  p3 = ip2_3;
  ip3 = ip1_3;
  p4 = ip2_4;
  ip4 = ip1_4;
  }
 if (ip1_1 == ip2_1)
  {
  if (ip1_2 < ip2_2)
   {
   p1 = ip1_1;
   ip1 = ip2_1;
   p2 = ip1_2;
   ip2 = ip2_2;
   p3 = ip1_3;
   ip3 = ip2_3;
   p4 = ip1_4;
   ip4 = ip2_4;
   }
  if (ip1_2 > ip2_2)
   {
   p1 = ip2_1;
   ip1 = ip1_1;
   p2 = ip2_2;
   ip2 = ip1_2;
   p3 = ip2_3;
   ip3 = ip1_3;
   p4 = ip2_4;
   ip4 = ip1_4;
   }
  if (ip1_2 == ip2_2)
   {
   if (ip1_3 < ip2_3)
    {
    p1 = ip1_1;
    ip1 = ip2_1;
    p2 = ip1_2;
    ip2 = ip2_2;
    p3 = ip1_3;
    ip3 = ip2_3;
    p4 = ip1_4;
    ip4 = ip2_4;
    }
   if (ip1_3 > ip2_3)
    {
    p1 = ip2_1;
    ip1 = ip1_1;
    p2 = ip2_2;
    ip2 = ip1_2;
    p3 = ip2_3;
    ip3 = ip1_3;
    p4 = ip2_4;
    ip4 = ip1_4;
    }
   if (ip1_3 == ip2_3)
    {
    if (ip1_4 < ip2_4)
     {
     p1 = ip1_1;
     ip1 = ip2_1;
     p2 = ip1_2;
     ip2 = ip2_2;
     p3 = ip1_3;
     ip3 = ip2_3;
     p4 = ip1_4;
     ip4 = ip2_4;
     }
    if (ip1_4 > ip2_4)
     {
     p1 = ip2_1;
     ip1 = ip1_1;
     p2 = ip2_2;
     ip2 = ip1_2;
     p3 = ip2_3;
     ip3 = ip1_3;
     p4 = ip2_4;
     ip4 = ip1_4;
     }
    if (ip1_4 == ip2_4)
     {
     p1 = ip1 = ip1_1;
     p2 = ip2 = ip1_2;
     p3 = ip3 = ip1_3;
     p4 = ip4 = ip1_4;
     }
    }
   }
  }
 
 temp = port2;
 if (port1 < port2)
 {
 temp = port1;
 port1 = port2;
 }
 
 while (p1 != (ip1 + 1))
  {
  while (!((p2 == (ip2 + 1))&(p1 == ip1)))
    {
    while (!((p3 == (ip3 + 1))&(p2 == ip2)))
     {
     while (!((p4 == (ip4 + 1))&(p3 == ip3)))
      {
      i = temp;
      while (i <= port1)
      {
      if ((socket1 = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
       {
       printf ("ERROR socket1\n");
       return 1;
       }
 
      memset(ipaddress2, '\0', sizeof(char) * 16);
      sprintf(ipaddress2, "%d.%d.%d.%d", p1, p2, p3, p4);

      memset(&server1, '0', sizeof(server1));
      server1.sin_family = AF_INET;
      server1.sin_port = htons(i);
      server1.sin_addr.s_addr = inet_addr(ipaddress2);

      if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1) )  >= 0)
       {
       printf("connect to %d port on %s\n", i, ipaddress2);
       fprintf(pFile, "connect to %d port on %s\n", i, ipaddress2);
       }

      close(socket1);
      i++;
      }
     //printf("ip: %d.%d.%d.%d\n", p1, p2, p3, p4);
     //fprintf(pFile, "ip: %d.%d.%d.%d\n", p1, p2, p3, p4);
      if ((p4 == ip4)&(p3 == ip3)&(p2 == ip2)&(p1 == ip1))
       {
       break;
       }
      p4++;
      if (p4 == 255)
       {
       p4 = 1;
       break;
       }
      }
     //printf("p3 = %d\n", p3);
     //fprintf(pFile, "p3 = %d\n", p3);
     if ((p3 == ip3)&(p2 == ip2)&(p1 == ip1))
      {
      break;
      }
     p3++;
     if (p3 == 255)
      {
      p3 = 0;
      break;
      }
     }
    //printf("p2 = %d\n", p2);
    //fprintf(pFile, "p2 = %d\n", p2);
    if ((p2 == ip2)&(p1 == ip1))
      {
      break;
      }
    p2++;
    if (p2 == 255)
     {
     p2 = 0;
     break;
     }
    }
  //printf("p1 = %d\n", p1);
  //fprintf(pFile, "p1 = %d\n", p1);
  if (p1 == ip1)
   {
   break;
   }
  p1++;
  if (p1 == 255)
   {
   p1 = 0;
   break;
   }
  }
 fclose (pFile);
=======
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
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020
 return 0;
 }

return 0;
}