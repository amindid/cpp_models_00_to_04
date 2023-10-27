/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:24:03 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/23 12:46:33 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();	
		Ice(const Ice &copy);	
		~Ice();
		Ice &operator=(const Ice &copy);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif