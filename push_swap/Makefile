NAME			=	push_swap
BONNAME			=	checker
HEAD			=	includes/push_swap.h
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
SRCS			=	srcs/main.c srcs/ft_nb_args.c srcs/do_op_a_vers_b.c srcs/do_op_b_vers_a.c srcs/operations_ab.c \
					srcs/push_swap.c srcs/check_errors.c srcs/indexation.c srcs/simple_swap.c srcs/del_lists.c srcs/operations.c
BONSRCS			=	bonus/main_bonus.c bonus/read_instructions.c srcs/ft_nb_args.c srcs/operations_ab.c \
					bonus/print_stack.c bonus/check_errors_bonus.c srcs/indexation.c srcs/del_lists.c srcs/operations.c
LIB_SRCS 		=	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c libft/ft_calloc.c libft/ft_bzero.c 
LIB_SRCS_BON	=	libft/get_next_line.c libft/get_next_line_utils.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_strncmp.c \
					libft/ft_printf.c libft/ft_check_var.c libft/ft_itoa.c libft/ft_printhex.c libft/ft_printnbr.c \
					libft/ft_printptr.c libft/ft_printstr.c libft/ft_printunbr.c libft/ft_itoa_pf.c libft/ft_printchar.c
LIB_OBJS		=	${LIB_SRCS:.c=.o}
LIB_OBJS_BON	=	${LIB_SRCS_BON:.c=.o}
OBJS			=	${SRCS:.c=.o}
BONOBJS			=	$(BONSRCS:.c=.o)
RM				=	rm -f

.c.o		:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)		:	${OBJS} ${HEAD}
				make -s -C libft
				$(CC) $(CFLAGS) -o ${NAME} ${OBJS} ${LIB_OBJS}
				echo Pret!

$(BONNAME)	:	$(BONOBJS)
				make -s -C libft
				$(CC) $(CFLAGS) -o ${BONNAME} ${BONOBJS} $(LIB_OBJS) ${LIB_OBJS_BON}
				echo Bonus pret!

all			:	$(NAME)

bonus		:	$(BONNAME)

clean		:	
				${RM} ${OBJS} $(BONOBJS) ${LIB_OBJS}
				make clean -s -C libft

fclean		:	clean
				$(RM) $(NAME) $(BONNAME) ${LIB_OBJS}
				make fclean -s -C libft
				echo Tout propre

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .c.o $(NAME) $(OBJS) $(CC) $(FLAGS) $(BONNAME) $(BONOBJS)
