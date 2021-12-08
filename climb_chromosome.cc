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
  uniform_int_distribution<unsigned int> dist(0, order_.size() - 1);
  unsigned int randomIndex = dist(generator_);

  // create new mutation, swap left index.
  // in the case the left index is invalid, use the last index instead.
  vector<unsigned int> swapLeft = order_;
  if (randomIndex == 0) {
    std::swap(swapLeft[order_.size() - 1], swapLeft[randomIndex]);
  } else {
    std::swap(swapLeft[randomIndex - 1], swapLeft[randomIndex]);
  }

  // create new mutation, swap right index.
  // in the case the right index is invalid, use the first index instead.
  vector<unsigned int> swapRight = order_;
  if (randomIndex == order_.size() - 1) {
    std::swap(swapRight[0], swapRight[randomIndex]);
  } else {
    std::swap(swapRight[randomIndex + 1], swapRight[randomIndex]);    
  }

  // set order to the order of the best mutation
  double currentFitness = get_fitness();
  vector<unsigned int> currentOrder = order_;
  order_ = swapLeft;
  double leftFitness = get_fitness();
  order_ = swapRight;
  double rightFitness = get_fitness();
  if (currentFitness < leftFitness) {
    if (rightFitness > leftFitness) {
      order_ = swapRight;
    } else {
      order_ = swapLeft;
    }
  } else if (currentFitness > rightFitness) {
    order_ = currentOrder;
  }

  assert(is_valid());
}
//////////////////////////////////////////////////////////////////////////////
// override of clone to return object of ClimbChromosome type
Chromosome*
ClimbChromosome::clone() const {
  return new ClimbChromosome(*this);
}
