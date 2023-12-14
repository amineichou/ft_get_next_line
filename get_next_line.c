/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:15:54 by moichou           #+#    #+#             */
/*   Updated: 2023/12/14 11:08:33 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// free str after using it
char *ft_read(int fd, char *result)
{
    char *buffer;
    int count;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (free(result), NULL);
    count = 1;
    while (count > 0 && ft_strsearch(result, '\n') == 0)
    {
        count = read(fd, buffer, BUFFER_SIZE);
        if (count == -1)
            return (free(buffer), free(result), NULL);
        buffer[count] = '\0';
        result = ft_strjoin(result, buffer);
        if (count == 0)
            break;
    }
    return (free(buffer), buffer = NULL, result);
}

char *ft_extract_line(char *result)
{
    char *str;
    int i = 0;
    int j;

    if (!result || *result == '\0')
        return (NULL);
    while (result[i] != '\n' && result[i])
        i++;
    if (result[i] == '\n')
        i++;
    str = malloc(sizeof(char) * i + 1);
    if (!str)
        return (free(result), NULL);
    j = 0;
    while (j < i)
    {
        str[j] = result[j];
        j++;
    }
    str[j] = '\0';
    return (str);
}

char *ft_extract_rest(char *result)
{
    char *str;
    int i;
    int j;

    i = 0;
    while (result[i] != '\n' && result[i])
        i++;
    if (result[i] == '\n')
        i++;
    if (*result == '\0')
        return (free(result), NULL);
    str = malloc(sizeof(char) * strlen(result + i) + 1);
    if (!str)
        return (free(result), NULL);
    j = 0;
    while (result[i] != '\0')
    {
        str[j] = result[i];
        j++;
        i++;
    }
    str[j] = '\0';
    return (free(result), str);
}

// free line after using it
char *get_next_line(int fd)
{
    static char *result;
    char *line;

    if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
        return (NULL);
    if (!result)
    {
        result = ft_strdup("");
        if (!result)
            return (NULL);
    }
    result = ft_read(fd, result);
    if (!result)
        return (free(result),result = NULL, NULL);
    line = ft_extract_line(result);
    if (!line)
        return (free(result),result = NULL, NULL);
    result = ft_extract_rest(result);
    if (!result)
        return (NULL);
    return (line);
}

// int main(void)
// {
//     int fd = open("hello", 2);
//     if (fd == -1)
//     {
//         printf("error fd");
//         return 0;
//     }
//     char *line = get_next_line(fd);
//     return (0);
// }
