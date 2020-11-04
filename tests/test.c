#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dst_array.h"
#include "dbg.h"

void    free_mat(char **mat)
{
    char **mat_pt;
    size_t  len;

    mat_pt = mat;

    while (*mat_pt)
    {
        len = strlen(*mat_pt);
        write(STDOUT_FILENO, *mat_pt, len);
        write(STDOUT_FILENO, "\n", 1);
        free(*mat_pt++); 
    }
    free(mat);
}

void    free_term(t_term **lst)
{
    unsigned char  len;
    int i;

    len = (*lst)->val;
    i = 0;
    
    while (i <= len)
    {
        debug("i : %d", i);
        debug("row: %u, col: %u, value: %c", 
        (*(lst + i))->row, (*(lst + i))->col, (*(lst + i))->val);
        free(*(lst + i));
        i++;
    }
    free(lst);
}

t_term      **init_terms(const char *argv[], unsigned int len)
{
    unsigned int     j;
    unsigned int     i;
    char     val;
    t_term  **ret;
    t_term  **ret_pt;

    i = 0;
    val = 0;
    
    while (i < len)
    {
        j = 0;
        while ((*((*(argv + i)) + j)) != '\0')
        {
            if ((*((*(argv + i)) + j)) != '0')
                val++;
            j++;
        }
        i++;
    }

    ret = (t_term **)malloc(sizeof(t_term *) * (val + 1));
    *ret = malloc(sizeof(t_term));
    (*ret)->col = j;
    (*ret)->row = len;
    (*ret)->val = val;
    ret_pt = ret + 1;
 
    i = 0;
    val = 0;
    
    while (i < len)
    {
        j = 0;
        while ((*(*(argv + i) + j)) != '\0')
        {
            if ((*(*(argv + i) + j)) != '0')
            {
                val = (*(*(argv + i) + j));
                (*ret_pt) = malloc(sizeof(t_term));
                (*ret_pt)->col = j;
                (*ret_pt)->row = i;
                (*ret_pt)->val = val;
                ret_pt++;
            }    
            j++;
        }
        i++;
    }   
    return (ret);
}

int test_transpose_triple(int argc, const char *argv[])
{
    t_term      **lst;

    lst = init_terms(argv+1, argc-1);
    ft_transpose_triple(lst);
    free_term(lst);

    return (EXIT_SUCCESS);
}
int test_transpose_mat(int argc, const char *argv[])
{
    char    **mat;
    size_t  len;
    size_t  i;

    len = strlen(*(argv+1));

    if ((size_t)(argc - 1) != len)
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



int main(int argc, const char *argv[])
{
    int success;
    int failure;

    success = 0;
    failure = 0;

    debug("---- RUN TEST----");
    test_transpose_mat(argc, argv) ? failure++ : success++;
    test_transpose_triple(argc, argv);
    
    
}
