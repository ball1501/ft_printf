NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -Ilibft

# โฟลเดอร์ Libft
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ไฟล์ซอร์สโค้ดของ ft_printf
SRCS        = ft_printf.c \
              ft_print_char.c \
              ft_print_str.c \
              ft_print_nbr.c \
              ft_print_hex.c \
              ft_print_ptr.c

OBJS        = $(SRCS:.c=.o)

# Command ทั้งหมด
AR          = ar rcs
RM          = rm -f

all: $(NAME)

# 1. คอมไพล์ Libft ก่อน
$(LIBFT):
	@make -C $(LIBFT_DIR)

# 2. รวม Libft เข้ากับ Object files ของ ft_printf
$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
