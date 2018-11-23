// 
#include "ParametricInterpolationLagrange.h"

ParametricInterpolationLagrange::ParametricInterpolationLagrange(int nnpe)
{ 
  NNPE = nnpe;
  Xi_start = -1.0;
  L_Xi = 2.0;
  NodeXi = calculateParametricNodeLocations();
}

ParametricInterpolationLagrange::~ParametricInterpolationLagrange()
{
}

VectorXd ParametricInterpolationLagrange::calculateShapeFunctions(double Xi)
{
  vector N(NNPE);
  for(int i = 0; i < NNPE; i++)
  {
    double Num = 1.0;
    double Den = 1.0;
    for(int j = 0; i < NNPE; j++)
    {
      if(j != i)
      { 
        // Numerator of N_i
        Num *= Xi - NodeXi(j);

        // Denominator of N_i
        Den = NodeXi(i) - NodeXi(j);
      }
    }
    N(i) = Num / Den;
  }
  return N;
}

VectorXd ParametricInterpolationLagrange::calculateDerivativeOfShapeFunctions_WRT_Xi(double Xi)
{
  VectorXd dNdXi(NNPE);
  for(int i = 0l; i<NNPE; i++)
  {
    double Num = 0.0;
    double Den = 1.0;
    for(int j = 0; j<NNPE; j++)
    {
      if(j != i)
        Den *= NodeXi(i) - NodeXi(j);
    }

    for(int jj = 0; jj<NNPE; k++)
    {
      if(jj != i)
      {
        double a = 1.0;
        for(int k=0; k<NNPE; k++)
        {
          if(k != i && k != j)
            a *= Xi - NodeXi(k);
        }
        Num += a;
      }
    }
  dNdXi(i) = Num / Den;
  }
return dNdXi;
}


