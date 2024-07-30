#ifndef _KINASES_PROCESSOR_HPP__
#define _KINASES_PROCESSOR_HPP__
#define QUANTUM_SIZE_PROCESSOR 0.01
#define HYSTERESIS_PROCESSOR 0.01
#define HYSTERESIS_PROCESSOR_ENABLE 0
#include <cadmium/modeling/devs/atomic.hpp>
#include <iostream>
#include <math.h> 
#include <string>
#include <cfloat>
#include <cadmium/modeling/devs/fmi.hpp>
#include "cadmium/modeling/devs/fmi.hpp"
#include "parameters.hpp"
namespace cadmium::QSS_DE_FMI {
	//! Class for representing the Blinky DEVS model state.struct Generator_Processor_State {
		
	struct Kinase_Processor_State {
		double sigma;
		double x1_value;
		double x2_value;
		double x3_value;
		double x4_value;
		double CurrentTime;
		double continuous_state_time;
		eFMI_mode FMI_mode;
		parameter input;
		double next_event_time;
		int output_val; 
		bool input_ack;
		double test_input_val;
		double x1_derivative_val;
		double x2_derivative_val;
		double x3_derivative_val;
		double x4_derivative_val;
		double test_state_variable;
		int stop_input;
		//! Blinky state constructor.
		Kinase_Processor_State(): sigma(0.01),CurrentTime(0), continuous_state_time(0), x1_value(0),x2_value(0), x3_value(0),x4_value(0),x1_derivative_val(0),x2_derivative_val(0),x3_derivative_val(0),x4_derivative_val(0), input_ack(true) {}
	}; //std::numeric_limits<double>::infinity()
	/**
	 * Insertion operator for Generator_Processor_State objects. It displays the value of sigma and lightOn.
	 * @param out output stream.
	 * @param s state to be represented in the output stream.
	 * 
	 * @return output stream with sigma and lightOn already inserted.
	 */
#ifndef NO_LOGGING 
	std::ostream& operator<<(std::ostream &out, const Kinase_Processor_State& state) {
		out << " Sigma "<< state.sigma << " x1_value "<< state.x1_value << " x2_value "<< state.x2_value << " x3_value "<< state.x3_value << " x4_value "<< state.x4_value << " x1_derivative_val "<< state.x1_derivative_val  <<" x2_derivative_val "<< state.x2_derivative_val  << " Current Time " << state.CurrentTime<< " " << "\r \n"; //
		return out;
	}
#endif


	class FMI_IMPORT_processor : public FMI <Kinase_Processor_State> {
	 private:
		
	 public:  
		/**
		 * Constructor function.
		 * @param id ID of the new Generator_Processor model object.
		 */
		FMI_IMPORT_processor(const std::string& id):
		FMI<Kinase_Processor_State>(
			id,
			Kinase_Processor_State(),
			"KinaseChain",
			"{35d61dbc-871a-46fc-b014-8652b7a50b9c}", //04
			"file:///home/intern/Documents/QSS_DE_FMI_Kinase_chain/KinaseChain/resources",  //file:///home/rotten/Code/fmu4-devs-java/devs-fmu/GenrFMU/resources
			"../../KinaseChain/binaries/linux64/KinaseChain.so"
		) 		
		{
			std::cout << " init "<< std::endl;
			initialize(state);			
		}
	};
	//! Atomic DEVS model of Generator_Processor.
	class Kinase_Processor : public FMI_IMPORT_processor { //FMI <Generator_Processor_State>
	 private:
		
	 public:
		Port<int> out;  
		Port<parameter> in;  
		/**
		 * Constructor function.
		 * @param id ID of the new Generator_Processor model object.
		 */
		Kinase_Processor(const std::string& id): //const std::string& id
		 	FMI_IMPORT_processor(id)		

		{
		 	out = addOutPort<int>("out");
		 	in  = addInPort<parameter>("in");		
		}
		
		/**
		 * It updates the Generator_Processor_State::lightOn.
		 * @param state reference to the current state of the model.
		 */
		void internalTransition(Kinase_Processor_State& state) const override { //
			double sigma[4];
			double* sigmaptr;
			//state.sigma = FMI_IMPORT::get_real(0); //state
			// if (state.sigma == DBL_MAX)
			// {
			// 	return;
			// }
			FMI_IMPORT_processor::set_real(9,1);
			FMI_IMPORT_processor::set_real(10,0.5);
			FMI_IMPORT_processor::set_real(11,1);
			if(state.input_ack == 1)
			{
				FMI_IMPORT_processor::do_step(state.CurrentTime,state.sigma); //state
				state.x1_value = FMI_IMPORT_processor::get_real(0);
				state.x2_value = FMI_IMPORT_processor::get_real(1);
				state.x3_value = FMI_IMPORT_processor::get_real(2);
				state.x4_value = FMI_IMPORT_processor::get_real(3);
				state.x1_derivative_val = FMI_IMPORT_processor::get_real(4);
				state.x2_derivative_val = FMI_IMPORT_processor::get_real(5);
				state.x3_derivative_val = FMI_IMPORT_processor::get_real(6);
				state.x4_derivative_val = FMI_IMPORT_processor::get_real(7);
				sigma[0] = Quantise_data(state,state.x1_derivative_val);
				sigma[1] = Quantise_data(state,state.x2_derivative_val);
				sigma[2] = Quantise_data(state,state.x3_derivative_val);
				sigma[3] = Quantise_data(state,state.x4_derivative_val);
				sigmaptr = std::min_element(sigma,sigma+4);
				std::cout << state.x1_value << state.x2_value << std::endl;
				// if(*sigmaptr > 0)
				state.sigma = *sigmaptr;
				if(state.sigma != std::numeric_limits<double>::infinity())
					{state.CurrentTime += state.sigma; }
			}
			if(state.CurrentTime >= 10.0)
			{
				//FMI_IMPORT::set_bool(0,true);
			}

			std::cout << " Sigma "<< state.sigma << " x1_value "<< state.x1_value << " x2_value "<< state.x2_value << " x3_value "<< state.x3_value << " x4_value "<< state.x4_value <<  " x1_derivative_val "<< state.x1_derivative_val  <<" x2_derivative_val "<< state.x2_derivative_val  << " Current Time " << state.CurrentTime<<   std::endl;   
		}

