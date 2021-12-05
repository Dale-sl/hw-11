/*
 * Implementation for Chromosome class
 */

#include <algorithm>
#include <cassert>

#include "chromosome.hh"
#include "climb_chromosome.hh"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// local hill climbing mutation operator
// mutates left and right index of a random index, then returns
// the best mutation of the three
void
ClimbChromosome::mutate() {
  uniform_int_distribution<int> dist(0, order_.size() - 1);
  int randomIndex = randomIndexdist(generator_);

  // create new mutation, swap left index.
  // in the case the left index is invalid, use the last index instead.
  Chromosome* swapLeft = clone();
  if (randomIndex == 0) {
    std::swap(order_[order_.size() - 1], order_[randomIndex]);
  } else {
    std::swap(order_[randomIndex - 1], order_[randomIndex]);
  }

  // create new mutation, swap right index.
  // in the case the right index is invalid, use the first index instead.
  Chromosome* swapRight = clone();
  if (randomIndex == order_.size() - 1) {
    std::swap(order_[0], order_[randomIndex]);
  } else {
    std::swap(order_[randomIndex + 1], order_[randomIndex]);    
  }

  // set order to the order of the best mutation
  double currentFitness = get_fitness();
  double leftFitness = swapLeft.get_fitness();
  double rightFitness = swapRight.get_fitness();
  if (currentFitness < leftFitness) {
    if (rightFitness > leftFitness) {
      order_ = swapRight.order_;
    } else {
      order_ = swapLeft.order_;
    }
  }
  
  assert(is_valid());
}
//////////////////////////////////////////////////////////////////////////////
// override of clone to return object of ClimbChromosome type
Chromosome*
ClimbChromosome::clone() {
  return new climbChromosome(*this);
}
