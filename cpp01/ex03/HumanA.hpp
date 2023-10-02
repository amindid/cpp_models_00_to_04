/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:51:39 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 13:25:54 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon& humanAweapon;
	public:
		HumanA(std::string newName, Weapon& newWeapon);
		~HumanA();
		void attack(void);
};

#endif