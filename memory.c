#include "shell.h"
/**
 * freeleak - Free memory allocated for an array of strings.
 * @array: The array of strings to be freed.
 */
void freeleak(char **array)
{
int i;
if(!array)
return;
for (i = 0; array[i]; i++)	
free(array[i]), array[i] = NULL;
free(array), array = NULL;
}
