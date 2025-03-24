/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cabeceralib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:42:35 by inbauman          #+#    #+#             */
/*   Updated: 2024/11/18 12:44:50 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_FD
#  define MAX_FD 1
# endif
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h> 
# include <stdarg.h>
#include <limits.h>
typedef struct s_conteo
{
    int size_a;
    int size_b;
    int rra_min;
    int rra_max;
    int rrb_min;
    int rrb_max;
    int num_min;
    int num_max;
} t_conteo;
 
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line2(char **linea, int bytes_leidos);
char	*get_next_line(int fd);
int	ft_printf_control(char copia, va_list args);
int	ft_printf(char const *linea, ...);
int	ft_printf_puthex(unsigned long long p);
int	ft_printf_putstr(char *s);
int	ft_printf_numero_hex(unsigned int num, char c);
int	ft_printf_putnbr(long long num);
int	ft_printf_numeros_dos_cifras(long long num);
int	ft_putchar(char c);
int control_duplicados(int *stack1, int argc);
int *alocacion_memoria(int argc, char *argv[]);
int *alocacion_memoria2(int argc);
int	ft_numero_minimo(int *stack_a, int argc);
int control_numeros(int argc, char *argv[]);
int	ft_atoi2(const char *nptr);
int	ft_atoi3(const char *nptr);
int	dimensiones_int(int argc, char *argv[]);
void    base_push_swap(int *stack_a, int *stack_b, int argc, t_conteo *conteo);
void    sa(int *stack_a, int *size_a);
void    sb(int *stack_b, int size_b);
void    ss(int *stack_a, int *stack_b, int size_a, int size_b);
void	pb(int *stack_a, int *stack_b, t_conteo *conteo);
void	pa(int *stack_a, int *stack_b, t_conteo *conteo);
void    ra(int *stack_a, int size_a);
void    rb(int *stack_b, int size_b);
void    rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	rrr(int *stack_a, int *stack_b, t_conteo *conteo);
void	rrb(int *stack_b, int size_b);
void    rra(int *stack_a, int size_a);
void	recolocacion_a_stack_a(int *stack_a, int *stack_b, int size_b);
void    control_minimo(int *stack_a, int *stack_b, int *numero_minimo, int *size_a, int *size_b);
void    control_0_1(int *stack_a, int *stack_b, int *numero_minimo, int *size_a, int* size_b);
void    guardar_stack_en_archivo(int *stack_a, int size_a);
void    control_posicion_minimo(int *stack_a, int *size_a, int numero_minimo);
void    rra(int *stack_a, int size_a);
void	posicionar_minimo(int *stack_a, int *size_a, int posicion_minimo, int n);
int	ft_numero_maximo(int *stack_a, int argc);
void	posicionamiento(int *stack_a, int *stack_b, t_conteo *conteo);
int    numero_movimientos_min(int *stack_a, int *stack_b, t_conteo *conteo);
int    numero_movimientos_max(int *stack_a, int *stack_b, t_conteo *conteo);
void posicionamiento_min(int *stack_a, int *stack_b, t_conteo *conteo);
void posicionamiento_max(int *stack_a, int *stack_b, t_conteo *conteo);
int	movimientos_a_realizar_stack_a_min(int *stack, t_conteo *conteo);
int movimientos_a_realizar_stack_b_min(int *stack_b, t_conteo *conteo);
int	movimientos_a_realizar_stack_a_max(int *stack_a, t_conteo *conteo);
int movimientos_a_realizar_stack_b_max(int *stack_b, t_conteo *conteo);

#endif
