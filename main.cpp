/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngwato <kngwato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:46:12 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 14:34:33 by kngwato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

int main() {
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * space = newwin(20, 50, (yMax/2 - 10), 10);
    box(space,0,0);
    refresh();
    wrefresh(space);

    Player * p = new Player(space, 1, 10, 'V');
    while(p->getPlayerInput() != 'x')
    {
        p->display();
        // std::cout << p->getX() << std::endl;
        // std::cout << p->getY() << std::endl;
        wrefresh(space);
    }
    getch();
    endwin();
    
    return 0;
}