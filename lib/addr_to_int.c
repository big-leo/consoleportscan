#include "addr_to_int.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>


int *l_ip1, *l_ip2, *l_ip3, *l_ip4;
int i, j, next;
char addr_in[16], temp[4];

void set_ip();
int addr_to_int (char *all_ip, int *ip1, int *ip2, int *ip3, int *ip4)
{

//printf("Hellooooooooooooooooooooooooooooooo\n");

memset (temp, ' ', strlen(temp));
memset (addr_in, '\0', sizeof(char) * 16);
memcpy(addr_in, all_ip, strlen(all_ip));
//addr_in = all_ip;
l_ip1 = ip1;
l_ip2 = ip2;
l_ip3 = ip3;
l_ip4 = ip4;

i = 0;
j = 0;
next = 1;

//while (i < 16)
//while((i < 16)&&(addr_in[i] != '\0'))
while (addr_in[i] != '\0')
 {
 if (addr_in[i] == '.')
 //if (all_ip[i] == '.')
  {
  i++;
  j = 0;
  set_ip();
  next++;
  }
 if ((addr_in[i] >= '0')||(addr_in[i] <= '9'))
  {
  switch (next)
   {
   case 1:
   temp[j] = addr_in[i];
   j++;
   break;

   case 2:
   temp[j] = addr_in[i];
   j++;
   break;

   case 3:
   temp[j] = addr_in[i];
   j++;
   break;

   case 4:
   temp[j] = addr_in[i];
   j++;
   break;
   }
  }
 else
  {
  printf ("ERROR 0-9\n");
  }
 i++;
 }
set_ip();

//printf("*ip1 = %d, *ip2 = %d, *ip3 = %d, *ip4 = %d, temp = %s, all_ip = %s\n", *ip1, *ip2, *ip3, *ip4, temp, all_ip);

return 0;
}

void set_ip()
{
switch(next)
 {
 case 1:
 //printf ("1 temp = %s\n", temp);
 *l_ip1 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;

 case 2:
 //printf ("2 temp = %s\n", temp);
 *l_ip2 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;

 case 3:
 //printf ("3 temp = %s\n", temp);
 *l_ip3 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;

 case 4:
 //printf ("4 temp = %s\n", temp);
 *l_ip4 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;
 }
}
