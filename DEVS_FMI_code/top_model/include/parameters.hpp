#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>

namespace cadmium::QSS_DE_FMI {

    struct parameter{
        double alpha;
        double beta;
        double lambda;
    };
#ifndef NO_LOGGING 
	std::ostream& operator<<(std::ostream &out, const parameter& parameters) {
		out << " alpha "<< parameters.alpha << " beta "<< parameters.beta << " lambda "<< parameters.lambda <<  " " << "\r \n"; //
		return out;
	}
#endif

}

#endif //PARAMETERS_HPP