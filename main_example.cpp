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
  double P = 0.0; // pressure [Pa]
  // grad[0] = derivative of pressure with respect to density (dP/dD)
  // grad[1] = derivative of pressure with respect to specific energy (dP/dE)
  std::vector<double> grad(2, 0.0);
  // hess[0] = second derivative of pressure (d**2P/dD**2)
  // hess[1] = mixed second derivative of pressure (d**2P/dDdE)
  // hess[2] = second derivative of pressure (d**2P/dE**2)
  std::vector<double> hess(3, 0.0);
  std::cout << "Density (D) = " << D << " kg/m3" << std::endl;
  std::cout << "Specific energy (E) = " << E << " m2/s2" << std::endl;

  // input: D, E
  // output: P
  P = IDEA_DEP(D, E);
  std::cout << std::endl << "Example 1. IDEA_DEP" << std::endl;
  std::cout << "Pressure (P) = " << P << " Pa" << std::endl;

  // input: D, E
  // output: P, grad
  P = IDEA_DEP_Grad(&grad[0], D, E);
  std::cout << std::endl << "Example 2. IDEA_DEP_Grad" << std::endl;
  std::cout << "Pressure (P) = " << P << " Pa" << std::endl;
  std::cout << "dP/dD = " << grad[0] << std::endl;
  std::cout << "dP/dE = " << grad[1] << std::endl;

  // input: D, E
  // output: P, grad, hess
  P = IDEA_DEP_Hess(&hess[0], &grad[0], D, E);
  std::cout << std::endl << "Example 3. IDEA_DEP_Hess" << std::endl;
  std::cout << "Pressure (P) = " << P << " Pa" << std::endl;
  std::cout << "dP/dD = " << grad[0] << std::endl;
  std::cout << "dP/dE = " << grad[1] << std::endl;
  std::cout << "d**2P/dD**2 = " << hess[0] << std::endl;
  std::cout << "d**2P/dDdE  = " << hess[1] << std::endl;
  std::cout << "d**2P/dE**2 = " << hess[2] << std::endl;

  // Finalize IDEA
  const char* finlog = IDEA_Finalize();
  std::cout << std::string(finlog) << std::endl;

  return 0;
}