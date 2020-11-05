/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poly_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:10:47 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/05 19:11:02 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dst_array.h"

t_poly  p_terms[MAX_TERMS];

t_poly      **ft_poly_add(t_poly *terms[], t_poly **as, t_poly **ae, t_poly **bs, t_poly **be, t_poly **avail)
{
    unsigned char   coef;
    unsigned char   exp;
    int             cmp;

    while (as < (ae + 1) && bs < (be + 1))
    {
        cmp = ft_poly_cmp(*as, *bs);
        if (!cmp)
        {
            coef = (*as)->coef + (*bs)->coef;
            exp = (*as)->exp + (*bs)->exp;
            as++;
            bs++;
        } else if (cmp > 0) {
            coef = (*as)->coef;
            exp = (*as)->exp;
            as++;
        } else {
            coef = (*bs)->coef;
            exp = (*bs)->exp;
            bs++;
        }
        ft_poly_append(terms, avail, coef, exp)
        avail++;
    }
    if (as < ae)
    {
        while(as != ae)
        {
            coef = (*as)->coef;
            exp = (*as)->exp;
            as++;
            ft_poly_append(terms, avail, coef, exp);
            avail++;
        }
        coef = (*as)->coef;
        exp = (*as)->exp;
        ft_poly_append(terms, avail, coef, exp)
    } else {
        while(bs != be)
        {
            coef = (*bs)->coef;
            exp = (*bs)->exp;
            bs++;
            ft_poly_append(terms, avail, coef, exp);
            avail++;
        }
        coef = (*bs)->coef;
        exp = (*bs)->exp;
        ft_poly_append(terms, avail, coef, exp)
    }
    return (be + 1);
}