		void QSS1_with_HYS(Kinase_Processor_State& state) const
		{
			static double last_p_der_val=0,last_n_der_val=0;
			
			//state.x1_value = state.x1_value + state.sigma*state.x1_derivative_val;

			if ((state.x1_derivative_val > 0) && ((last_n_der_val==0)||(last_n_der_val>=QUANTUM_SIZE_PROCESSOR+HYSTERESIS_PROCESSOR)))
			{
				state.sigma = (QUANTUM_SIZE_PROCESSOR)/state.x1_derivative_val; //state.voltage_Vc +  add after external trasition 
				last_p_der_val = state.x1_value;
			}
			else if ((state.x1_derivative_val < 0) && ((last_p_der_val==0)||(last_p_der_val>=QUANTUM_SIZE_PROCESSOR+HYSTERESIS_PROCESSOR)))
			{
				state.sigma = (QUANTUM_SIZE_PROCESSOR)/abs(state.x1_derivative_val); //state.voltage_Vc -  add after external trasition 
				last_n_der_val =  state.x1_value;
			}
			else
			{
				// std::cout << " SIGMA INFINITE " << std::endl;
				// state.sigma = std::numeric_limits<double>::infinity(); // 5;//
				// state.switch_state = 0;
			}
		}
		double Quantise_data(Kinase_Processor_State& state,double derivative_val) const
		{			
			//state.x1_value = state.x1_value + state.sigma*state.x1_derivative_val;
			double sigma = 0.0;
			//QSS1
			if (derivative_val > 0)
			{
				sigma = (QUANTUM_SIZE_PROCESSOR)/derivative_val; //state.voltage_Vc +  add after external trasition 
			}
			else if (derivative_val < 0)
			{
				sigma = (QUANTUM_SIZE_PROCESSOR)/abs(derivative_val); //state.voltage_Vc -  add after external trasition 
			}
			else
			{
				// std::cout << " SIGMA INFINITE " << std::endl;
				// state.sigma = std::numeric_limits<double>::infinity(); // 5;//
				// state.switch_state = 0;
			}
			if(sigma > 0)
				return sigma;
			else
				return std::numeric_limits<double>::infinity();

		}
		/**
		 * Updates Generator_Processor_State::fastToggle and Generator_Processor_State::sigma.
		 * @param state reference to the current model state.
		 * @param e time elapsed since the last state transition function was triggered.
		 * @param x reference to the model input port set.
		 */
		void externalTransition(Kinase_Processor_State& state, double e) const override {
			//FMI_IMPORT::externalTransition(state,e);

			
			std::cout << " External Trasnsition "<< std::endl;
			if(!in->empty()){
				for( const auto x : in->getBag()){
					{
						if((x.alpha != 0.0) && (x.beta != 0.0) && (x.lambda != 0.0))
						{
						state.input.alpha = x.alpha;
						state.input.beta = x.beta;
						state.input.lambda = x.lambda;
						FMI_IMPORT_processor::set_real(9,state.input.alpha); //
						FMI_IMPORT_processor::set_real(10,state.input.beta); //
						FMI_IMPORT_processor::set_real(11,state.input.lambda); //
						std::cout << " Processor input external (alpha) "<< state.input.alpha << " " << state.input.beta  << state.sigma << std::endl;
						state.input_ack = true;
						if(state.sigma >= std::numeric_limits<double>::infinity()) //1000
						{
							state.sigma = 0.01;
						}
						else
						{
							state.sigma = state.sigma - e;
						}
						}
					}					
				}
			}

			std::cout << " Sigma "<< state.sigma << std::endl;

		}

		/**
		 * It outputs the already processed Generator_Processor_State::lightOn via the out port.
		 * @param state reference to the current model state.
		 * @param y reference to the atomic model output port set.
		 */
		void output(const Kinase_Processor_State& state) const override {
//			if(state.event_flag == 1)
			{

				out->addMessage(state.x1_value);
				std::cout << " Cadmium Generator_Processor Output "<< state.output_val << std::endl;
				
			} 
			
				
		}

		void confluentTransition(const Kinase_Processor_State& state, double e)
		{

		}
		/**
		 * It returns the value of Generator_Processor_State::sigma.
		 * @param state reference to the current model state.
		 * @return the sigma value.
		 */
		[[nodiscard]] double timeAdvance(const Kinase_Processor_State& state) const override {
			return state.sigma;
		}
	};
}  //namespace cadmium::blinkySystem

#endif //_KINASES_PROCESSOR_HPP__


		// double get_variable_val(int variable_no) 
		// {
		// 	return get_real(variable_no);
		// }
		// void set_variable_val(int variable_no, double value) 
		// {
		// 	set_real(variable_no,value);
		// }

