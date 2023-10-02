/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:38:34 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 13:03:18 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string weaponType);
		void setType(std::string newType);
		const std::string& getType(void); 		
};

#endif