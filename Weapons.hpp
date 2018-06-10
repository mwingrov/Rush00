/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapons.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:26:06 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/10 16:36:15 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_HPP
#define WEAPONS_HPP
#include "Entity.hpp"

class Weapons : public Entity
{
    public:
        Weapons(WINDOW * win, int x, int y, const char * c);
        Weapons();
        ~Weapons();
        Weapons(Weapons const & src);
        Weapons & operator = (Weapons const & src);
        void    moveForward(int xIncr);
        void    shoot(void);
};

#endif
