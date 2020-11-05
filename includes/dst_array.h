#ifndef __DST_ARRAY__
#define __DST_ARRAY__
#define MAX_TERM 8
#define MAX_TERMS 20
#include <unistd.h>
typedef struct   m_term
{
    unsigned int    row;
    unsigned int    col;
    unsigned char   val;
}               t_term;

void        ft_transpose_mat(char **mat, size_t n);
t_term      **ft_transpose_triple(t_term **lst);

typedef struct  m_poly
{
    unsigned char   coef;
    unsigned char   exp;
}               t_poly;

int         ft_poly_cmp(t_poly *dst, t_poly *src);
int         ft_poly_append(t_poly **terms, t_poly **avail, unsigned char coef, unsigned char exp);
t_poly      **ft_poly_add(t_poly **terms, t_poly **as, t_poly **ae, t_poly **bs, t_poly **be, t_poly **avail);

#endif
