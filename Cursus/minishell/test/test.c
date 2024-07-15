
#include "test.h"
#include "string.h"

char **create_own_env()
{
    char **array;
    array = malloc(5 * sizeof(char *));
    array[0] = strdup(ENV_USER);
    array[1] = strdup(ENV_HOME);
    array[2] = strdup(ENV_PWD);
    array[3] = strdup(ENV_PATH);
    array[4] = NULL;
    return array;
}

int main(int argc, char **argv, char **envp)
{
    t_data(data) = {0};
    (void)argc;
    (void)argv;

    int size = 0;

    if (envp[0]!= NULL)

    {
        while (envp[size] != NULL)
            size++;
        data.shell_env = malloc((size + 1) * sizeof(char *));

        int i = 0;
        while (envp[i] != NULL)
        {
            data.shell_env[i] = strdup(envp[i]);
            i++;
        }
        data.shell_env[i] = NULL;
    }
    else
    data.shell_env = create_own_env();

    // char *str = calloc(50, sizeof(char));
    // strncpy(str, "echo $\"USER\"   '${USER}' $'USER ", 50);

    for (char **env = data.shell_env; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }

    return 0;
}
