# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lajudy <lajudy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 17:15:03 by lajudy            #+#    #+#              #
#    Updated: 2023/04/19 09:21:15 by pnegre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	error_handling.c ft_atoi.c libft.c\
		stack_actions.c stack_actions2.c stack_sort.c\
		stack_sort_utils.c\
		stack_utils.c stack_utils2.c\
		transfer_to_a.c transfer_to_a2.c\
		ft_split.c main.c

BSRCS = ft_split.c libft.c stack_utils.c\
		stack_utils2.c ft_atoi.c error_handling.c\
		stack_actions.c stack_actions2.c\
		checker.c checker_utils.c libft_checker.c\
		stack_actions3.c

HDRS =	push_swap.h

OBJS = 	$(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = 	push_swap
BNAME = checker

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

$(MOBJS):$(HDRS) Makefile
$(OBJS):$(HDRS) Makefile
$(BOBJS):$(HDRS) Makefile

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}

re: fclean all

leaks:
	leaks --atExit -- ./$(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BSRCS}
	norminette -R CheckDefine ${HDRS}

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
