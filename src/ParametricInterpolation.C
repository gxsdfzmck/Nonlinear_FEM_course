//
#include "ParametricInterpolation.h"

ParametricInterpolation::ParametricInterpolation(int _NNPE = 0, double _Xi_start = -1, _L_Xi = 2) : 
  NNPE(_NNPE), Xi_start(_Xi_start), L_Xi(_L_Xi)
{
  NodeXi = calculateParametricNodeLocations();
}

VectorXd ParametricInterpolation::calculateShapeFunctions(double Xi)
{
  VectorXd N(NNPE);
  return N;
}

VectorXd ParametricInterpolation::calculateDerivativeOfShapeFunctions_WRT_Xi(double Xi)
{
  Vector dNdXi(NNPE);
  return dNdXi;
}

VectorXd ParametricInterpolation::calculateDerivativeOfShapeFunctions_WRT_X(double Xi, double Le)
{
  return calculateDerivativeOfShapeFunctions_WRT_Xi(Xi) * (L_Xi / Le);
}

double ParametricInterpolation::interpolateVariable(double Xi, VectorXd variableNodalValues)
{
  VectorXd N = calculateShapeFunction(Xi);
  return interpolateVariable(variableNodalValues, N);
}

double ParametricInterpolation::interpolateVariable(VectorXd variableNodalValues, VectorXd N)
{
  return variableNodalValues.dot(N);
}

double ParametricInterpolation::interpolateDerivativeOfVariable_WRT_Xi(double Xi, VectorXd variableNodalValues)
{
  VectorXd dNdXi = calculateDerivativeOfShapeFunctions_WRT_Xi(Xi);
  return interpolateDeriavtiveOfVariable_WRT_Xi(variableNodalVinterpolateVariableDerivativeOfVariable_WRT_Xialues, dNdXi);
}

double ParametricInterpolation::interpolateDerivativeOfVariable_WRT_Xi(VectorXd variableNodalValues, VectorXd dNdXi)
{
  return variableNodalValues.dot(dNdXi);
}

double ParametricInterpolation::interpolateDerivativeOfVariable_WRT_X(double Xi, double Le, VectorXd variableNodalValues)
{
  VectorXd dNdXi = calculateDerivativeOfShapeFunctions_WRT_Xi(Xi);
  return interpolateDeriavtiveOfVariable_WRT_X(Le, variableNodalValues, dNdXi);
}

double ParametricInterpolation::interpolateDerivativeOfVariable_WRT_X(double Le, VectorXd variableNodalValues, VectorXd dNdXi)
{
  return variableNodalValues.dot(dNdXi) * L_Xi / Le;
}

void ParametricInterpolation::calculateElementRealNodeLocation(double xStart, double xEnd, vector<Node> ElementNodes)
{
  for(int i = 0; i< NNPE; i++)
  {
    ElementNodes[i].X = calculateX(xStart, xEnd, NodeXi(i));
  }
}

VectorXd ParametricInterpolation::calculateNodeX(vector<Node> ElementNodes)
{
  int nnpe = ElementNodes.size();
  VectorXd X(nnpe);
  for(int i = 0; i < nnpe; i++)
  {
    X(i) = CalculateX(ElementNodes, NodeXi(i));
  }
  return X;
}

double ParametricInterpolation::calculateX(vector<Node> ElementNodes, double Xi)
{
  return CalculateX(ElementNodes[0].X, ElementNodes[NNPE-1].X, Xi);
}

double ParametricInterpolation::calculateX(double xStart, double xEnd, double Xi)
{
  return xStart + (xEnd - xStart) * (Xi - Xi_start) / L_Xi;
}

VectorXd ParametricInterpolation::calculateParametricNodeLocations()
{
  VecotrXd NodeXi(NNPE);
  double DXi = L_Xi / double(NNPE - 1);
  NodeXi(0) = Xi_start;
  for(int p = 1;p < NNPE; p++)
  {
    NodeXi(p) = NodeXi(p-1) + DXi;
    return NodeXi;
  }
