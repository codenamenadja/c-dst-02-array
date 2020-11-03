/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:47:12 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/03 16:56:51 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int transpose_mat(char **mat, int n);

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

#include <stdio.h>
int main(int argc, const char *argv[])
{
    char    **mat;
    size_t  len;
    size_t  i;

    len = strlen(*(argv+1));
    i = 0;
    printf("c:%d,", argc);
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
    free_mat(mat);

    return (EXIT_SUCCESS);
}
