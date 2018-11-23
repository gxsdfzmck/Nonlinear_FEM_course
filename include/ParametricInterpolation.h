//
#ifndef PARAMETRICINTERPOLATION_H
#define PARAMETRICINTERPOLATION_H
#include <iostream>
#include <vector>
#include "eigen/Eigen/Core"
#include "eigen/Eigen/Dense"
#include "Node.h"

using namespace std;
using namespace Eigen;

// Forward delcaration
class ParametricInterpolation;

class ParametricInterpolation
{
public:
  ParametricInterpolation(int _NNPE = 0, double _Xi_start = -1, int _L_Xi = 2);

  // Number of nodes per element
  const int NNPE;

  // Node locations
  VectorXd NodeXi;

  // Parametric domain [Xi_start, Xi_start+L_Xi]
  const double Xi_start, L_Xi;

  virtual VectorXd calculateShapeFunctions(double Xi);

  virtual VectorXd calculateDerivativeOfShapeFunctions_WRT_Xi(double Xi);

  virtual VectorXd calculateDerivativeOfShapeFunctions_WRT_X(double Xi, double Le);

  virtual double interpolateVariable(double Xi, VectorXd variableNodalValues);

  virtual double interpolateVariable(VectorXd variableNodalValues, VectorXd N);

  virtual double interpolateDerivativeOfVariable_WRT_Xi(double Xi, VectorXd variableNodalValues);

  virtual double interpolateDerivativeOfVariable_WRT_Xi(VectorXd variableNodalValues, VectorXd dNdXi);

  virtual double interpolateDeriavtiveOfVariable_WRT_X(double Le, VectorXd variableNodalValues, VectorXd dNdXi);

  virtual double interpolateDeriavtiveOfVariable_WRT_X(double Xi, double Le, VectorXd variableNodalValues);

  virtual void calculateElementRealNodeLocation(double xStart, double xEnd, vector<Node> ElementNodes); 

  VectorXd calculateNodeX(vector<Node> ElementNodes);

  virtual double calculateX(double xStart, double xEnd, double Xi);

  virtual double calculateX(vector<Node> ElementNodes, double Xi);

  virtual VectorXd calculateParametricNodeLocations();

};
#endif
