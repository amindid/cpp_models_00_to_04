/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:03:31 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 13:09:16 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap
	:public ClapTrap {
		public:
			FragTrap();
			FragTrap(FragTrap const &copy);
			FragTrap(std::string);
			FragTrap &operator=(const FragTrap &copy);
			~FragTrap();

			void attack(const std::string& target);
			void highFivesGuys(void);
			
};

#endif