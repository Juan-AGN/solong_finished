/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:00:05 by juan-ant          #+#    #+#             */
/*   Updated: 2023/09/23 19:23:23 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	char			*ret;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ret = malloc(1 + l1 + l2 * sizeof(char));
	if (ret == NULL)
		return (0);
	ft_strlcpy(ret, s1, l1 + 1);
	ft_strlcat(ret, s2, l1 + l2 + 1);
	return (ret);
}
