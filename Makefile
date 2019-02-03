# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 17:55:11 by ebatchas          #+#    #+#              #
#    Updated: 2019/02/03 18:02:10 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes
CFLAGS=-Wall -Wextra -I$(HEADDIR)
LDFLAGS= $(CFLAGS) -I$(HEADDIR) -L$(LIBDIR)/ -lft 

SRC1=$(SRCDIR)/client.c
SRC2=$(SRCDIR)/server.c

OBJ1=$(LIBDIR)/client.o
OBJ2=$(LIBDIR)/server.o

NAME2=server
NAME1=client

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	make -C $(LIBDIR)/libft/ fclean && make -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)/
	$(CC) $(LDFLAGS) -o $@ $^

$(NAME2): $(OBJ2)
	$(CC) $(LDFLAGS) -o $@ $^


$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean fclean

clean:
	rm -rf $(LIBDIR)/*.o
	make -C $(LIBDIR)/libft clean

fclean:clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C $(LIBDIR)/libft fclean

re : fclean all
