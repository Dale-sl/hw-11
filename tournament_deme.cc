#include "chromosome.hh"
#include "deme.hh"
#include "tournament_deme.hh"
#include <algorithm>
#include <vector>
#include <iostream>
#include "cities.hh"
#include "cassert"

using namespace std;

Chromosome* TournamentDeme::select_parent(){
  return TournamentDeme::tournament_selection(); //use the new tournament method for select parent
}

Chromosome* TournamentDeme::tournament_selection(){
  std::vector<Chromosome*> tournament_parents;    //vector for storing the random parents out of the population vector pop_
  std::sample(pop_.begin(), pop_.end(), std::back_inserter(tournament_parents), 8, generator_);   //p = 8, get 8 random parents from the population vector of chromosomes and put them in the tournament_parents vector 
  while (tournament_parents.size() > 1){      
  for (uint64_t i=0; i<tournament_parents.size()/2; i++){     //look at pairs in the tournament_vector
    double x_pair = tournament_parents[i]->get_fitness();     //get two parents for the pair, the first being x
    double y_pair = tournament_parents[i+1]->get_fitness();   //the second being y
    if (x_pair > y_pair){ 
      tournament_parents.erase(tournament_parents.begin()+i+1);   //if the x fitness value is greater have it move on by erasing y from the tournament vector
    }
    else if (y_pair > x_pair){  
      tournament_parents.erase(tournament_parents.begin()+i);     //if the y fitness value is graeter have it move on by erasing x from the tournament vector
    }
    else if (y_pair == x_pair){
      tournament_parents.erase(tournament_parents.begin()+i+1);   //if the pairs fitness values are equal to eachother I choose to erase y from the vector 
    }
  }
  }
  //std::assert(tournament_parents.size() == 1);
  return tournament_parents[0];   //return the last remaining element in the vector wtih the highest fitness value
}