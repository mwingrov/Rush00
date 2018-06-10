# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 15:58:12 by mwingrov          #+#    #+#              #
#    Updated: 2018/06/10 16:07:49 by mwingrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang++

FLAGS= -c -Wall -Wextra -Werror

all: prog

prog: main.o Enemy.o Weapons.o Player.o Entity.o 
	$(CC) main.o Enemy.o Weapons.o Player.o Entity.o -lncurses -o ft_retro

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Entity.o: Entity.cpp Entity.hpp
	$(CC) $(FLAGS) Entity.cpp Entity.hpp

Enemy.o: Enemy.cpp Enemy.hpp
	$(CC) $(FLAGS) Enemy.cpp Enemy.hpp

Player.o: Player.cpp Player.hpp
	$(CC) $(FLAGS) Player.cpp Player.hpp

Weapons.o: Weapons.cpp Weapons.hpp
	$(CC) $(FLAGS) Weapons.cpp Weapons.hpp
	
clean:
	rm -rf *.o ft_retro

re: clean all