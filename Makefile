# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 15:58:12 by mwingrov          #+#    #+#              #
#    Updated: 2018/06/10 16:01:15 by mwingrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang++

FLAGS= -c -Wall -Wextra -Werror

all: prog

prog: main.o ft_.o
	$(CC) main.o Pony.o -o ft_retro

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Contact.o: Pony.cpp Pony.hpp
	$(CC) $(FLAGS) Pony.cpp Pony.hpp

Contact.o: Pony.cpp Pony.hpp
	$(CC) $(FLAGS) Pony.cpp Pony.hpp

Contact.o: Pony.cpp Pony.hpp
	$(CC) $(FLAGS) Pony.cpp Pony.hpp

Contact.o: Pony.cpp Pony.hpp
	$(CC) $(FLAGS) Pony.cpp Pony.hpp
	
clean:
	rm -rf *.o ft_retro

re: clean all