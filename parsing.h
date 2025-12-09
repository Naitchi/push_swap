/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:36:20 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/09 17:36:20 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"


int ft_isspace(char c);
int is_split_needed(char *str);
void parsing (int argc, char *argv[]);
int	ft_atoi(const char *str);

#endif
