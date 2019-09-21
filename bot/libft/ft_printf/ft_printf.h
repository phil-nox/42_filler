/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define LEN_STR_FRC 16500
# define LEN_STR_ENT 5000
# define STOP_SHORT 30000
# define FRAC_FLOAT 63 + 1
# define DEBUG_POWER 0
# define DEBUG_FLOAT_CREATION 0
# define DEBUG_EXP_TAB 0
# define DEBUG_ROUNDING 0
# define SHOW_LAST_TASK 0
# define UTF8COUNT 0
# define BUFF 1024
# define BOOST_ON 1

# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

typedef	union			u_longd
{
	long double			ld;
	struct				s_parts_ld
	{
		unsigned long	frac : 63;
		unsigned long	exp : 15;
		unsigned long	sign : 1;
	}					t_parts_ld;
}						t_longd;

typedef	union			u_d
{
	double				d;
	struct				s_parts_d
	{
		unsigned long	frac : 52;
		unsigned long	exp : 11;
		unsigned long	sign : 1;
	}					t_parts_d;
}						t_d;

typedef	union			u_f
{
	float				f;
	struct				s_parts_f
	{
		unsigned int	frac : 23;
		unsigned int	exp : 8;
		unsigned int	sign : 1;
	}					t_parts_f;
}						t_f;

typedef	struct			s_str_f
{
	char				ent[LEN_STR_ENT];
	char				frc[LEN_STR_FRC];
	int					idx_ent;
	int					idf;
	int					exp_ent;
	int					exp_frc;
	char				sign;
}						t_str_f;

typedef	struct			s_task
{
	char				minus;
	char				plus;
	char				space;
	char				hash;
	char				zero;
	int					width;
	int					precision;
	char				length;
	char				type;
	char				*tmp;
}						t_task;

int						ft_printf(const char *format, ...);

void					init_task(t_task *input);
void					print_task(t_task *input);
int						set_task(t_task *input, char *start, va_list *ap);
int						make_task(t_task *input, va_list *ap);

int						make_c(t_task *input, va_list *ap);
int						make_bc(t_task *input, va_list *ap);
int						make_s(t_task *input, va_list *ap);
int						make_bs(t_task *input, va_list *ap);
int						make_p(t_task *input, va_list *ap);
void					make_d_job(t_task *input, int len, int len_num,
						long long target);
int						make_d(t_task *input, va_list *ap);
int						make_o(t_task *input, va_list *ap);
int						make_u(t_task *input, va_list *ap);
int						make_x(t_task *input, va_list *ap);
int						make_f(t_task *input, va_list *ap);
int						make__(t_task *input);

int						ft_atoi_printf(const char *str, int *add_total);
void					fill(char fill, int len);
int						is_one_of(char target, char *str);
int						length_utf8(char *str);
int						length_unicode(wchar_t *str);
int						len_unicode_by_symbole(wchar_t *str, int top);

int						unicodestep(wchar_t tmp);
int						ft_utf8step(char const *s);
int						ft_pututf8(char const *s);
int						ft_putchar_p(int c);
int						ft_putchar_simple(char c);
void					ft_putnbr(int n);
int						ft_putstr_p(char const *s);
int						ft_putstrn(char const *s, int len);
void					print_arr(short *list, int size);
void					ft_putunbr(unsigned long n);
void					ft_baseitoa(char *out, unsigned long long target,
						unsigned char base, char big);
void					ft_baseitoasign(char *out, long long target,
						unsigned char base);
int						unicode2utf8(wchar_t tmp);
int						ft_putunicode(wchar_t *s, int len);

int						write_boost(char const *s, int end);
void					boost_pos(t_str_f *input, int pwr, int *curr);
void					boost_neg(t_str_f *input, int pwr, int *curr);
void					boost15360(t_str_f *input);
void					boost14336(t_str_f *input);
void					boost12288(t_str_f *input);
void					boost8192(t_str_f *input);
void					boost4096(t_str_f *input);
void					boost_neg_15360(t_str_f *input);
void					boost_neg_14336(t_str_f *input);
void					boost_neg_12288(t_str_f *input);
void					boost_neg_8192(t_str_f *input);
void					boost_neg_4096(t_str_f *input);
void					boost_neg_do(t_str_f *input,
						char *(*boost_fun[7])(void));
void					boost_pos_do(t_str_f *input,
						char *(*boost_fun[7])(void));
char					*boost_neg_12288_part1(void);
char					*boost_neg_12288_part2(void);
char					*boost_neg_12288_part3(void);
char					*boost_neg_12288_part4(void);
char					*boost_neg_12288_part5(void);
char					*boost_neg_14336_part1(void);
char					*boost_neg_14336_part2(void);
char					*boost_neg_14336_part3(void);
char					*boost_neg_14336_part4(void);
char					*boost_neg_14336_part5(void);
char					*boost_neg_15360_part1(void);
char					*boost_neg_15360_part2(void);
char					*boost_neg_15360_part3(void);
char					*boost_neg_15360_part4(void);
char					*boost_neg_15360_part5(void);

void					init_t_str_f(t_str_f *input);
void					init_t_str_f_sign(t_str_f *input, unsigned int sign);
void					init_t_str_f_ent(t_str_f *input);
void					init_t_str_f_frc(t_str_f *input);
void					print_t_str_f(t_str_f *input);
void					print_t_str_f_human(t_str_f *input);
void					print_t_str_f_full(t_str_f *input);
void					power2(t_str_f *input, int pwr);
void					power2form(t_str_f *input, int pwr, int curr);
void					sum_t_str_f_frc(t_str_f *result, t_str_f *a,
						t_str_f *b);
void					sum_t_str_f_ent(t_str_f *result, t_str_f *a,
						t_str_f *b);
void					set_sign(t_str_f *result, unsigned int sign);

void					show_float(t_longd input);
void					int_power_tab(short	power_tab[FRAC_FLOAT]);
void					set_power_tab(short	power_tab[FRAC_FLOAT],
						unsigned long vals, short exp, unsigned long mask);
void					debug_print(t_str_f	*add, int power, int curr);
void					debug_print_final(t_str_f	*final);
void					get_fractionnaire(t_str_f *frc,
						short power_tab[FRAC_FLOAT]);
void					get_entiere(t_str_f *ent, short power_tab[FRAC_FLOAT]);
void					get_precision_longd(t_str_f *output, long double input);
void					get_precision_d(t_str_f *output, double input);
void					get_precision_f(t_str_f *output, float input);

void					t_str_f_print_ent(t_str_f *input);
void					t_str_f_print_frc(t_str_f *input, int pos);
void					t_str_f_print_full_simple(t_str_f *input, int pos);
void					t_str_f_round(t_str_f *input, unsigned int pos);

#endif
