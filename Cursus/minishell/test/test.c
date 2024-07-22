
#include "test.h"
#include "string.h"
#include <unistd.h>



int main(int argc, char **argv, char **envp)
{
 
    (void)argc;
    (void)argv;

     // Premier tableau
    // char *command1[] = {"ls", "-la", NULL};

    // Deuxième tableau
    char *command2[] = {"/usr/bin/ls", "-la", NULL};

    char * path = "/usr/bin/ls";

    // char *str = calloc(50, sizeof(char));
    // strncpy(str, "echo $\"USER\"   '${USER}' $'USER ", 50);

   execve(path,command2,envp);
    printf("\n");
    return 0;
}
