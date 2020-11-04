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
