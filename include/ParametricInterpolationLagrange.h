#ifndef PARAMETRICINTERPOLATIONLAGRANGE_H
#define PARAMETRICINTERPOLATIONLAGRANGE_H
#include "ParametricInterpolation.h"

//Forward declaration
class ParametricInterpolationLagrange;

class ParametricInterpolationLagrange: public ParametricInterpolation
{
public:
  //constructor
  ParametricInterpolationLagrange(int nnpe);

  // deconstructor
  ~ParametricInterpolationLagrange();

  /**
   * Calculate the shape function N(Xi) 
   * @param Xi the parametric location derived derived from the actual location
   */
  VectorXd calculateShapeFunctions(double Xi) override;

  /**
   * Calculate dN/dXi
   * @param Xi the parametric location
   */
  VectorXd calculateDerivativeOfShapeFunctions_WRT_Xi(double Xi) override;
};
#endif
