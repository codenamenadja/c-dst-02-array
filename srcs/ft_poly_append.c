/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poly_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:31:16 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/05 18:58:04 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dst_array.h"

int ft_poly_append(t_poly **terms, t_poly **avail, unsigned char coef, unsigned char exp)
{
    t_poly  *new;

    if (avail - terms >= MAX_TERMS)
        return (0);

    new = malloc(sizeof(t_poly));
    new->exp = exp;
    new->coef = coef;
    *avail = new;
    return (avail - terms + 1);
}
