/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transpose_mat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:25:16 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/03 17:26:41 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_transpose_mat(char **mat, size_t n)
{
    size_t i, j;
    char buf;

    i = 0;
    n--;

    while (i <= (n - i))
    {
        j = 0;
        while (j <= n)
        {
            buf = *(*(mat + i) + j);
            *(*(mat + i) + j) = *(*(mat + n - i) + n - j);
            *(*(mat + n - i) + n - j) = buf;
            j++;
        }
        i++;
    }
}

