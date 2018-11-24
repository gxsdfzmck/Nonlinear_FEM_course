#include <iostream>
#include "ParametricInterpolationLagrange.h"
#include "readData.h"
using namespace std;

int main(int argc, char **argv)
{
  const char *fileName = "data.txt";
  MatrixXf data;
  data = readData(fileName);
  
  // nodes per element
  int nnpe = 11;
  
  ParametricInterpolationLagrange paraLagrange(nnpe);

  // Length of element
  double Le = 10;
  
  // The x coordinate of the point
  double X = 1.5;

  // Calculate the parametric coordinate at x=1.5
  double Xi = paraLagrange.Xi_start + paraLagrange.L_Xi* (X / Le);

  // Extract the node value from data
 // VectorXd nodeValues = data.rightCols(1);


  return 0;
}
