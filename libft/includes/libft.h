/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:40:15 by conrodri          #+#    #+#             */
/*   Updated: 2020/03/04 18:41:29 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "../../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# define BLACK (t_rgb){0, 0, 0, 0}
# define WHITE (t_rgb){255, 255, 255, 0}
# define RED (t_rgb){255, 0, 0, 0}
# define GREEN (t_rgb){0, 255, 0, 0}
# define BLUE (t_rgb){0, 0, 255, 0}
# define PURPLE (t_rgb){90, 41, 98, 0}
# define S_GREY (t_rgb){50, 50, 50, 0}
# define L_GREY (t_rgb){150, 150, 150, 0}
# define ORANGE (t_rgb){255, 174, 66, 0}
# define YELLOW (t_rgb){239, 253, 95, 0}

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_real
{
	float				x;
	float				y;
}					t_real;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_rgb;

typedef struct		s_2d_line
{
	float	a;
	float	b;
	float	c;
}					t_2d_line;

typedef struct		s_cplx
{
	double			rl;
	double			im;
}					t_cplx;

typedef struct		s_mlx_img
{
	void			*ptr;
	char			*img;
	int				width;
	int				height;
	int				bpp;
	int				s_l;
	int				endian;
}					t_mlx_img;

void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_itoa(int n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_memdel(void **ap);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_countletters(char const *s, char c, int i);
int					ft_countword(char const *s, char c);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
void				ft_error(char *str);
char				*ft_strcapitalize(char *str);
void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
t_rgb				ft_get_pixel(t_mlx_img img, int x, int y);
void				ft_img_dark(t_mlx_img img);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
int					ft_sqrt(int nb);
t_real				op_real(t_real a, char op, t_real b);
float				real_norm(t_real p);
float				real_scale_product(t_real p1, t_real p2);
t_real				real_turn(t_real point, float degree);
float				ft_deg_to_rad(float nb);
t_2d_line			create_2d_line_points(t_real p1, t_real p2);

#endif
