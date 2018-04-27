/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:40:27 by bandre            #+#    #+#             */
/*   Updated: 2017/03/21 00:18:25 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_mem_stock
{
	void			**list_ptr;
	struct			s_mem_stock *next;
}					t_mem_stock;

void				*mem_stock(int i);
t_mem_stock			**mem_ptr(void);
void				mem_stock_free(void);
void				mem_free_ptr(void *ptr);

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *substring);
char				*ft_itoa(int n);
char				*ft_itoa_base_signed(ssize_t value, int base, int m);
char				*ft_itoa_base(size_t value, int base, int m);
char				*ft_strnstr(const char *str, const char *subs, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
ssize_t				ft_atoi(char *str);
size_t				ft_strlcat(char *dst, const char*src, size_t size);

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *c);
void				ft_putendl(char const *c);

void				ft_putstr_fd(char const *c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *c, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchartab(char **tab);

char				*ft_itoa(int n);
char				**ft_strsplit(char const *str, char c);
char				*ft_strsub(char const*str, unsigned int start, size_t len);
char				*ft_strtrim(char const *str);
char				*ft_strjoin(char const *str1, char const *str2);

int					ft_strequ(char const *str1, char const *str2);
int					ft_strnequ(char const *str1, char const *str2, size_t n);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_strclr(char *str);

void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char(*f)(unsigned int, char));

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_is_number(char *str);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newt);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putlst(t_list *lst);
int					get_next_line(const int fd, char **line);

void				**ft_ptradd(void **list, void *add);
void				**ft_ptradd_free(void **list, void *add);
void				ft_afficher_tab_c(char **tab);

#endif
