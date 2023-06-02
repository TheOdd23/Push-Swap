NAME	=	libft.a
HEAD	=	libft.h
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
SRCS	=	ft_atoi.c ft_bzero.c  ft_calloc.c ft_isalnum.c ft_isalpha.c \
                    ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
                    ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
                    ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
                    ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
                    ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
                    ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
                    ft_toupper.c ft_check_var.c ft_itoa_pf.c ft_printchar.c \
					ft_printhex.c ft_printnbr.c ft_printstr.c ft_printunbr.c ft_printf.c \
					ft_printptr.c get_next_line_utils.c get_next_line.c
BONSRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c
OBJS	=	${SRCS:.c=.o}
BONOBJS	=	${BONSRCS:.c=.o}
RM		=	rm -f

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	 ${OBJS} ${HEAD}
	ar rcs ${NAME} ${OBJS}

bonus	:	${OBJS} ${BONOBJS} ${HEAD}
	ar rcs ${NAME} ${OBJS} ${BONOBJS}	

all		:	$(NAME)

clean	:	
	${RM} ${OBJS} ${BONOBJS}

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean ${OBJS}
	ar rcs ${NAME} ${OBJS}

.PHONY	:	all bonus clean cleanbonus fclean re
