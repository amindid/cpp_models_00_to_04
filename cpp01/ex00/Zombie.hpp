/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:52:06 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/01 15:16:54 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string name;
	
	public:
		void setName(std::string zombieName);
		std::string getName(void);
		void announce(void);
		~Zombie();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
