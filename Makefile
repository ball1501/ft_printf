NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -Ilibft

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = ft_printf.c \
              ft_printf_char.c \
              ft_printf_hex.c \
              ft_printf_nbr.c

OBJS        = $(SRCS:.c=.o)

# Rules หลัก
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

# Rule สำหรับ Bonus (เตรียมไว้ใช้สำหรับส่วนถัดไป)
bonus: all

.PHONY: all clean fclean re bonus
