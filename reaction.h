/*
 * reaction.h
 *
 *  Created on: Jul 5, 2018
 *      Author: zeil
 */

#ifndef REACTION_H_
#define REACTION_H_

#include <map>
#include <string>
#include <vector>

/**
 * A description of what happens when one unit of a single chemical is
 * mixed with one unit of another.
 */
struct Reaction {
  std::string chemical1;  ///>  First chemical
  std::string chemical2;  ///>  Second chemical
  int tempChange;         ///> Temperature change induced.
};

/**
 *  Find the maximum temperature change that can be induced by
 *  pairwise reactions among given quantities of various chemicals.
 *
 *  @param quantities: a mapping from chemical names to
 *                     the quantities of those chemicals available.
 *  @param reactions: a list of the possible reactions and their corresponding
 *                    temperature changes
 */
int findMaxTemp (std::map<std::string,int>& quantities,
		 	     std::vector<Reaction>& reactions);




#endif /* REACTION_H_ */
