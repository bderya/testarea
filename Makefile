NAME			= push_swap

CC				= gcc
CFLAG			= -Wall -Wextra -Werror
RM				= rm -rf

SRC				= main.c algoritma.c checker.c parsing.c ./utils/utils.c ./utils/utils2.c ./utils/utils3.c ./move/reverse_rotate.c ./move/rotate.c ./move/swap.c ./move/push.c
OBJS			= ${SRC:.c=.o}


all: 		${NAME}

${NAME}:	$(OBJS)

			@$(CC) $(CFLAG) $(INC) $(SRC) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(OBJS)


re:			fclean all

.PHONY:		all clean fclean re

