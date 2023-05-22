# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 11:57:26 by vcodrean          #+#    #+#              #
#    Updated: 2023/05/22 14:53:26 by vcodrean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME = philo

CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address  
RM = rm -f

SRCS = src/philo.c src/utils.c src/time_utils.c
INCS = inc/
 
OBJS = $(SRCS:.c=.o)

%.o:%.c
		@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
		@$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME) 

$(NAME): $(OBJS)
		@echo "\n$(GREEN) Created $(EXEC) ✓ $(DEF_COLOR)\n"
		@$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) -I$(INCS) -lpthread

clean:
		@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"
		@$(RM) $(OBJS)

fclean: clean 
		@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"
		@$(RM) $(NAME) 
		@$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
