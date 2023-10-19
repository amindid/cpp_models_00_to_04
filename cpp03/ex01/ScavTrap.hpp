/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:10 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 12:44:27 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap 
	:public ClapTrap {
		public:
			ScavTrap();
			ScavTrap(ScavTrap const &copy);
			ScavTrap(std::string);
			ScavTrap &operator=(const ScavTrap &copy);
			~ScavTrap();

			void attack(const std::string& target);
			void guardGate(void);
};

#endif