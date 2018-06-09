/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:46:12 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 18:25:35 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Enemy.hpp"
#include <thread>


WINDOW * space;

void    EnemyShip(void) {
    int i = 0;
    Enemy * e = new Enemy(space, 48, 1, '<');
    Enemy * e1 = new Enemy(space, 48, 2, '{');
    Enemy * e2 = new Enemy(space, 48, 4, '[');
    Enemy * e3 = new Enemy(space, 48, 10, '=');
    Enemy * e4 = new Enemy(space, 48, 11, '+');
    Enemy * e5 = new Enemy(space, 48, 12, '=');
    Enemy * e6 = new Enemy(space, 48, 13, '<');
    Enemy * e7 = new Enemy(space, 48, 14, '*');
    Enemy * e8 = new Enemy(space, 48, 15, '{');
    Enemy * e9 = new Enemy(space, 48, 16, '<');
    Enemy * e10 = new Enemy(space, 48, 17, '~');
    e->display();
    e1->display();
    e2->display();
    e3->display();
    e4->display();
    e5->display();
    e6->display();
    e7->display();
    e8->display();
    e9->display();
    e10->display();
    wrefresh(space);
    while(true) {
        if (i%100000000 == 0)
        {
            e->moveForward(2);
            e1->moveForward(5);
            e2->moveForward(4);
            e3->moveForward(3);
            e4->moveForward(1);
            e5->moveForward(5);
            e6->moveForward(2);
            e7->moveForward(6);
            e8->moveForward(4);
            e9->moveForward(5);
            e10->moveForward(6);
            e->display();
            e1->display();
            e2->display();
            e3->display();
            e4->display();
            e4->display();
            e5->display();
            e6->display();
            e7->display();
            e8->display();
            e9->display();
            e10->display();
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
        wrefresh(space);
    }
    runner.join();
    getch();
    endwin();
    
    return 0;
}