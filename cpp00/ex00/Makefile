# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 18:29:15 by vtrofyme          #+#    #+#              #
#    Updated: 2025/10/05 16:34:18 by vtrofyme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= megaphone

MAIN		= megaphone.cpp

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
	@$(CC) $(OBJS) -o $(NAME)

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

