NAME	= push_swap

# directories
SRCDIR	= ./srcs
INCDIR	= ./includes
OBJDIR	= ./obj

# src / obj files
SRC		= main.c error_utils.c list_cmd.c push.c \
		stack_a_init.c print.c swap.c rotate.c rev_rotate.c \
		small_sorts.c target.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= cc
CFLAGS	= -Wall -Wextra -Werror


# ft library
FT		= ./libs
FT_LIB	= $(addprefix $(FT)/,libftprintf.a)
FT_INC	= -I ./libs/includes
FT_LNK	= -L ./libs/includes

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	#$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(FT_LIB) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
