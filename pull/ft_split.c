/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:32:08 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/21 15:47:05 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_clear(char **rslt, int nbr_elems)
{
	int	i;

	i = 0;
	while (i < nbr_elems)
	{
		free(rslt[i]);
		i++;
	}
	free(rslt);
	return (NULL);
}

static int	count_word_len(char const *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	return (i);
}

static int	count_elemnts(char const *s)
{
	int	count;
	int	lf_word;
	int	i;

	i = 0;
	count = 0;
	lf_word = 1;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			lf_word = 1;
		if (!ft_isspace(s[i]) && lf_word)
		{
			lf_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*copy_word(char const *s)
{
	char	*rslt;
	int		i;
	int		len;

	i = 0;
	len = count_word_len(s);
	rslt = malloc(len + 1);
	if (!rslt)
		return (NULL);
	while (i < len)
	{
		rslt[i] = s[i];
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}

char	**ft_split(char const *s)
{
	char	**rslt;
	int		nbr_elems;
	int		j;

	nbr_elems = count_elemnts(s);
	j = 0;
	rslt = malloc(sizeof(char *) * (nbr_elems + 1));
	if (rslt == NULL)
		return (NULL);
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (!ft_isspace(*s) && *s)
		{
			rslt[j] = copy_word(s);
			if (rslt[j])
				j++;
			s += count_word_len(s);
		}
	}
	rslt[j] = NULL;
	if (j != nbr_elems)
		rslt = ft_clear(rslt, nbr_elems);
	return (rslt);
}

// int main(void)
// {
//     const char *tests[] = {
//         "1 23 d6d 89 5d 654d    65465",
//         "",
//         "   ",
//         "a\tb\nc",
//         "single",
//         "  leading",
//         "trailing  ",
//         NULL
//     };

//     for (int t = 0; tests[t]; t++)
//     {
//         printf("Test %d: input: \"%s\"\n", t, tests[t]);
//         char **res = ft_split(tests[t]);
//         if (!res)
//         {
//             printf("  -> (null)\n\n");
//             continue ;
//         }
//         if (!res[0])
//         {
//             printf("  -> (empty)\n\n");
//             free(res);
//             continue ;
//         }
//         for (int i = 0; res[i]; i++)
//         {
//             printf("  [%d] \"%s\"\n", i, res[i]);
//             free(res[i]);
//         }
//         free(res);
//         printf("\n");
//     }
//     return (0);
// }
