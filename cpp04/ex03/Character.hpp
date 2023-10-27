/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:55:25 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/25 12:40:56 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "UnequipedAmateria.hpp"

class UnequipedAmateria;

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* inventory[4];
		UnequipedAmateria* trashHolder;
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &copy);

		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif