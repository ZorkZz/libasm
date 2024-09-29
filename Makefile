NAME = libasm.a

SRCS = asm/ft_strlen.s asm/ft_strcpy.s asm/ft_strcmp.s asm/ft_write.s

SRCS_TEST = main.c

CFLAGS = -Wall -Wextra -Werror 

CC = cc

OBJS = $(SRCS:.s=.zizi)

OBJS_TEST = $(SRCS_TEST:.c=.zozo)

NA = nasm
NA_FLAGS = -f elf64
TEST_FLAGS = -lasm -L .

RM = rm -f

DELETE_LINE	= \r\033[2K
YELLOW		= \033[1;33m
GREEN		= \033[1;32m
RED			= \033[1;31m
ENDL		= \033[0m

all: $(NAME) test

%.zizi: %.s Makefile
	@$(NA) $(NA_FLAGS) -o $@ $<
	@printf	"$(YELLOW) $(DELETE_LINE)Creating -c $< -o $\n $(ENDL)"

%.zozo: %.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf	"$(YELLOW) $(DELETE_LINE)Creating -c $< -o $\n $(ENDL)"

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf	"$(GREEN) $(DELETE_LINE)Compiling $(NAME) : DONE $(ENDL)\n"

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)
	@printf	"$(RED)Deleting objects : DONE $(RED)\n"

fclean: clean
	$(RM) $(NAME)
	$(RM) test.run
	@printf "$(RED)Deleting executable : DONE $(RED)\n\n"

test: $(OBJS_TEST)
	@$(CC) $(CFLAGS) $(OBJS_TEST) $(NAME) $(TEST_FLAGS) -o test.run
	@printf	"$(GREEN) $(DELETE_LINE)Compiling test.run : DONE $(ENDL)\n"

re: fclean all