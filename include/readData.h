#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "eigen/Eigen/Dense"
#include "eigen/Eigen/Core"

using namespace std;
using namespace Eigen;

MatrixXf readData(const char * fileName)
{
  const int row = 11;
  const int col = 2;
  MatrixXf data(row, col);
  ifstream readFile;
  readFile.open(fileName);
  if(!readFile)
  {
    cerr<<"Unable to open file:"<<fileName<<endl;
    exit(1);
  }
  for(int i = 0; i<row; i++)
    for(int j=0; j<col; j++)
      readFile>>data(i,j);

  readFile.close();
  return data;
}
