/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnequipedAmateria.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:11:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 12:14:13 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnequipedAmateria.hpp"

UnequipedAmateria::UnequipedAmateria() {
	this->trash = NULL;
	std::cout << "trash default constructor called" << std::endl;
}

UnequipedAmateria::UnequipedAmateria(const UnequipedAmateria &copy) {
	*this = copy;
	std::cout << "trash copy constructor called" << std::endl;
}

UnequipedAmateria::~UnequipedAmateria() {
	std::cout << "trash  destructor called" << std::endl;
	this->emptyTrash();
}

UnequipedAmateria &UnequipedAmateria::operator=(const UnequipedAmateria &copy) {
	if (this != &copy) {
		this->emptyTrash();
		list* tmp = copy.trash;
		while(tmp) {
			this->moveToTrash(tmp->m->clone());
			tmp = tmp->next;
		}
	}
	return *this;
}

void UnequipedAmateria::moveToTrash(AMateria *m) {
	if (!m)
		return;
	list *newnode = new list;
	newnode->m = m;
	newnode->next = NULL;
	if (!this->trash) {
		this->trash = newnode;
		return;
	}
	else {	
		list *tmp = this->trash;
		while (tmp) {
			if (!tmp->next) {
				tmp->next = newnode;
				break;
			}
			tmp = tmp->next;
		}
	}
}

void UnequipedAmateria::emptyTrash(void) {
	list *tmp;

	tmp = this->trash;
	while(tmp) {
		delete this->trash->m;
		tmp = tmp->next;
		delete this->trash;
		this->trash = tmp;
	}
}