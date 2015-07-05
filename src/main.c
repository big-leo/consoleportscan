/*
 Copyright (C) 2013 Bogdan Levkiv
 contact us at <raptor02 ukr dot net>
 
 This program is free software of the GNU General Public License as published
 by the Free Software Foundation.
*/

#include "main.h"

#define MAXPORT 5555
#define THREADS_MAX 55555

pthread_t thread1[THREADS_MAX];
struct pthread_arg arg[THREADS_MAX];
int socket1, fd1, result, i = 1, j = 0, id, temp = 1, port1 = 0, port2 = 0, port_or_address = 0,
                           ip11,  ip12,  ip13,  ip14,
                           ip21,  ip22,  ip23,  ip24,
                           ip1_1, ip1_2, ip1_3, ip1_4,
                           ip2_1, ip2_2, ip2_3, ip2_4;
char ipaddress1[16]={0}, ipaddress2[16]={0};
struct sockaddr_in server2;

int main (int argc, char * argv[])
{
 struct sockaddr_in server1;
 //fd1 = open ("log.txt", O_WRONLY|O_CREAT, 0640);

if (argc < 2)
 {
  fprintf(stderr, "You most enter ipaddress(es) up to two and/or port(s) of computers up to two for find his or these ranges!\n");
  return 1;
 }

if (argc > 5)
 {
  fprintf(stderr, "Very much arguments! Only 1-2(from one to two) port(s) and address(es)\n");
  return 1;
 }

memset(ipaddress1, '\0', sizeof(char) * 16);
memset(ipaddress2, '\0', sizeof(char) * 16);
ip1_1 = ip1_2 = ip1_3 = ip1_4 =
ip2_1 = ip2_2 = ip2_3 = ip2_4 = 0;

 while (argc > 1)
  {
   ip21 = ip22 = ip23 = ip24 = 0;
   port_or_address = addr_to_int(argv[argc - 1], &ip11, &ip12, &ip13, &ip14);

//read ports
  if (port_or_address == 0) //for 0 if port; 1 if address
  {
//for second port
   if (ip11 > 0)
    {
    if (port2 == 0)
     {
      port2 = ip11;
      //printf ("port2 = %d\n", port2);
     }
//for first port
    else
    {
    if (port1 == 0)
     {
      port1 = ip11;
      //printf ("port1 = %d\n", port1);
     }
    }
    }
   }

//read addreses
  if (port_or_address == 1)
   {
//for second address
    if (ip2_4 == 0)
     {
     ip2_1 = ip11;
     ip2_2 = ip12;
     ip2_3 = ip13;
     ip2_4 = ip14;
     memset(ipaddress2, '\0', sizeof(char) * 16);
     memcpy(ipaddress2, argv[argc - 1], strlen(argv[argc -1]));
     }
//for first address
    else
    {
    if (ip1_4 == 0)
     {
     ip1_1 = ip11;
     ip1_2 = ip12;
     ip1_3 = ip13;
     ip1_4 = ip14;
     memset(ipaddress1, '\0', sizeof(char) * 16);
     memcpy(ipaddress1, argv[argc - 1], strlen(argv[argc -1]));
     }
    }
   }

  argc--;
  }

//for find when bee enter only one address
if ((port1 == 0)&&(port2 == 0)&&(ipaddress1[0] == '\0')&&(ipaddress2[0] != '\0'))
 {
 fprintf(stderr, "for find when bee enter only one address\n");

 while (port2 < MAXPORT)
  {
  arg[j].addr = ipaddress2;
  arg[j].port = port2;
  if (j > 300)
  pthread_join(thread1[j-300], NULL);
  result = pthread_create(&thread1[j], NULL, &child, &arg[j]);
  if (result)
  fprintf(stderr, "ERROR thread %s:%d\n", arg[j].addr, arg[j].port);
  port2++;
  j++;
  if (j >= THREADS_MAX)
  j = 0;
  }
  /*while (j < THREADS_MAX)
  {
   pthread_join(thread1[j], NULL);
   j++;
  }*/
 
 return 0;
 }

//for find when bee enter two addreses
if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 == 0)&&(port2 == 0))
 {
 printf("for find when bee enter two addreses\n");
 if (ip1_1 < ip2_1)
  {
  ip11 = ip1_1;
  ip21 = ip2_1;
  ip12 = ip1_2;
  ip22 = ip2_2;
  ip13 = ip1_3;
  ip23 = ip2_3;
  ip14 = ip1_4;
  ip24 = ip2_4;
  }
 if (ip1_1 > ip2_1)
  {
  ip11 = ip2_1;
  ip21 = ip1_1;
  ip12 = ip2_2;
  ip22 = ip1_2;
  ip13 = ip2_3;
  ip23 = ip1_3;
  ip14 = ip2_4;
  ip24 = ip1_4;
  }
 if (ip1_1 == ip2_1)
  {
  if (ip1_2 < ip2_2)
   {
   ip11 = ip1_1;
   ip21 = ip2_1;
   ip12 = ip1_2;
   ip22 = ip2_2;
   ip13 = ip1_3;
   ip23 = ip2_3;
   ip14 = ip1_4;
   ip24 = ip2_4;
   }
  if (ip1_2 > ip2_2)
   {
   ip11 = ip2_1;
   ip21 = ip1_1;
   ip12 = ip2_2;
   ip22 = ip1_2;
   ip13 = ip2_3;
   ip23 = ip1_3;
   ip14 = ip2_4;
   ip24 = ip1_4;
   }
  if (ip1_2 == ip2_2)
   {
   if (ip1_3 < ip2_3)
    {
    ip11 = ip1_1;
    ip21 = ip2_1;
    ip12 = ip1_2;
    ip22 = ip2_2;
    ip13 = ip1_3;
    ip23 = ip2_3;
    ip14 = ip1_4;
    ip24 = ip2_4;
    }
   if (ip1_3 > ip2_3)
    {
    ip11 = ip2_1;
    ip21 = ip1_1;
    ip12 = ip2_2;
    ip22 = ip1_2;
    ip13 = ip2_3;
    ip23 = ip1_3;
    ip14 = ip2_4;
    ip24 = ip1_4;
    }
   if (ip1_3 == ip2_3)
    {
    if (ip1_4 < ip2_4)
     {
     ip11 = ip1_1;
     ip21 = ip2_1;
     ip12 = ip1_2;
     ip22 = ip2_2;
     ip13 = ip1_3;
     ip23 = ip2_3;
     ip14 = ip1_4;
     ip24 = ip2_4;
     }
    if (ip1_4 > ip2_4)
     {
     ip11 = ip2_1;
     ip21 = ip1_1;
     ip12 = ip2_2;
     ip22 = ip1_2;
     ip13 = ip2_3;
     ip23 = ip1_3;
     ip14 = ip2_4;
     ip24 = ip1_4;
     }
    if (ip1_4 == ip2_4)
     {
     ip11 = ip21 = ip1_1;
     ip12 = ip22 = ip1_2;
     ip13 = ip23 = ip1_3;
     ip14 = ip24 = ip1_4;
     }
    }
   }
  }
  
 while (ip11 <= ip21)
  {
   while ((ip12 <= ip22)||(ip11 <= ip21))
    {
    while ((ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
     {
     while ((ip14 <= ip24)||(ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
      {
      port2 = 1;
      while (port2 < MAXPORT)
       {
       arg[j].addr = (char *) malloc (sizeof(char) * 16);
       memset(arg[j].addr, '\0', sizeof(char) * 16);
       sprintf(arg[j].addr, "%d.%d.%d.%d", ip11, ip12, ip13, ip14);
       
       arg[j].port = port2;

       if (!pthread_equal(pthread_self(), thread1[j]))
        pthread_join(thread1[j], NULL);
       if (j > 300)
       pthread_join(thread1[j - 300], NULL);
       result = pthread_create(&thread1[j], NULL, child, &arg[j]);
       if (result)
       {
        fprintf(stderr, "ERROR thread %s:%d\n", arg[j].addr, arg[j].port);
        return 1;
       }
       free(arg[j].addr);
       port2++;
       j++;
       
       if (j >= THREADS_MAX)
        j = 0;
      //fprintf(stderr, "Whill bee from %d\n", j);
      }
      //printf("Whill bee from 4\n");
      if ((ip14 == ip24)&&(ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
       {
       break;
       }
      ip14++;
      if (ip14 == 255)
       {
       ip14 = 1;
       break;
       }
      }
     //printf("Whill bee from 3\n");
     if ((ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
     ip13++;
     if (ip13 == 255)
      {
      ip13 = 0;
      break;
      }
     }
    //printf("Whill bee from 2\n");
    if ((ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
    ip12++;
    if (ip12 == 255)
     {
     ip12 = 0;
     break;
     }
    }
  //printf("Whill bee from 1\n");
  if (ip11 == ip21)
   {
   break;
   }
  ip11++;
  if (ip11 == 255)
   {
   ip11 = 0;
   break;
   }
  }
 return 0;
 }


//for find when bee enter only one port
if ((ipaddress1[0] == '\0')&&(ipaddress2[0] == '\0')&&(port1 == 0)&&(port2 != 0))
 {
 printf("for find when bee enter one port\n");
 
 /*ip11 = 1;	ip21 = 254;
 ip12 = 0;	ip22 = 254;
 ip13 = 0;	ip23 = 254;
 ip14 = 1;	ip24 = 254;*/
 
 ip11 = 1;	ip21 = 254;
 ip12 = 0;	ip22 = 254;
 ip13 = 0;	ip23 = 254;
 ip14 = 1;	ip24 = 254;

 while (ip11 <= ip21)
  {
  while ((ip12 <= ip22)||(ip11 <= ip21))
    {
    while ((ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
     {
     while ((ip14 <= ip24)||(ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
      {
      arg[j].addr = (char *) malloc (sizeof(char) * 16);
      memset(arg[j].addr, '\0', sizeof(char) * 16);
      sprintf(arg[j].addr, "%d.%d.%d.%d", ip11, ip12, ip13, ip14);
      
      arg[j].port = port2;
      
      if (!pthread_equal(pthread_self(), thread1[j]))
       pthread_join(thread1[j], NULL);
      if (j > 300)
      pthread_join(thread1[j - 300], NULL);
      result = pthread_create(&thread1[j], NULL, child, &arg[j]);
      if (result)
      fprintf(stderr, "ERROR thread %s:%d\n", arg[j].addr, arg[j].port);
      free(arg[j].addr);
      j++;
      if (j >= THREADS_MAX)
       j = 0;
      
      //printf("Whill bee from 4\n");
      if ((ip14 == ip24)&&(ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
       {
        break;
       }
       ip14++;
      if (ip14 == 255)
       {
       ip14 = 1;
       break;
       }
      }
     //printf("Whill bee from 3\n");
     if ((ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
     ip13++;
     if (ip13 == 255)
      {
      ip13 = 0;
      break;
      }
     }
    //printf("Whill bee from 2\n");
    if ((ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
    ip12++;
    if (ip12 == 255)
     {
     ip12 = 0;
     break;
     }
    }
  printf("Whill bee from 1\n");
  if (ip11 == ip21)
   {
   break;
   }
  ip11++;
  if (ip11 == 255)
   {
   ip11 = 0;
   break;
   }
  }
 return 0;
 }


//for find when bee enter one port and one address
if ((port1 == 0)&&(port2 > 0)&&(ipaddress1[0] == '\0')&&(ipaddress2[0] != '\0'))
 {
 fprintf(stderr, "for find when bee enter one port and one address\n");
 
 if ((socket1 = socket(AF_INET, SOCK_STREAM, 0)) < 0)
 {
  fprintf(stderr, "ERROR create socket1\n");
 }
 
 memset(&server1, '\0', sizeof(server1));
 server1.sin_family = AF_INET;
 server1.sin_port = htons(port2);
 server1.sin_addr.s_addr = inet_addr(ipaddress2);

 if (connect(socket1, (struct sockaddr *) &server1, sizeof(server1))  >= 0)
  {
  printf("connect to %d port on %s\n", port2, ipaddress2);
  }
 else
  {
  printf ("ERROR connect to %d port on %s\n", port2, ipaddress2);
  return 1;
  }

 close(socket1);
 return 0;
 }

//for find when bee enter one port and two addreses
if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 == 0)&&(port2 > 0))
 {
 fprintf(stderr, "for find when bee enter one port and two addreses\n");
 if (ip1_1 < ip2_1)
  {
  ip11 = ip1_1;
  ip21 = ip2_1;
  ip12 = ip1_2;
  ip22 = ip2_2;
  ip13 = ip1_3;
  ip23 = ip2_3;
  ip14 = ip1_4;
  ip24 = ip2_4;
  }
 if (ip1_1 > ip2_1)
  {
  ip11 = ip2_1;
  ip21 = ip1_1;
  ip12 = ip2_2;
  ip22 = ip1_2;
  ip13 = ip2_3;
  ip23 = ip1_3;
  ip14 = ip2_4;
  ip24 = ip1_4;
  }
 if (ip1_1 == ip2_1)
  {
  if (ip1_2 < ip2_2)
   {
   ip11 = ip1_1;
   ip21 = ip2_1;
   ip12 = ip1_2;
   ip22 = ip2_2;
   ip13 = ip1_3;
   ip23 = ip2_3;
   ip14 = ip1_4;
   ip24 = ip2_4;
   }
  if (ip1_2 > ip2_2)
   {
   ip11 = ip2_1;
   ip21 = ip1_1;
   ip12 = ip2_2;
   ip22 = ip1_2;
   ip13 = ip2_3;
   ip23 = ip1_3;
   ip14 = ip2_4;
   ip24 = ip1_4;
   }
  if (ip1_2 == ip2_2)
   {
   if (ip1_3 < ip2_3)
    {
    ip11 = ip1_1;
    ip21 = ip2_1;
    ip12 = ip1_2;
    ip22 = ip2_2;
    ip13 = ip1_3;
    ip23 = ip2_3;
    ip14 = ip1_4;
    ip24 = ip2_4;
    }
   if (ip1_3 > ip2_3)
    {
    ip11 = ip2_1;
    ip21 = ip1_1;
    ip12 = ip2_2;
    ip22 = ip1_2;
    ip13 = ip2_3;
    ip23 = ip1_3;
    ip14 = ip2_4;
    ip24 = ip1_4;
    }
   if (ip1_3 == ip2_3)
    {
    if (ip1_4 < ip2_4)
     {
     ip11 = ip1_1;
     ip21 = ip2_1;
     ip12 = ip1_2;
     ip22 = ip2_2;
     ip13 = ip1_3;
     ip23 = ip2_3;
     ip14 = ip1_4;
     ip24 = ip2_4;
     }
    if (ip1_4 > ip2_4)
     {
     ip11 = ip2_1;
     ip21 = ip1_1;
     ip12 = ip2_2;
     ip22 = ip1_2;
     ip13 = ip2_3;
     ip23 = ip1_3;
     ip14 = ip2_4;
     ip24 = ip1_4;
     }
    if (ip1_4 == ip2_4)
     {
     ip11 = ip21 = ip1_1;
     ip12 = ip22 = ip1_2;
     ip13 = ip23 = ip1_3;
     ip14 = ip24 = ip1_4;
     }
    }
   }
  }
  
 while (ip11 <= ip21)
  {
  while ((ip12 <= ip22)||(ip11 <= ip21))
    {
    while ((ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
     {
     while ((ip14 <= ip24)||(ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
      {
      arg[j].addr = (char *) malloc (sizeof(char) * 16);
      memset(arg[j].addr, '\0', sizeof(char) * 16);
      sprintf(arg[j].addr, "%d.%d.%d.%d", ip11, ip12, ip13, ip14);

      arg[j].port = port2;
      
      if (!pthread_equal(pthread_self(), thread1[j]))
       pthread_join(thread1[j], NULL);
      if (j > 300)
      pthread_join(thread1[j - 300], NULL);
      result = pthread_create(&thread1[j], NULL, child, &arg[j]);
      if (result)
      fprintf(stderr, "ERROR thread %s:%d\n", arg[j].addr, arg[j].port);
      free(arg[j].addr);
      j++;
      if (j >= THREADS_MAX)
       j = 0;
      
      if ((ip14 == ip24)&&(ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
       {
       break;
       }
      ip14++;
      if (ip14 == 255)
       {
       ip14 = 1;
       break;
       }
      }
     if ((ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
     ip13++;
     if (ip13 == 255)
      {
      ip13 = 0;
      break;
      }
     }
    if ((ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
    ip12++;
    if (ip12 == 255)
     {
     ip12 = 0;
     break;
     }
    }
  if (ip11 == ip21)
   {
   break;
   }
  ip11++;
  if (ip11 == 255)
   {
   ip11 = 0;
   break;
   }
  }
 return 0;
 }

//for find when bee enter two ports
if ((ipaddress1[0] == '\0')&&(ipaddress2[0] == '\0')&&(port1 != 0)&&(port2 != 0))
 {
 fprintf(stderr, "for find when bee enter two ports\n");
 
 ip11 = 1;	ip21 = 254;
 ip12 = 0;	ip22 = 254;
 ip13 = 0;	ip23 = 254;
 ip14 = 1;	ip24 = 254;

 temp = port2;
 if(port1 < port2)
  {
  temp = port1;
  port1 = port2;
  port2 = temp;
  }

 while (ip11 <= ip21)
  {
  while ((ip12 <= ip22)||(ip11 <= ip21))
    {
    while ((ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
     {
     while ((ip14 <= ip24)||(ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
      {
      port2 = temp;
      while (port2 <= port1)
       {
        arg[j].addr = (char *) malloc (sizeof(char) * 16);
        memset(arg[j].addr, '\0', sizeof(char) * 16);
        sprintf(arg[j].addr, "%d.%d.%d.%d", ip11, ip12, ip13, ip14);
        
        arg[j].port = port2;
        
        if (!pthread_equal(pthread_self(), thread1[j]))
         pthread_join(thread1[j], NULL);
        if (j > 300)
        pthread_join(thread1[j - 300], NULL);
        result = pthread_create(&thread1[j], NULL, child, &arg[j]);
        if (result)
        fprintf(stderr, "ERROR thread %d %s:%d\n", j, arg[j].addr, arg[j].port);
        free(arg[j].addr);
        port2++;
        j++;
        if (j >= THREADS_MAX)
         j = 0;
       }
      //printf("Whill bee from 4\n");
      if ((ip14 == ip24)&&(ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
       {
       break;
       }
      ip14++;
      if (ip14 == 255)
       {
       ip14 = 1;
       break;
       }
      }
     //printf("Whill bee from 3\n");
     if ((ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
     ip13++;
     if (ip13 == 255)
      {
      ip13 = 0;
      break;
      }
     }
    //printf("Whill bee from 2\n");
    if ((ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
    ip12++;
    if (ip12 == 255)
     {
     ip12 = 0;
     break;
     }
    }
  //printf("Whill bee from 1\n");
  if (ip11 == ip21)
   {
   break;
   }
  ip11++;
  if (ip11 == 255)
   {
   ip11 = 0;
   break;
   }
  }
 return 0;
 }


//for find when bee enter two ports and one address
if ((port1 > 0)&&(port2 > 0)&&(ipaddress1[0] == '\0')&&(ipaddress2[0] != '\0'))
 {
 fprintf(stderr, "for find when bee enter two ports and one address\n");
 if (port2 > port1)
  {
  ip11 = port1;
  ip12 = port2;
  }
 else
  {
  ip11 = port2;
  ip12 = port1;
  }
 
 j = 0;
 while (ip11 <= ip12)
 {
  arg[j].addr = ipaddress2;
  arg[j].port = ip11;
  
  if (!pthread_equal(pthread_self(), thread1[j]))
   pthread_join(thread1[j], NULL);
  if (j > 300)
  pthread_join(thread1[j - 300], NULL);
  result = pthread_create(&thread1[j], NULL, child, &arg[j]);
  if (result)
  fprintf(stderr, "ERROR thread %s:%d\n", arg[j].addr, arg[j].port);
  j++;
  ip11++;
  if (j >= THREADS_MAX)
   j = 0;
 }
 return 0;
 }

//for find when bee enter two ports and two addreses
if ((ipaddress1[0] != '\0')&&(ipaddress2[0] != '\0')&&(port1 > 0)&&(port2 > 0))
 {
 fprintf(stderr, "for find when bee enter two ports and two addreses\n");
 
 if (ip1_1 < ip2_1)
  {
  ip11 = ip1_1;
  ip21 = ip2_1;
  ip12 = ip1_2;
  ip22 = ip2_2;
  ip13 = ip1_3;
  ip23 = ip2_3;
  ip14 = ip1_4;
  ip24 = ip2_4;
  }
 if (ip1_1 > ip2_1)
  {
  ip11 = ip2_1;
  ip21 = ip1_1;
  ip12 = ip2_2;
  ip22 = ip1_2;
  ip13 = ip2_3;
  ip23 = ip1_3;
  ip14 = ip2_4;
  ip24 = ip1_4;
  }
 if (ip1_1 == ip2_1)
  {
  if (ip1_2 < ip2_2)
   {
   ip11 = ip1_1;
   ip21 = ip2_1;
   ip12 = ip1_2;
   ip22 = ip2_2;
   ip13 = ip1_3;
   ip23 = ip2_3;
   ip14 = ip1_4;
   ip24 = ip2_4;
   }
  if (ip1_2 > ip2_2)
   {
   ip11 = ip2_1;
   ip21 = ip1_1;
   ip12 = ip2_2;
   ip22 = ip1_2;
   ip13 = ip2_3;
   ip23 = ip1_3;
   ip14 = ip2_4;
   ip24 = ip1_4;
   }
  if (ip1_2 == ip2_2)
   {
   if (ip1_3 < ip2_3)
    {
    ip11 = ip1_1;
    ip21 = ip2_1;
    ip12 = ip1_2;
    ip22 = ip2_2;
    ip13 = ip1_3;
    ip23 = ip2_3;
    ip14 = ip1_4;
    ip24 = ip2_4;
    }
   if (ip1_3 > ip2_3)
    {
    ip11 = ip2_1;
    ip21 = ip1_1;
    ip12 = ip2_2;
    ip22 = ip1_2;
    ip13 = ip2_3;
    ip23 = ip1_3;
    ip14 = ip2_4;
    ip24 = ip1_4;
    }
   if (ip1_3 == ip2_3)
    {
    if (ip1_4 < ip2_4)
     {
     ip11 = ip1_1;
     ip21 = ip2_1;
     ip12 = ip1_2;
     ip22 = ip2_2;
     ip13 = ip1_3;
     ip23 = ip2_3;
     ip14 = ip1_4;
     ip24 = ip2_4;
     }
    if (ip1_4 > ip2_4)
     {
     ip11 = ip2_1;
     ip21 = ip1_1;
     ip12 = ip2_2;
     ip22 = ip1_2;
     ip13 = ip2_3;
     ip23 = ip1_3;
     ip14 = ip2_4;
     ip24 = ip1_4;
     }
    if (ip1_4 == ip2_4)
     {
     ip11 = ip21 = ip1_1;
     ip12 = ip22 = ip1_2;
     ip13 = ip23 = ip1_3;
     ip14 = ip24 = ip1_4;
     }
    }
   }
  }
 
 temp = port2;
 if (port1 < port2)
 {
 temp = port1;
 port1 = port2;
 port2 = temp;
 }
 
 while (ip11 <= ip21)
  {
  while ((ip12 <= ip22)||(ip11 <= ip21))
    {
    while ((ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
     {
     while ((ip14 <= ip24)||(ip13 <= ip23)||(ip12 <= ip22)||(ip11 <= ip21))
      {
      i = port2;
      while (i <= port1)
      {
       arg[j].addr = (char *) malloc(sizeof(char) * 16);
       memset(arg[j].addr, '\0', sizeof(char) * 16);
       sprintf(arg[j].addr, "%d.%d.%d.%d", ip11, ip12, ip13, ip14);
       
       arg[j].port = i;
       
       if (!pthread_equal(pthread_self(), thread1[j]))
        pthread_join(thread1[j], NULL);
       if (j > 300)
       pthread_join(thread1[j - 300], NULL);
       result = pthread_create(&thread1[j], NULL, child, &arg[j]);
       if (result)
        {
        fprintf(stderr, "ERROR create thread %d %s:%d\n", j, arg[j].addr, arg[j].port);
        return 1;
        }
       free(arg[j].addr);
       j++;
       i++;
       if (j >= THREADS_MAX)
        j = 0;
      }
      if ((ip14 == ip24)&&(ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
       {
       break;
       }
      ip14++;
      if (ip14 == 255)
       {
       ip14 = 1;
       break;
       }
      }
     if ((ip13 == ip23)&&(ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
     ip13++;
     if (ip13 == 255)
      {
      ip13 = 0;
      break;
      }
     }
    if ((ip12 == ip22)&&(ip11 == ip21))
      {
      break;
      }
    ip12++;
    if (ip12 == 255)
     {
     ip12 = 0;
     break;
     }
    }
  if (ip11 == ip21)
   {
   break;
   }
  ip11++;
  if (ip11 == 255)
   {
   ip11 = 0;
   break;
   }
  }
 return 0;
 }

return 0;
}