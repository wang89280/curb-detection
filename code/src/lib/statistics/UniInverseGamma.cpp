#include "UniInverseGamma.h"

#include <iostream>
#include <fstream>

#include <math.h>

using namespace std;

UniInverseGamma::UniInverseGamma(double f64Alpha, double f64Beta)
  throw (OutOfBoundException) : mf64Alpha(f64Alpha),
                                mf64Beta(f64Beta) {
  if (mf64Alpha <= 0)
    throw OutOfBoundException("UniInverseGamma::UniInverseGamma(): mf64Alpha should be bigger than 0");
  if (mf64Beta <= 0)
    throw OutOfBoundException("UniInverseGamma::UniInverseGamma(): mf64Beta should be bigger than 0");
}

UniInverseGamma::UniInverseGamma(const UniInverseGamma& other)
  : mf64Alpha(other.mf64Alpha),
    mf64Beta(other.mf64Beta) {
}

UniInverseGamma& UniInverseGamma::operator = (const UniInverseGamma& other) {
  mf64Alpha = other.mf64Alpha;
  mf64Beta = other.mf64Beta;
  return *this;
}

UniInverseGamma::~UniInverseGamma() {
}

void UniInverseGamma::read(istream& stream) {
}

void UniInverseGamma::write(ostream& stream) const {
}

void UniInverseGamma::read(ifstream& stream) {
}

void UniInverseGamma::write(ofstream& stream) const {
}

ostream& operator << (ostream& stream,
  const UniInverseGamma& obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream& stream,
  UniInverseGamma& obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream& stream,
  const UniInverseGamma& obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream& stream,
  UniInverseGamma& obj) {
  obj.read(stream);
  return stream;
}

double UniInverseGamma::pdf(double f64X) const throw (OutOfBoundException) {
  if (f64X < 0)
    throw OutOfBoundException("UniInverseGamma::pdf(): f64X should be bigger or equal to 0");
  return (pow(mf64Beta, mf64Alpha) / tgamma(mf64Alpha)) *
    pow(f64X, -mf64Alpha - 1) * exp(-mf64Beta / f64X);
}

double UniInverseGamma::logpdf(double f64X) const throw (OutOfBoundException) {
  if (f64X < 0)
    throw OutOfBoundException("UniInverseGamma::logpdf(): f64X should be bigger or equal to 0");
  return (mf64Alpha * log(mf64Beta)) - lgamma(mf64Alpha) -
    ((mf64Alpha + 1) * log(f64X)) - (mf64Beta / f64X);
}

double UniInverseGamma::getAlpha() const {
  return mf64Alpha;
}

double UniInverseGamma::getBeta() const {
  return mf64Beta;
}

void UniInverseGamma::setAlpha(double f64Alpha) throw (OutOfBoundException) {
  mf64Alpha = f64Alpha;
  if (mf64Alpha <= 0)
    throw OutOfBoundException("UniInverseGamma::setAlpha(): mf64Alpha should be bigger than 0");
}

void UniInverseGamma::setBeta(double f64Beta) throw (OutOfBoundException) {
  mf64Beta = f64Beta;
  if (mf64Beta <= 0)
    throw OutOfBoundException("UniInverseGamma::setBeta(): mf64Beta should be bigger than 0");
}