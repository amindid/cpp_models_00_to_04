/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:15:06 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/12 11:03:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

// vector
typedef std::vector<unsigned int> vector;
typedef vector::iterator vect_it;
typedef std::pair<vector, vector> myPair;
typedef std::vector<myPair> vectorOfPairs;
typedef vectorOfPairs::iterator vectOfPrs_it;
typedef std::vector<vector> vectorOfVectors;
typedef vectorOfVectors::iterator vofvs_it;
typedef std::vector<std::pair<vector, vofvs_it> > Paind;
typedef Paind::iterator Paind_iter;

// list
typedef std::list<unsigned int> List;
typedef List::iterator List_it;
typedef std::pair<List, List> listPair;
typedef std::list<listPair> listOfPairs;
typedef listOfPairs::iterator listOfPairs_it;
typedef std::list<List> listOfLists;
typedef listOfLists::iterator listOfLists_it;
typedef std::list<std::pair<List, listOfLists_it> > listPaind;
typedef listPaind::iterator listPaind_it;

class PmergeMe {
	private:
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);

		// vector
		myPair mergePairs(myPair pair1, myPair pair2);
		void mergePairInVector(myPair pair, vector & vect);
		void fill_sortedChain(void);
		void first_fill(void);
		void insurtPaindInmainChain(vectorOfVectors &mainChain,Paind &paind);
		static bool myCompare(vector vect, vector value);
		void fillMainChainAndPaind(vectorOfVectors &mainChain, Paind &paind);
		void updateIterator(Paind &paind, vofvs_it insurtPos);
		void Psort_vector();
		vectorOfPairs mainVect;
		vectorOfVectors sortedChain;

		// list
		listPair mergePairs_list(listPair pair1, listPair pair2);
		void mergePairInVector_list(listPair pair, List & vect);
		void fill_sortedChain_list(void);
		void first_fill_list(void);
		void insurtPaindInmainChain_list(listOfLists &mainChain,listPaind &paind);
		static bool myCompare_list(List vect, List value);
		void fillMainChainAndPaind_list(listOfLists &mainChain, listPaind &paind);
		void Psort_list();
		listOfPairs mainList;
		listOfLists sortedList;
		
		int jacobStl[15];
	public:
		PmergeMe();
		~PmergeMe();
		void Psort();
		// vector
		vector firstInput;
		
		// list
		List firstInputList;
};