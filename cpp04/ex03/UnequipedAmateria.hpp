/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnequipedAmateria.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:58:49 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/25 08:19:49 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNEQUIPEDAMATERIA_HPP
#define UNEQUIPEDAMATERIA_HPP

#include "AMateria.hpp"

class AMateria;

typedef struct list
{
	AMateria* m;
	list* next;
} list;

class UnequipedAmateria {
	private:
		list* trash;
	public:
		UnequipedAmateria();
		UnequipedAmateria(const UnequipedAmateria &copy);
		~UnequipedAmateria();
		UnequipedAmateria &operator=(const UnequipedAmateria &copy);

		void moveToTrash(AMateria *m);
		void emptyTrash(void);
};

#endif