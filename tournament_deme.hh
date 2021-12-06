

#include "deme.hh"

#pragma once

class TournamentDeme : public Deme{
  public:
  
 protected:
  // Randomly select a chromosome in the population based on fitness and
  // return a pointer to that chromosome.
  virtual Chromosome* select_parent();

  virtual Chromosome* tournament_selection();

  std::vector<Chromosome*> pop_;  // Population of Chromosomes
  

  std::default_random_engine generator_; // A random number generator for the various methods
};