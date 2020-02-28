#ifndef SYSTEM_MANAGER_H
#define SYSTEM MANAGER_H

#include <vector>

#include "Parameters.h"
#include "Particle.h"
#include "Properties.h"

// it may be better to move the 'main loop' for this into the simulation class.
// The observer class can then organize the data (i.e. the total energy config
// of the system, the current RDF/PCF, handle updating the forces for each
// particle, etc.

class System_Manager {
  private:
    // maybe keep private objects here
    // current total force (2 by 1 vector)
    Properties prop;
    Parameters param;

    // this is to track the virial calculation throughout the sim
    double f_r = 0;
    double f_energy = 0;
    // just moved over from the properties class

    // these are values used for initializing the rdf & pcf vectors
    double delta_r = 0;
    double cell_L = 0;

    std::vector<double> sum_energy;
    std::vector<double> sum_virial; // in prop I had this as sum_Fdot_r

    // arrays used for calculating the RDF
    std::vector<double> num_density;
    std::vector<double> par_num_density;
    std::vector<double> antp_num_density;

    // 2D arrays used for calculating the PCFs
    std::vector<std::vector<double>> xy_num_density;
    std::vector<std::vector<double>> par_xy_density;
    std::vector<std::vector<double>> antp_xy_density;

  public:
    // constructors
    System_Manager();
    System_Manager(std::string yaml_file);

    void updateNumDensity(double r, int ID);
    void calc_xy_dens(double x, double y, int ID);

    void updateVirial(double v);
    void setTotalVirial();
    void resetVirial();

    void updateEnergy(double v);
    void setTotalEnergy();
    void resetEnergy();

    std::vector<double> *getTotalEnergy();
    std::vector<double> *getTotalVirial();

    std::vector<double> *getTotalNumDensity();
    std::vector<double> *getParNumDensity();
    std::vector<double> *getAntiNumDensity();

    std::vector<std::vector<double>> *getTotalXYDensity();
    std::vector<std::vector<double>> *getParXYDensity();
    std::vector<std::vector<double>> *getAntiXYDensity();
};
#endif