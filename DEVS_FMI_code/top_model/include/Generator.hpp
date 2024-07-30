#ifndef _GENERATOR_HPP__
#define _GENERATOR_HPP__
#include <cadmium/modeling/devs/atomic.hpp>
#include <iostream>
#include <math.h> 
#include <string>
#include <cfloat>
#include <cadmium/modeling/devs/fmi.hpp>
#include "cadmium/modeling/devs/fmi.hpp"
#include "parameters.hpp"
//#include "FMI_importer.hpp"
namespace cadmium::QSS_DE_FMI {
	//! Class for representing the Blinky DEVS model state.struct Generator_State {
		
	struct Generator_State {
		double sigma;
		double alpha;
		double beta; 
		double lambda;
		double CurrentTime;
		double continuous_state_time;
		eFMI_mode FMI_mode;
		parameter output;
		double next_event_time;
		double test_input_val;
		double test_derivative_val;
		double test_state_variable;
		int stop_input;
		//! Blinky state constructor.
		Generator_State(): sigma(0),CurrentTime(0), continuous_state_time(0), alpha(0), beta(0),lambda(0), stop_input(0) {}
	};
	/**
	 * Insertion operator for Generator_State objects. It displays the value of sigma and lightOn.
	 * @param out output stream.
	 * @param s state to be represented in the output stream.
	 * @return output stream with sigma and lightOn already inserted.
	 */
#ifndef NO_LOGGING 
	std::ostream& operator<<(std::ostream &out, const Generator_State& state) {
		out << " Sigma "<< state.sigma << " alpha "<< state.alpha << " Output value " << state.beta <<  " test_input_val " << state.lambda <<  "\r \n"; //
		return out;
	}
#endif


	class FMI_IMPORT : public FMI <Generator_State> {
	 private:
		
	 public:  
		/**
		 * Constructor function.
		 * @param id ID of the new Generator model object.
		 */
		FMI_IMPORT(const std::string& id):
		FMI<Generator_State>(
			id,
			Generator_State(),
			"GenrFMU",
			"{864b7d79-d454-4d85-b5f8-757f21eab7f7}", //04
			"file:///home/intern/Documents/QSS_DE_FMI_Kinase_chain/GenrFMU/resources",  //file:///home/rotten/Code/fmu4-devs-java/devs-fmu/GenrFMU/resources
			"../../GenrFMU/binaries/linux64/GenrFMU.so"
		) 		
		{
			std::cout << " init "<< std::endl;
			initialize(state);			
		}
	};
	//! Atomic DEVS model of Generator.
	class Generator : public FMI_IMPORT { //FMI <Generator_State>
	 private:
		
	 public:
		Port<parameter> out;  
		Port<int> in;  
		/**
		 * Constructor function.
		 * @param id ID of the new Generator model object.
		 */
		Generator(const std::string& id): //const std::string& id
		 	FMI_IMPORT(id)		

		{
		 	out = addOutPort<parameter>("out");
		 	in  = addInPort<int>("in");		
		}
		
		/**
		 * It updates the Generator_State::lightOn.
		 * @param state reference to the current state of the model.
		 */
		void internalTransition(Generator_State& state) const override { //
			state.sigma = FMI_IMPORT::get_real(0); //state
			if (state.sigma == DBL_MAX)
			{
				return;
			}

			// state.x_value = FMI_IMPORT::get_real(0);
			state.output.alpha = FMI_IMPORT::get_real(1);
			state.output.beta = FMI_IMPORT::get_real(2);
			state.output.lambda = FMI_IMPORT::get_real(3);
			FMI_IMPORT::do_step(state.CurrentTime,state.sigma); //state
			state.CurrentTime += state.sigma; 

			if(state.CurrentTime >= 10.0)
			{
				//FMI_IMPORT::set_bool(0,true);
			}
			
			// state.continuous_state_time = state.continuous_state_time + state.sigma;
			std::cout << " Sigma "<< state.sigma << " alpha " << state.output.alpha << " beta " << state.output.beta <<  " lambda " << state.output.lambda  <<   std::endl;   //" Output value" << state.output_val<<  " test_input_val " << state.test_input_val <<  " test_derivative_val " << state.test_derivative_val  << " " << "test_state_variable" << state.test_state_variable << " " <<state.next_event_time <<
		}

		/**
		 * Updates Generator_State::fastToggle and Generator_State::sigma.
		 * @param state reference to the current model state.
		 * @param e time elapsed since the last state transition function was triggered.
		 * @param x reference to the model input port set.
		 */
		void externalTransition(Generator_State& state, double e) const override {
			//FMI_IMPORT::externalTransition(state,e);
			if(state.sigma == std::numeric_limits<double>::infinity())
			{
				state.sigma = 0.01;
			}
			else
			{
				state.sigma = state.sigma - e;
			}
			
			std::cout << " External Trasnsition "<< std::endl;
			if(!in->empty()){
				for( const auto x : in->getBag()){
					if (x==1)
					{
						state.stop_input = x; 
						FMI_IMPORT::set_int(1,state.stop_input);
						state.sigma = std::numeric_limits<double>::infinity();
					}					
				}
			}

			

		}

		/**
		 * It outputs the already processed Generator_State::lightOn via the out port.
		 * @param state reference to the current model state.
		 * @param y reference to the atomic model output port set.
		 */
		void output(const Generator_State& state) const override {
//			if(state.event_flag == 1)
			{

				out->addMessage(state.output);
				std::cout << " Cadmium Generator Output "<< state.output.alpha << std::endl;
				
			} 
			
				
		}

		void confluentTransition(const Generator_State& state, double e)
		{

		}
		/**
		 * It returns the value of Generator_State::sigma.
		 * @param state reference to the current model state.
		 * @return the sigma value.
		 */
		[[nodiscard]] double timeAdvance(const Generator_State& state) const override {
			return state.sigma;
		}
	};
}  //namespace cadmium::blinkySystem

#endif //_GENERATOR_HPP__


		// double get_variable_val(int variable_no) 
		// {
		// 	return get_real(variable_no);
		// }
		// void set_variable_val(int variable_no, double value) 
		// {
		// 	set_real(variable_no,value);
		// }

