/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapons.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:26:06 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 18:24:53 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_HPP
#define WEAPONS_HPP
#include "Entity.hpp"

class Weapons : public Entity
{
    public:
        Weapons(WINDOW * win, int x, int y, char c);
        ~Weapons();
        Weapons(Weapons const & src);
        Weapons & operator = (Weapons const & src);
        void    moveForward(int xIncr);
};

#endif
