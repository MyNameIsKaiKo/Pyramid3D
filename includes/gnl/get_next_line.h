/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:38:04 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/25 20:12:25 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> //open
# include <unistd.h> //read
# include <stdio.h> //ssize_t
# include <stdlib.h> //malloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
char	*gnl_strndup(char *s, size_t n);
char	*gnl_strjoin_and_free(char *s1, char *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);
size_t	gnl_strlen(char *s);

#endif
