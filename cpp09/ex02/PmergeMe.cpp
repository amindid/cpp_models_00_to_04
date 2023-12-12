/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:49:33 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/12 10:45:36 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	int arr[15] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846};
	memcpy(jacobStl, arr, sizeof(arr));
}
PmergeMe::PmergeMe(const PmergeMe &copy){
	(void)copy;
}
PmergeMe::~PmergeMe(){}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	(void)copy;
	return *this;
}

void PmergeMe::Psort(void) {
	vect_it it = firstInput.begin();
	std::cout << "Befor: ";
	while (it != firstInput.end()) {
		std::cout << (*it) << " " ;
		it++;
	}
	std::cout << std::endl;
	unsigned long start = std::clock();
	Psort_vector();
	unsigned long end = std::clock();
	double VectorDuration = (double)(end - start) / CLOCKS_PER_SEC;
	start = std::clock();
	Psort_list();
	end = std::clock();
	double ListDuration = (double)(end - start) / CLOCKS_PER_SEC;
	listOfLists_it iter = sortedList.begin();
	std::cout << "After: ";
	while (iter != sortedList.end()) {
		std::cout << (*iter).front() << " " ;
		iter++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << sortedChain.size() << " elements with std::vector : " \
	<< VectorDuration * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << sortedList.size() << " elements with std::list : " \
	<< ListDuration * 1000 << " ms" << std::endl;
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

bool PmergeMe::myCompare(vector vect, vector value) {
	return (vect.back() <= value.back() ? true : false);
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
	vector tmp;
	vect_it vit = (*it).first.begin();
	while (vit != (*it).first.end()) {
		tmp.push_back(*vit);
		vit++;
	}
	vit = (*it).second.begin();
	while (vit != (*it).second.end()) {
		tmp.push_back(*vit);
		vit++;
	}
	sortedChain.push_back(tmp);
}

void PmergeMe::updateIterator(Paind &paind, vofvs_it insurtPos) {
	Paind_iter pnd_it = paind.begin();
	while(pnd_it != paind.end()) {
		if (pnd_it->second >= insurtPos)
			(*pnd_it).second++;
		pnd_it++;
	}
}

void PmergeMe::insurtPaindInmainChain(vectorOfVectors &mainChain, Paind &paind) {
	for (unsigned int i = 0; i < 15; i++) {
		if (paind.empty())
			return;
		unsigned int befor = jacobStl[i];
		Paind_iter it = paind.begin();
		if (paind.size() <= befor) {
			it += paind.size() - 1;
			befor = paind.size();
		}
		else
			it += befor - 1;
		int eraseCount = 0;
		for (unsigned int j = befor; j > 0; j--) {
			if (paind.empty())
				return;
			else {
				vofvs_it insurtPos = std::lower_bound(mainChain.begin(), it->second, it->first, PmergeMe::myCompare);
				mainChain.insert(insurtPos, it->first);
				updateIterator(paind, insurtPos);
				eraseCount++;
				it--;
			}
		}
		while (eraseCount > 0) {
			paind.erase(paind.begin());
			eraseCount--;
		}
	}
}

void PmergeMe::fillMainChainAndPaind(vectorOfVectors &mainChain, Paind &paind) {
	vofvs_it sortedChain_it = sortedChain.begin();
	int count = 1;
	while (sortedChain_it != sortedChain.end()) {
		if (count <= 2 || count % 2 == 0)
			mainChain.push_back(*sortedChain_it);
		else {
			vector tmp = *sortedChain_it;
			sortedChain_it++;
			if (sortedChain_it != sortedChain.end()) {
				mainChain.push_back(*sortedChain_it);
				
				vofvs_it tracker = mainChain.end();
				tracker--;
				paind.push_back(std::make_pair(tmp, tracker));
			}
			else {
				paind.push_back(std::make_pair(tmp, mainChain.end()));
				break;
			}
			count++;
		}
		count++;
		sortedChain_it++;
	}
}

void PmergeMe::Psort_vector() {
	vector rest;
	vectOfPrs_it mainVect_it = mainVect.begin();
	vectorOfVectors mainChain;
	Paind paind;
	if (mainVect.size() == 0) {
		if (firstInput.size() % 2 != 0) {
			rest.push_back(firstInput.back());
			firstInput.pop_back();
		}
		first_fill();
	}
	else {
		if (mainVect.size() % 2 != 0) {
			mergePairInVector(mainVect.back(), rest);
			mainVect.pop_back();
		}
		while (mainVect_it != mainVect.end())
		{
			myPair tmp;
			if ((*mainVect_it).second.back() <= (*(mainVect_it + 1)).second.back())
				tmp = mergePairs(*mainVect_it, *(mainVect_it + 1));
			else
				tmp = mergePairs(*(mainVect_it + 1), *mainVect_it);
			mainVect.erase(mainVect_it);
			mainVect.erase(mainVect_it);
			mainVect.insert(mainVect_it, tmp);
			mainVect_it++;
		}
	}
	if (mainVect.size() > 1)
		Psort_vector();
	if (sortedChain.empty())
		fill_sortedChain();
	vofvs_it sortedChain_it = sortedChain.begin();
	vectorOfVectors tmpHolder;
	while (sortedChain_it != sortedChain.end()) {
		vector tmp1;
		vect_it tmp1_it = (*sortedChain_it).begin();
		unsigned long sizecount = 1;
		while (sizecount <= (*sortedChain_it).size() / 2) {
			tmp1.push_back((*tmp1_it));
			tmp1_it++;
			sizecount++;
		}
		tmpHolder.push_back(tmp1);
		tmp1.clear();
		while (tmp1_it != (*sortedChain_it).end()) {
			tmp1.push_back((*tmp1_it));
			tmp1_it++;
		}
		tmpHolder.push_back(tmp1);
		sortedChain_it++;
	}
	sortedChain.clear();
	sortedChain = tmpHolder;
	if (!rest.empty())
		sortedChain.push_back(rest);
	mainChain.reserve(sortedChain.size());
	fillMainChainAndPaind(mainChain, paind);
	if (!paind.empty())
		insurtPaindInmainChain(mainChain, paind);
	sortedChain.clear();
	sortedChain = mainChain;
}

// list

listPair PmergeMe::mergePairs_list(listPair pair1, listPair pair2) {
	listPair pair;

	List_it it = pair1.first.begin();
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

bool PmergeMe::myCompare_list(List myList, List value) {
	return (myList.back() <= value.back() ? true : false);
}

void PmergeMe::mergePairInVector_list(listPair pair, List &myList) {
	List_it it;
	it = pair.first.begin();
	while (it != pair.first.end()) {
		myList.push_back(*it);
		it++;
	}
	it = pair.second.begin();
	while (it != pair.second.end()) {
		myList.push_back(*it);
		it++;
	}
}

void PmergeMe::first_fill_list(void) {
	List_it it = firstInputList.begin();
	while (it != firstInputList.end()) {
		List tmp1;
		List tmp2;
		tmp1.push_back(*it);
		it++;
		tmp2.push_back(*it);
		it++;	
		if (*(tmp1.begin()) <= *(tmp2.begin()))
			mainList.push_back(std::make_pair(tmp1, tmp2));
		else
			mainList.push_back(std::make_pair(tmp2, tmp1));
	}
}

void PmergeMe::fill_sortedChain_list(void) {
	listOfPairs_it it = mainList.begin();
	List tmp;
	List_it vit = (*it).first.begin();
	while (vit != (*it).first.end()) {
		tmp.push_back(*vit);
		vit++;
	}
	vit = (*it).second.begin();
	while (vit != (*it).second.end()) {
		tmp.push_back(*vit);
		vit++;
	}
	sortedList.push_back(tmp);
}

void PmergeMe::insurtPaindInmainChain_list(listOfLists &mainChain, listPaind &paind) {
	for (unsigned int i = 0; i < 15; i++) {
		if (paind.empty())
			return;
		unsigned int befor = jacobStl[i];
		listPaind_it it = paind.begin();
		if (paind.size() <= befor) {
			std::advance(it, paind.size() - 1);
			befor = paind.size();
		}
		else
			std::advance(it, befor - 1);
		int eraseCount = 0;
		for (unsigned int j = befor; j > 0; j--) {
			if (paind.empty())
				return;
			else {
				listOfLists_it insurtPos = std::lower_bound(mainChain.begin(), it->second, it->first, PmergeMe::myCompare_list);
				mainChain.insert(insurtPos, it->first);
				eraseCount++;
				it--;
			}
		}
		while (eraseCount > 0) {
			paind.erase(paind.begin());
			eraseCount--;
		}
	}
}

void PmergeMe::fillMainChainAndPaind_list(listOfLists &mainChain, listPaind &paind) {
	listOfLists_it sortedList_it = sortedList.begin();
	int count = 1;
	while (sortedList_it != sortedList.end()) {
		if (count <= 2 || count % 2 == 0)
			mainChain.push_back(*sortedList_it);
		else {
			List tmp = *sortedList_it;
			sortedList_it++;
			if (sortedList_it != sortedList.end()) {
				mainChain.push_back(*sortedList_it);
				
				listOfLists_it tracker = mainChain.end();
				tracker--;
				paind.push_back(std::make_pair(tmp, tracker));
			}
			else {
				paind.push_back(std::make_pair(tmp, mainChain.end()));
				break;
			}
			count++;
		}
		count++;
		sortedList_it++;
	}
}

void PmergeMe::Psort_list() {
	List rest;
	listOfPairs_it mainList_it = mainList.begin();
	listOfLists mainChain;
	listPaind paind;
	if (mainList.size() == 0) {
		if (firstInputList.size() % 2 != 0) {
			rest.push_back(firstInputList.back());
			firstInputList.pop_back();
		}
		first_fill_list();
	}
	else {
		if (mainList.size() % 2 != 0) {
			mergePairInVector_list(mainList.back(), rest);
			mainList.pop_back();
		}
		while (mainList_it != mainList.end())
		{
			listPair tmp;
			listOfPairs_it mainList_it_next = mainList_it;
			mainList_it_next++;
			if ((*mainList_it).second.back() <= (*mainList_it_next).second.back())
				tmp = mergePairs_list(*mainList_it, *mainList_it_next);
			else
				tmp = mergePairs_list(*mainList_it_next, *mainList_it);
			mainList_it = mainList.erase(mainList_it);
			mainList_it = mainList.erase(mainList_it);
			mainList_it = mainList.insert(mainList_it, tmp);
			std::advance(mainList_it, 1);
		}
	}
	if (mainList.size() > 1)
		Psort_list();
	if (sortedList.empty())
		fill_sortedChain_list();
	listOfLists_it sortedList_it = sortedList.begin();
	listOfLists tmpHolder;
	while (sortedList_it != sortedList.end()) {
		List tmp1;
		List_it tmp1_it = (*sortedList_it).begin();
		unsigned long sizecount = 1;
		while (sizecount <= (*sortedList_it).size() / 2) {
			tmp1.push_back((*tmp1_it));
			tmp1_it++;
			sizecount++;
		}
		tmpHolder.push_back(tmp1);
		tmp1.clear();
		while (tmp1_it != (*sortedList_it).end()) {
			tmp1.push_back((*tmp1_it));
			tmp1_it++;
		}
		tmpHolder.push_back(tmp1);
		sortedList_it++;
	}
	sortedList.clear();
	sortedList = tmpHolder;
	if (!rest.empty())
		sortedList.push_back(rest);
	fillMainChainAndPaind_list(mainChain, paind);
	if (!paind.empty())
		insurtPaindInmainChain_list(mainChain, paind);
	sortedList.clear();
	sortedList = mainChain;
}