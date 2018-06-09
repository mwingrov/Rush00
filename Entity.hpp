/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngwato <kngwato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:27:50 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 14:11:52 by kngwato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <ncurses.h>
#include <iostream>
#include <string>

class Entity
{
    public:
        Entity(WINDOW * win, int x, int y, char c);
        ~Entity();
        Entity(Entity const & src);
        Entity & operator = (Entity const & src);
        bool    comparePos(Entity const & src) const;
        void    display(void) const;
        int     getX(void) const;
        int     getY(void) const;
        void    move(int xIncr, int yIncr);
        void    moveForward(int xIncr);
        int     getXMax(void) const;
        int     getYMax(void) const;
        char    getCharater(void) const;
        WINDOW *    getCurrentWindow(void) const;
    protected:
        int xLoc;
        int yLoc;
        int xMax;
        int yMax;
        char character;
        WINDOW * currentWindow;
        static const int SPEED = 1;
};

#endif