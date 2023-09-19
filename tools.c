#include "shell.h"

void freestring (char **array)
{
if (!array)
return;
for (i = 0; array[i]; i++)
{
    free(array[i]);
    array[i] = NULL;
}
free(array), array = NULL;
}