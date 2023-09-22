#include "shell.h"
void printerror(char *name, char *cmd, int cpt)
{
char *idx, message[] = ": not found\n";
idx = _itoa(cpt);
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, idx, _strlen(idx));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, message, _strlen(message));
free(idx), idx = NULL;
}
char *_itoa(int s)
{
char buffer[10];
int i = 0;
if (s == 0)
buffer[i++] = '0';
else 
{
while (s > 0)
{
buffer[i++]= (s % 10) + '0';
s /= 10;
}
}
buffer[i] = '\0';
reverse_string(buffer, i);
return (_strdup(buffer));
}
void reverse_string(char *s, int len)
{
char cpy;
int begin = 0;
int last = len -1;
while (begin < last)
{
cpy = s[begin];
s[begin] = s[last];
s[last] = cpy;
begin++;
last--;
}
}

