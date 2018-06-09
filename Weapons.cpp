/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapons.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:26:03 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 18:24:44 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapons.hpp"

#include "Enemy.hpp"

Weapons::Weapons(WINDOW * win, int x, int y, char c) : Entity(win, x, y, c){
}

Weapons::~Weapons(void) {
}

Weapons::Weapons(Weapons const & src) : Entity(src){
}

Weapons & Weapons::operator=(Weapons const & src){
    xLoc = src.getX();
    yLoc = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    return *this;
}

void    Weapons::moveForward(int xIncr) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(xIncr, 0);
    if (getX() < 1) {
        xLoc = -1;
        xLoc = getX();
    }
}
