#ifndef __DST_ARRAY__
#define __DST_ARRAY__
#define MAX_TERM 8
#include <unistd.h>
typedef struct   m_term
{
    unsigned int    row;
    unsigned int    col;
    unsigned char   val;
}               t_term;

void    ft_transpose_mat(char **mat, size_t n);
t_term    **ft_transpose_triple(t_term **lst);
#endif
