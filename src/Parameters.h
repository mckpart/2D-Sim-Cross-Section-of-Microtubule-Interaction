#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <yaml-cpp/yaml.h>

class Parameters{

	private:

		int n_updates = 0; 
		int n_particles = 0; 
		long seed = 0; 

		double weight = 0; 

		bool rigidBC = 0; 
		bool periodicBC = 0; 
		bool extWell = 0; 

		bool hardDisk = 0;  
		bool lenJones = 0;  	
		bool WCA = 0; 

	public: 
		
		void initializeParameters(std::string yamlFile); // may need to add a default constructor

		int getUpdates(); 	
		int getNumParticles(); 
		long getSeed(); 

		double getWeight(); 

		bool getRigidBC(); 
		bool getPeriodicBC(); 
		bool getExtWell(); 

		bool getHardDisk(); 
		bool getLenJones(); 
		bool getWCA(); 

		// NOTE: THE SETTERS ARE NOT NECESSARY
		// GIVEN THAT THESE PARAMETERS ARE CONSTANT
		// THROUGHOUT THE SIMULATION

}; 
#endif 