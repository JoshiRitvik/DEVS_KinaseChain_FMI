#ifndef _FMI_IMPORT_HPP__
#define _FMI_IMPORT_HPP__
#define QUANTUM_SIZE 0.01
#include <cadmium/modeling/devs/atomic.hpp>
#include <iostream>
#include <math.h> 
#include <string>
#include <cadmium/modeling/devs/fmi.hpp>
#include "cadmium/modeling/devs/fmi.hpp"
#include "Quantise_input.hpp"

namespace cadmium::QSS_DE_FMI {
		
	//! Atomic DEVS model of Quantize_input.
	class FMI_IMPORT : public FMI <Quantise_input_State> {
	 private:
		
	 public: 
		/**
		 * Constructor function.
		 * @param id ID of the new Quantize_input model object.
		 */
		FMI_IMPORT(const std::string& id): //const std::string& id
		FMI<Quantise_input_State>(
			id,
			Quantise_input_State(),
			"test_for_QSS",
			"{e8c82697-a56c-468a-a47b-c5cd2cb0cdde}",
			1,
			0,
			"include/binaries/linux64/test_for_QSS.so"
		) 		
		{
			std::cout << " init "<< std::endl;
			initialize(state);			
		}

		double get_variable_val(int variable_no) const
		{
			return get_real(variable_no);
		}
		void set_variable_val(int variable_no, double value) 
		{
			set_real(variable_no,value);
		}


	};
}  //namespace cadmium::blinkySystem

#endif //_FMI_IMPORT_HPP__
