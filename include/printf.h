/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:44:37 by sksourou          #+#    #+#             */
/*   Updated: 2015/03/09 02:44:48 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "colors.h"

typedef enum	e_color
{
	E_RED = 1,
	E_GREEN,
	E_BLUE,
	E_MAGENTA,
	E_CYAN,
	E_END
}				t_color;

typedef struct	s_infos
{
	char		*flag;
	int			width;
	int			prec;
	char		*modif;
	char		conv;
	int			color;
}				t_infos;

typedef struct	s_chkstr
{
	int			return_val;
	int			tmp;
}				t_chkstr;

typedef struct	s_wc
{
	int			i;
	int			ret;
	int			tmp;
	int			tmp2;
}				t_wc;

int				ft_strcmp(char const *s1, char const *s2);
int				ft_atoi(char const *s);
long long int	ft_atoi_long(char *s);
char			*ft_itoa(int n);
char			*ft_itoa_long(long long int n);
char			*ft_uitoa(unsigned int n);
char			*ft_uitoa_long(unsigned long int n);
size_t			ft_strlen(char const *s);
char			*ft_strrev(char const *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
void			*ft_memcpy(void *dst, void const *src, size_t n);
int				wstrlen(wchar_t *s);

/*		printf.c		*/
int				ft_printf(const char *rfmt, ...);
int				check_string(char *s, va_list arg, t_infos *new, t_chkstr *chk);
void			no_conv(char *s, int c, t_infos *infos, t_chkstr *chk);
int				no_conv_spec(char *s, int c, t_chkstr *chk);
int				check_if_another_percent(char *s, int c, t_chkstr *chk);
/*		init.c			*/
t_chkstr		*init_chkstr(t_chkstr *chk);
int				detect_infos(char *s, int c, t_infos *new);
int				define_convert(va_list arg, t_infos *infos);
int				define_convert2(va_list arg, t_infos *infos, int val);
int				define_convert3(va_list arg, t_infos *infos, int val);
/*		search_infos.c	*/
char			*search_flag(char *s, int c);
char			*ft_help_flag(char *s, int i);
char			skip_spaces(char *s, int c);
char			search_conv(char *s, int c);
/*		search_infos2.c	*/
int				search_width(char *s, int c);
int				search_prec(char *s, int c);
char			*search_modif(char *s, int c, char conv);
char			*search_char(char *s, int c);
/*		colors.c		*/
int				check_colors(char *s, int c, t_infos *infos);
void			define_colors(char *s, t_infos *infos);
/*		is_infos.c		*/
int				is_flag(char c);
int				is_conv(char c);
int				is_modif(char c);
/*		convert.c		*/
int				convert_int(va_list arg, t_infos *infos);
int				convert_string(va_list arg, t_infos *infos);
int				convert_pointer(va_list arg, t_infos *infos);
int				convert_unsigned(va_list arg, t_infos *infos);
int				convert_char(va_list arg, t_infos *infos);
/*		convert2.c		*/
int				convert_wchar(va_list arg, t_infos *infos);
int				convert_wchar_string(va_list arg, t_infos *infos);
int				convert_long_int(va_list arg, t_infos *infos);
int				convert_octal(va_list arg, t_infos *infos);
int				convert_hexa(va_list arg, t_infos *infos);
/*		convert3.c		*/
int				convert_binary(va_list arg, t_infos *infos);
/*		base.c			*/
char			*base_binary(unsigned long int n);
int				base_decimal(char *bin);
char			*base_hexa(unsigned long long int n, int spec);
char			*base_octal(unsigned long long int n);
/*		add_width.c		*/
char			*add_width(char *s, int width, char *flag);
char			*add_width_0x(char *s, int width, char *flag);
void			add_width_prec_wchar(t_wc *wc, t_infos *infos);
void			add_width_minus_on(t_wc *wc, t_infos *infos, wchar_t *ws);
void			add_width_minus_off(t_wc *wc, t_infos *infos, wchar_t *ws);
/*		add_prec.c		*/
char			*add_prec(char *s, int prec);
char			*add_prec_string(char *s, int prec);
char			*add_prec_addr(char *s, int prec);
char			*add_prec_hexa(char *s, int prec);
void			add_prec_wchar(t_wc *wc, t_infos *infos, wchar_t *ws);
/*		add_flag.c		*/
char			*add_sharp_octal(char *s);
char			*add_sharp_hexa(char *s, int spec);
char			*add_plus(char *s);
char			*add_space(char *s);
char			*add_flag_integer(char *flag, char *s);
/*		add_flag2.c		*/
char			*add_flag_minus(char *s, int width);
char			*add_flag_zero(char *s, int width);
void			add_colors(int code_color);
/*		wchar.c			*/
int				print_wchar(int value);
int				mask_unicode(char *bin, int lenmask);
int				split_binary(char *bin, int lenmask);
int				display_wchar(char **tab, int nb);
/*		utils.c			*/
int				hexa_value(int n);
int				hexa_value_maj(int n);
char			*add_0x_addr(char *s);
int				next_percent(char *s, int c);
int				define_len_string(char *s, int c, t_infos *infos);
/*		utils2.c		*/
char			*define_modif_int(t_infos *infos, long long int integer);
int				define_prec_wchar(int prec);
void			init_var(t_wc *wc);
char			*add_octal_conv(t_infos *infos, char *ret, unsigned long int o);
char			*add_hexa_conv(t_infos *infos, char *ret, unsigned long int x);
/*		utils3.c		*/
char			*choose_hexa_conv(t_infos *infos,
				char *ret, unsigned long int x);
void			add_infos_no_conv(t_infos *infos,
				t_chkstr *chk, char *s, int c);
char			*choose_unicode_mask(int lenmask, char **tab, char *bin);

#endif
