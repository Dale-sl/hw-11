

#include "deme.hh"

#pragma once

class TournamentDeme : public Deme{
  public:
  using Deme::Deme;
 protected:
  // Randomly select a chromosome in the population based on fitness and
  // return a pointer to that chromosome.
  virtual Chromosome* select_parent();

  virtual Chromosome* tournament_selection();
};
