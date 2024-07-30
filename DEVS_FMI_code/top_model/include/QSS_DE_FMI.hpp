#ifndef _QSS_DE_FMI_HPP_
#define _QSS_DE_FMI_HPP_

#include <cadmium/modeling/devs/coupled.hpp>
// #include <iostream>
// #include <cstdlib>
// #ifdef RT_ARM_MBED
// 	#include <digitalOutput.hpp>
// 	#include <pwmOutput.hpp>
// 	#include <analogInput.hpp>
// 	#include "../mbed.h"
// 	#include "PinNames.h"

// 	#include "generator.hpp" //remove after test
// #else
	
// #endif
#include "Generator.hpp"
#include "Kinases_processor.hpp"
#include "Transducer.hpp"
namespace cadmium::QSS_DE_FMI {

	struct QSS_DE_FMI : public Coupled {

			/**
		 	 * Constructor function for the QSS_robot model.
		 	 * @param id ID of the QSS_robot model.
		 	 */
			QSS_DE_FMI(const std::string& id) : Coupled(id) {
				std::cout << " DEVS_FMI model " << std::endl;
				//auto generator = addComponent<Generator>("generator");
				auto kinase_Processor = addComponent<Kinase_Processor>("kinase_Processor");
				//auto transducer = addComponent<Transducer>("transducer");
				//addCoupling(generator->out, kinase_Processor->in);
				// addCoupling(transducer->terminate, kinase_Processor->in);
			}
	};
}  //namespace cadmium::QSS_robot

#endif //_QSS_DE_FMI_HPP_
