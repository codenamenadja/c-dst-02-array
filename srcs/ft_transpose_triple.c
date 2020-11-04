/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transpose_triple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:30:23 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/04 17:58:00 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dst_array.h"

t_term    **ft_transpose_triple(t_term **lst)
{
    unsigned char       len;
    unsigned char       i;
    t_term              **lst_pt;

    len = ((*lst)->val);
    i = 0;
    lst_pt = lst + 1;
    
    while (i++ < len)
    {
        (*lst_pt)->row = (*lst)->row - (*lst_pt)->row;
        (*lst_pt)->col = (*lst)->col - (*lst_pt)->col;
        lst_pt++;
    }

    return (lst);
}

