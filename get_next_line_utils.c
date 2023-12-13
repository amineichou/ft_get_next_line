/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:16:08 by moichou           #+#    #+#             */
/*   Updated: 2023/12/13 14:58:49 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *first, char *second)
{
    char *res;
    if (!first && !second)
        return (NULL);
    if (!first)
        return (strdup(second));
    if (!second)
        return (strdup(first));
    res = malloc(sizeof(char) * (strlen(first) + strlen(second) + 1));
    if (!res)
        return (NULL);
    int i = 0;
    int j = 0;
    while (first[j])
    {
        res[i] = first[j];
        i++;
        j++;
    }
    j = 0;
    while (second[j])
    {
        res[i] = second[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}

// returns the index of the first accurence of c
int ft_strsearch(char *str, char c)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (0);
}
