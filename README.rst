DST Array in C
==============

01 TRANSPOSE_MAT
----------------

``void ft_transpose_mat(char **mat, int len)``

- DESC::

   Convert matrix to Transpose matrix.
   
- PARAMS::

   mat
      2-dimensions of digit-characters with len size dimension and len size of string.

   len
      number of elements in ``mat``

- RETURNS::

    None

02 TRANSPOSE_TRIPLE
-------------------

.. code-block:: c

   typedef struct   m_term
   {
       unsigned int     row;
       unsigned int     col;
       unsigned char    val;
   }                t_term;

   t_term    **ft_transpose_triple(t_term **lst);


- DESC::

   Convert matrix-t_term to Transpose matrix.
   
- PARAMS::

   lst 
      2-dimensions of digit-characters converted as t_term data.
      first poiter refers to size of 2-dimensions and its val means non 0, length of **t_term.
      since val exists, it doesn't ends with NULL terminates.

- RETURNS::

   ``t_term **`` with twisted row and col of t_term structs excepts first pointer

03 POLY_ADD
-----------

.. code-block:: c
    
   #define MAX_TERMS 20

   typedef struct  m_poly
   {
       unsigned char   coef;
       unsigned char   exp;
   }               t_poly;

   int         ft_poly_cmp(t_poly *dst, t_poly *src);
   int         ft_poly_append(t_poly **terms, t_poly **avail, unsigned char coef, unsigned char exp);
   t_poly      **ft_poly_add(t_poly **terms, t_poly **as, t_poly **ae, t_poly **bs, t_poly **be, t_poly **avail);

- DESC::

   summation two polynomial in array, and appends to its end of array.

- PARAMS::

   terms
      An array storing type of model of polynomials.

   as, bs
      A pointer of A-polynomial and B-polynomial meaning Start of that.

   ae, be
      A pointer of A-polynomial and B-polynomial meaning End of that.

   avail
      An End + 1 address of ``be`` initially, changes as it appends,
      meaning sequence to append on edge of ``terms``
      basically storing non Polynomial data. excepts reaches to MAX_TERMS.

- RETURNS::

   A Pointer that delegetes the new allocated start point in ``terms`` array.
