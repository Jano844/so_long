/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:12:36 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/24 13:45:29 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (temp == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// int main()
// {
//     char str1[] = "Alle meine Entchen";
//     char *str2 = ft_strdup(str1);
//     char *str3 = strdup(str1);

//     printf("%s\n", str1);
//     printf("%s\n", str2);
//     printf("%s\n", str3);

//     free(str2);
//     free(str3);
//     return(0);
// }
