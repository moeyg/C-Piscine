CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
TARGET = do-op
SRCS = $(SRCDIR)/main.c $(SRCDIR)/ft_operator.c $(SRCDIR)/ft_validate.c $(SRCDIR)/ft_atoi.c
OBJECTS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
