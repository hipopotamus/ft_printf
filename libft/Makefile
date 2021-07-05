SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isinset.c ft_uitoa.c ft_uitoa_base.c ft_ultoa_base.c ft_sizet_max.c ft_sizet_min.c ft_tenary.c
SRCS_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
INCS = .

TARGET = libft.a

CC = gcc
CFLAGES = -Wall -Wextra -Werror
LIBC = ar -rcs
RM = rm -f

all : $(TARGET)

.c.o:
	$(CC) $(CFLAGES) -o $@ -c $< -I$(INCS)

$(TARGET) : $(OBJS)
	$(LIBC) $(TARGET) $(OBJS)

bonus : $(TARGET) $(OBJS_B)
	$(LIBC) $(TARGET) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(TARGET)

re: fclean alli

.PHONY : all clean fclean re .c.o
