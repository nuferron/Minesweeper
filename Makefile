RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

SRCS = 	main.c set_game.c print_game.c
SRCDIR = src/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
DEPS = $(addprefix $(OBJDIR),$(SRCS:.c=.d))
OBJDIR = obj/
NAME = minesweeper
CFLAGS = -Wall -Wextra -Werror -MMD #-fsanitize=address
LIB = inc/libft/libft.a
INC = inc/
COLUMNS = $(shell tput cols)

all: make_libs ${NAME}

make_libs:
	make -C inc/libft --no-print-directory

-include $(DEPS)
${NAME}: ${OBJS} ${LIB}
	cc ${CFLAGS} ${OBJS} -I inc inc/libft/libft.a -o ${NAME}
	echo "${WHITE}${NAME}: ${GREEN}Binary successfully created!${RESET}"

leaks: ${NAME}
	leaks -atExit -- ./${NAME}

run: ${NAME}
	./${NAME}

${OBJDIR}%.o: ${SRCDIR}%.c Makefile
	@printf "${WHITE}${NAME}: ${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -I ${INC} -c $< -o $@
	@printf "\r%-${COLUMNS}s\r"

clean:
	if [ -d ${OBJDIR} ] ; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS}; \
		printf "${WHITE}${NAME}: ${RED}Objects have been deleted${RESET}\n"; \
	fi
	make -C inc/libft clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] ; then \
		rm -f ${NAME} ${LIB} do_bonus ; \
		printf "${WHITE}${NAME}: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}${NAME}: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C inc/libft fclean --no-print-directory

re:	fclean all

.SILENT: clean fclean leaks make_libs ${NAME} run
.PHONY: all clean fclean re leaks run
