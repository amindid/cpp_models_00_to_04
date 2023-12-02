/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:49:33 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/02 13:17:25 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &copy){
	(void)copy;
}
PmergeMe::~PmergeMe(){}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	(void)copy;
	return *this;
}

myPair PmergeMe::mergePairs(myPair pair1, myPair pair2) {
	myPair pair;
	vect_it it = pair1.first.begin();
	while (it != pair1.first.end()) {
		pair.first.push_back(*it);
		it++;
	}
	it = pair1.second.begin();
	while (it != pair1.second.end()) {
		pair.first.push_back(*it);
		it++;
	}
	it = pair2.first.begin();
	while (it != pair2.first.end()) {
		pair.second.push_back(*it);
		it++;
	}
	it = pair2.second.begin();
	while (it != pair2.second.end()) {
		pair.second.push_back(*it);
		it++;
	}
	return pair;
}

void PmergeMe::mergePairInVector(myPair pair, vector & vect) {
	vect_it it;
	it = pair.first.begin();
	while (it != pair.first.end()) {
		vect.push_back(*it);
		it++;
	}
	it = pair.second.begin();
	while (it != pair.second.end()) {
		vect.push_back(*it);
		it++;
	}
}

void PmergeMe::first_fill(void) {
	vect_it it = firstInput.begin();
	while (it != firstInput.end()) {
		vector tmp1;
		vector tmp2;
		tmp1.push_back(*it);
		it++;
		tmp2.push_back(*it);
		it++;
		if (*(tmp1.begin()) <= *(tmp2.begin()))
			mainVect.push_back(std::make_pair(tmp1, tmp2));
		else
			mainVect.push_back(std::make_pair(tmp2, tmp1));
	}
}

void PmergeMe::fill_sortedChain(void) {
	vectOfPrs_it it = mainVect.begin();
	while (it != mainVect.end()) {
		vector tmp1;
		vect_it vit = (*it).first.begin();
		while (vit != (*it).first.end()) {
			tmp1.push_back(*vit);
			vit++;
		}
		sortedChain.push_back(tmp1);
		vit = (*it).second.begin();
		tmp1.clear();
		while (vit != (*it).second.end()) {
			tmp1.push_back(*vit);
			vit++;
		}
		sortedChain.push_back(tmp1);
		it++;
	}
}

void PmergeMe::insurtPaindInmainChain(vectorOfVectors &mainChain, vectorOfVectors paind) {
	vofvs_it paind_it = paind.begin();
	while (paind_it != paind.end()) {
		vofvs_it insurtionPos = std::lower_bound(mainChain.begin(), mainChain.end(), *paind_it);
		paind_it++;
	}
}

void PmergeMe::Psort() {
	vector rest;
	if (mainVect.size() == 0) {
		if (firstInput.size() % 2 != 0) {
			rest.push_back(firstInput.back());
			firstInput.pop_back();
		}
		first_fill();
	}
	vectOfPrs_it mainVect_it = mainVect.begin();
	vectorOfVectors mainChain;
	vectorOfVectors paind;
	
	
	// numbers: [0,1][5,50][71,91][6,89]
	// *it : [0,1]
	while (mainVect.size() > 1) {
		if (mainVect.size() % 2 != 0) {
			mergePairInVector(mainVect.back(), rest);
			mainVect.pop_back();
		}
		while (mainVect_it != mainVect.end())
		{
			myPair tmp;
			// vectOfPrs_it pair1_it = it;
			// vectOfPrs_it pair2_it = (it + 1);
			if ((*mainVect_it).second.back() <= (*(mainVect_it + 1)).second.back())
				tmp = mergePairs(*mainVect_it, *(mainVect_it + 1));
			// (*it).second.back() : 1
			// (*(it + 1)).second.back() : 50
			// tmp : [0 1,5 50]
			else
				tmp = mergePairs(*(mainVect_it + 1), *mainVect_it);
		
			mainVect.erase(mainVect_it);
			// numbers : [5,50][71,91][6,89]
			mainVect.erase(mainVect_it);
			// numbers : [71,91][6,89]
			mainVect.insert(mainVect_it, tmp);
			mainVect_it++;
		}
		// numbers : [0->1,5->50][71,91][6,89]
		Psort();
		if (sortedChain.empty())
			fill_sortedChain();
		else {
			vofvs_it sortedChain_it = sortedChain.begin();
			int count = 0;
			while (sortedChain_it != sortedChain.end()) {
				vector tmp;
				vect_it vector_it = (*sortedChain_it).begin();
				while (vector_it != (*sortedChain_it).end()) {
					tmp.push_back(*vector_it);
					vector_it++;
				}
				count++;
				if (count > 3 || count % 2 == 0)
					mainChain.push_back(tmp);
				else
					paind.push_back(tmp);
				if (!rest.empty())
					paind.push_back(rest);
				insurtPaindInmainChain(&mainChain, paind);
				sortedChain_it++;
			}
		}
	}
}