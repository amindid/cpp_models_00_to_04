/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:57:00 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 11:06:57 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap
	: public ScavTrap, public FragTrap {
		private:
			std::string name;
		public:
			DiamondTrap();
			DiamondTrap(const DiamondTrap &copy);
			DiamondTrap(std::string name);
			~DiamondTrap();
			DiamondTrap &operator=(const DiamondTrap &copy);

			void attack(const std::string& target);
			void whoAmI(void);
			std::string getDiamondName(void);
}; 

#endif