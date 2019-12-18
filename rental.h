#ifndef RENTAL_H
#define RENTAL_H
#include "irental.h"
#include "imovie.h"

class Rental : public IRental {
public :
  Rental(const IMovie& movie,  int days_rented);

  const std::string getMovieName() const override;
  int GetFrequentRenterPoints() const override;


  double GetAmount() const override;

private:
  const IMovie& movie_;
  const int days_rented_;
};

#endif // RENTAL_H
