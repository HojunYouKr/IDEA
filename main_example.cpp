#include <iostream>
#include <string>
#include <vector>

#include "idea.h"

int main(void) {
  // Print the list of units used by IDEA
  const char* unit_info = IDEA_Units();
  std::cout << std::string(unit_info) << std::endl;

  // Initialize IDEA
  const std::string dir = "models/15000K/";
  const std::string errlev = "ALL = 1, PTD=3, DEP = 4";
  const char* initlog = IDEA_Init(dir.c_str(), errlev.c_str());
  std::cout << std::string(initlog) << std::endl;

  // Usage examples of IDEA subroutines
  const double D = 0.1; // density [kg/m3]
  const double E = 1.4E+5; // specific energy [m2/s2]
  const double P = DEP_ANN(D, E); // pressure [Pa]
  std::vector<double> diff(2, 0.0);
  // diff[0] = derivative of pressure with respect to density (dP/dD)
  // diff[1] = derivative of pressure with respect to specific energy (dP/dE)
  DEP_diff_ANN(&diff[0], D, E);

  std::cout << "Density (D) = " << D << " kg/m3" << std::endl;
  std::cout << "Specific energy (E) = " << E << " m2/s2" << std::endl;
  std::cout << "Pressure (P) = " << P << " Pa" << std::endl;
  std::cout << "dP/dD = " << diff[0] << std::endl;
  std::cout << "dP/dE = " << diff[1] << std::endl;

  // Finalize IDEA
  const char* finlog = IDEA_Finalize();
  std::cout << std::string(finlog) << std::endl;

  return 0;
}