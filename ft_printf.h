/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:57:55 by klut              #+#    #+#             */
/*   Updated: 2016/12/21 11:06:27 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct		s_printlist
{
	char*			data;
	size_t			content_size;
	struct s_list	*next;
	char 			convertion_type;
	char*			f_array;
	char*			width_array;
	char*			preci_array;
	int 			m_flag;
	int 			z_flag;
	int 			p_flag;
	int 			s_flag;
	int 			h_flag;
	int 			min_width;
	int 			precision;
	int 			size;
	int 			priority;
	int 			specificator;
}					t_printlist;

int 				ft_printf(const char *arg_data, ...);
int					starting_sequence(const char *arg_data, va_list arguments);
char				*ft_bufiller(const char *s1, char s2);
int 				ft_flag_parcing(t_printlist *buffer, int i);
int 				ft_width_parcing(t_printlist *buffer, int i);
int 				ft_flagcheck(const char *arg_data, int i);
int 				ft_format_regime(const char *arg_data, int i, t_printlist *buffer);
void				*ft_bzero(void *s, size_t n);
int					ft_conv_buffering(const char *arg_data, int i,t_printlist *buffer);
char				*ft_strnew(size_t size);
void				ft_conv_init(t_printlist *buffer);
size_t				ft_strlen(const char *s);
int 				ft_precision_parcing(t_printlist *buffer, int i);
int 				ft_convletter(const char *arg_data, int i);
void				ft_hl(t_printlist *buffer, int num, char c);
int 				ft_processing(t_printlist *buffer, va_list arguments);
int 				ft_digits_cast_processing(t_printlist *buffer, va_list arguments);
int 				ft_unsigned_digits_processing(t_printlist *buffer, va_list arguments);
int					ft_d_convertion(t_printlist *buffer, long long int num);
int					ft_du_convertion(t_printlist *buffer, unsigned long int num);
int 				ft_memory_type_parc1(t_printlist *buffer, int i);
int 				ft_memory_type_parc2(t_printlist *buffer, int i);
char 				*ft_dies_proc(t_printlist *buffer, char *output, char *number);
char				*ft_space_filler(t_printlist *buffer, char *output, char *temp);
char				*ft_precision_filler(t_printlist *buffer, char *output, char *number);
char 				*ft_zeroproc(char *output, char *number, t_printlist *buffer);
char    			*ft_zeroprecision(t_printlist *buffer, char *output);
char 				*ft_stringproc(t_printlist *buffer, char *string);
char 				*ft_dig_output(char *output, char *number, t_printlist *buffer);
char				*ft_dig_output_u(char *output, char *number, t_printlist *buffer);
char				*ft_dig_output_uo(char *output, char *number, t_printlist *buffer);
char				*ft_itoa_base(long long int value, char *str, int base);
char				*ft_itoa_base_u(unsigned long int value, char *str, int base);
void				ft_f_ignore_checker_digit(t_printlist *buffer, char *number);
void				ft_sign_swap(char *output, char *number);
intmax_t			ft_s_cast(t_printlist *buffer, va_list arguments);
uintmax_t			ft_u_cast(t_printlist *buffer, va_list arguments);
int 				ft_charproc(t_printlist *buffer, int character);
char				*ft_whitechar_convertion(int character);
char				*ft_wproc2(char *wchar, char *temp1, wchar_t *output);
char 				*ft_strprecision(t_printlist *buffer, char *output);
int					ft_strprocessing(t_printlist *buffer, char *output);
int 				ft_letters_processing(t_printlist *buffer, va_list arguments);
char				*ft_cspace_filler(t_printlist *buffer, char *output, char *temp, int character);
int					ft_wstringprocessing(t_printlist *buffer, wchar_t *output);
int					ft_percent_processing(t_printlist *buffer);

#endif