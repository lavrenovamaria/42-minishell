NAME = 				minishell

DIR_LIBFT =			libft/libft/
LIBFT = 			libft/libft/libft.a

CC = 				gcc

CFLAGS = 			-Wall -Wextra -Werror -lreadline

# INC_PATH = 			inc
# INC = 				-I${INC_PATH} -I${LIBFT_PATH}

HEA_NAME =			minishell.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

SRC_PATH =			service
SRC_NAME_MAIN =		tree.c

OBJ_PATH = 			obj
OBJ_MAIN = 			${addprefix ${OBJ_PATH}/,${SRC_NAME_MAIN:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h ${LIBFT_PATH}/Makefile ${RL_PATH}/*.c ${RL_PATH}/*.h ${RL_PATH}/Makefile Makefile
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:			${OBJ_MAIN}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					${CC} ${CFLAGS} -o ${NAME} ${OBJ_MAIN} -L${LIBFT_PATH} -l${LIBFT}

all: 				${NAME}

clean:
					rm -rf ${OBJ_PATH}
					@make clean -C ${LIBFT_PATH}

fclean: 			clean
					rm -rf ${NAME}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

.PHONY: 			all clean fclean re bonus
