/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:01:22 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 13:25:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* humanBweapon;
	public:
		HumanB(std::string newName);
		~HumanB();
		void setWeapon(Weapon& weapon);
		void attack(void);
};

#endif