#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

#include "reaction.h"

using namespace std;

struct higherDegree {
    bool operator()(Reaction const & r1, Reaction const & r2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return r1.tempChange < r2.tempChange;
    }
};
int tempRise =0, highest = 0;
map<string,int> used;
int permuteHelper(vector<Reaction>& reactions, map<string,int>&quantities,vector<Reaction>chosen/*, vector<vector<pair<string, int>>>vect*/)
{
    if(reactions.size() == 0)
    {
        if(tempRise>highest)
            highest = tempRise;
    }
    else{
        for (int it =0; it < reactions.size(); it++)
        {

            cerr<<it<<endl;
            cerr<<"chem1: /"<<quantities[reactions[it].chemical1]<<" chem2: /"<<quantities[reactions[it].chemical2]<<endl;
            Reaction temp = reactions[it];
            if((quantities[reactions[it].chemical1] - used[reactions[it].chemical1]) !=0 || (quantities[reactions[it].chemical2]-used[reactions[it].chemical2]) !=0){
                int bigger = min(quantities[reactions[it].chemical1], quantities[reactions[it].chemical2]);
                int change =  bigger * reactions[it].tempChange;
                cerr<<"change: //"<<change<<endl;
                tempRise += change;
                quantities[reactions[it].chemical1] -= min(quantities[reactions[it].chemical1], quantities[reactions[it].chemical2]);
                quantities[reactions[it].chemical2] -= min(quantities[reactions[it].chemical1], quantities[reactions[it].chemical2]);
                if(used.find(reactions[it].chemical1)!=used.end())
                    used.emplace(reactions[it].chemical1, bigger);
                else
                    used[reactions[it].chemical1] -= bigger;
                if(used.find(reactions[it].chemical2)!=used.end())
                    used.emplace(reactions[it].chemical2, bigger);
                else
                    used[reactions[it].chemical2] -= bigger;
            }
            chosen.push_back(temp);
            auto it1 = reactions.begin();
            while(it1->chemical1 !=temp.chemical1 && it1->chemical2 != temp.chemical2)
                it1++;
            reactions.erase(it1);
            permuteHelper(reactions, quantities, chosen/*, vect*/);

            reactions.emplace(reactions.begin(),temp);
            chosen.pop_back();
            used[reactions[it].chemical1] += quantities[reactions[it].chemical1];
            used[reactions[it].chemical2] += quantities[reactions[it].chemical2];

        }

    }
    return highest;
}
/**
 *  Find the maximum temperature change that can be induced by
 *  pairwise reactions among given quantities of various chemicals.
 *
 *  @param quantities: a mapping from chemical names to
 *                     the quantities of those chemicals available.
 *  @param reactions: a list of the possible reactions and their corresponding
 *                    temperature changes
 */
int findMaxTemp (map<string,int>& quantities,
		 	     vector<Reaction>& reactions)
{
    /*int num = 0;
    vector<vector<pair<string,int> vect;
    for<auto it1 = reactions.begin(); it1!=reactions.end(); it++)
    {
        vector<map<string,int> p;
        vect.push_back(p);
        for(auto it = quantities.begin(); it !=quantities.end(); it++)
        {
            vect[num].push_back(it->first, it->second);
        }
        num++
    }*/
    vector<Reaction>chosen;
    permuteHelper(reactions, quantities, chosen/*, vect*/);
    return tempRise;

}


