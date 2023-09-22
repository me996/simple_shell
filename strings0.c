#include "shell.h"


int positive_num(char *s)
{
int i;
if (s == NULL)
return (0);
for (i = 0; s[i]; i++)
{
if (s[i] < '0' || s[i] > '9')
return (0);
}
return (1);
}



int _atoi(char *s)
{
int i, number = 0;
for (i = 0; s[i]; i++)
{
number *= 10;
number += (s[i] - '0');
}
return (number);
}

