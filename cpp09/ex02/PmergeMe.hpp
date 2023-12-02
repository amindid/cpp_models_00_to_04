/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:15:06 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/02 13:15:46 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<unsigned int> vector;
typedef vector::iterator vect_it;
// typedef std::vector<vector> vecotrOfVectors;
typedef std::pair<vector, vector> myPair;
typedef std::vector<myPair> vectorOfPairs;
typedef vectorOfPairs::iterator vectOfPrs_it;
typedef std::vector<vector> vectorOfVectors;
typedef vectorOfVectors::iterator vofvs_it;

class PmergeMe {
	private:
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		myPair mergePairs(myPair pair1, myPair pair2);
		void mergePairInVector(myPair pair, vector & vect);
		void fill_sortedChain(void);
		void first_fill(void);
		void insurtPaindInmainChain(vectorOfVectors &mainChain,vectorOfVectors paind);
	public:
		vectorOfPairs mainVect;
		vector firstInput;
		vectorOfVectors sortedChain;
		PmergeMe();
		~PmergeMe();
		void Psort();
};