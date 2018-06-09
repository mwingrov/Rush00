/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngwato <kngwato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:46:12 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 16:34:46 by kngwato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Enemy.hpp"
#include <thread>


WINDOW * space;

void    EnemyShip(void) {
    int i = 0;
    Enemy * e = new Enemy(space, 20, 10, 'e');
             e->display();
            wrefresh(space);
    while(true) {
        if (i%100000000 == 0)
        {
            e->moveForward(1);
            e->display();
            wrefresh(space);
        }
        i++;
    }
}

int main() {
    
    
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
space = newwin(20, 50, (yMax/2 - 10), 10);
    box(space,0,0);
    refresh();
    wrefresh(space);

    
    Player * p = new Player(space, 1, 10, 'P');
    std::thread runner (EnemyShip);
    
    while(p->getPlayerInput() != 'x')
    {
        p->display();
        // std::cout << p->getX() << std::endl;
        // std::cout << p->getY() << std::endl;
        wrefresh(space);
    }
    runner.join();
    getch();
    endwin();
    
    return 0;
}