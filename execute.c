#include "shell.h" 

int _execute (char *command, **argv)
{
    pid_t child;
    int status;
    child = fork();
    if (child == 0)
    {
        if (execve(command [0], command, environ) == -1)
        {
            perror(argv[0]);
            freestring(command);
        }
     
    }
    else 
    {
        waitpid(child, &status, 0);
        freestring(command);
    }
    return(WEXITSTATUS(status));
}
