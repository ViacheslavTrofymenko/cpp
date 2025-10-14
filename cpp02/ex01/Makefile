# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 18:29:15 by vtrofyme          #+#    #+#              #
#    Updated: 2025/10/09 19:10:14 by vtrofyme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= fixedPoint

MAIN		= main.cpp Fixed.cpp

MAINDIR		= src
MAINSRC		= $(addprefix $(MAINDIR)/, $(MAIN))
SRCSDIR		= src
OBJDIR		= obj
INCLUDE		= include

SRCS		= $(MAINSRC)

OBJS		= $(SRCS:$(SRCSDIR)/%.cpp=$(OBJDIR)/%.o)

CFLAGS		= -Wall -Wextra -Werror -g3 -std=c++98
INCLUDES	= -I$(INCLUDE)
CC			= c++

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(CC) $(OBJS) $(INCLUDES) -o $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all


#phony
.PHONY: all clean fclean re

