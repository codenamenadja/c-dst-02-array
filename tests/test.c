#include <stdlib.h>
#include <unistd.h>
#include "dst_array.h"

void    free_mat(char **mat)
{
    char **mat_pt;
    size_t  len;

    mat_pt = mat;

    while (*mat_pt)
    {
        len = strlen(*mat_pt);
        write(STDOUT_FILENO, *mat_pt, len);
        free(*mat_pt++); 
    }
    free(mat);
}

int main(int argc, const char *argv[])
{
    char    **mat;
    size_t  len;
    size_t  i;

    len = strlen(*(argv+1));

    if ((size_t)(argc + 1) != len)
        return (EXIT_FAILURE);

    i = 0;
    mat = (char **)malloc(sizeof(char *) * (len + 1));
    while (i < len)
    {
        if (strlen(*(argv + i + 1)) != len)
        {
            free_mat(mat);
            return (EXIT_FAILURE);
        }

        *(mat + i) = strdup(*(argv + i + 1));
        i++;
    }
    *(mat + i) = NULL;
    ft_transpose_mat(mat, len);
    free_mat(mat);

    return (EXIT_SUCCESS);
}
