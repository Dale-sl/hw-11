/*
 * Declarations for ClimbChromosome, a child
 * of Chromosome that uses local hill climbing
 */

#pragma once

#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
  using Chromosome::Chromosome;
  void mutate() override;
  Chromosome* clone() const override;
};
