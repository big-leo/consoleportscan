/*
 Copyright (C) 2013 Bogdan Levkiv
 contact us at <raptor02 at ukr dot net>
 
 This program is free software of the GNU General Public License as published
 by the Free Software Foundation.
*/

#include "addr_to_int.h"

int *l_ip1, *l_ip2, *l_ip3, *l_ip4;
int i, j, next;
char addr_in[16], temp[4];

void set_ip();
int addr_to_int (char *all_ip, int *ip1, int *ip2, int *ip3, int *ip4)
{

memset (temp, ' ', strlen(temp));
memset (addr_in, '\0', sizeof(char) * 16);
memcpy(addr_in, all_ip, strlen(all_ip));
l_ip1 = ip1;
l_ip2 = ip2;
l_ip3 = ip3;
l_ip4 = ip4;

i = 0;
j = 0;
next = 1;

while (addr_in[i] != '\0')
 {
 if (addr_in[i] == '.')
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

if ((*ip1 > 0)&&(*ip2 >= 0)&&(*ip3 >= 0)&&(*ip4 > 0)) //for ipaddress
return 1;
if ((*ip1 > 0)&&(*ip2 == 0)&&(*ip3 == 0)&&(*ip4 == 0)) //for port
return 0;
else                                                   //for error
return -1;
}

void set_ip()
{
switch(next)
 {
 case 1:
 *l_ip1 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;

 case 2:
 *l_ip2 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;

 case 3:
 *l_ip3 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;

 case 4:
 *l_ip4 = atoi(temp);
 memset (temp, ' ', strlen(temp));
 break;
 }
}
