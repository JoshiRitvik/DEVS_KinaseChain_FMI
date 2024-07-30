#ifndef _TRANSDUCER_HPP__
#define _TRANSDUCER_HPP__

#define ODD 1
#define EVEN 0

#include <cadmium/modeling/devs/atomic.hpp>
#include <iostream>
namespace cadmium::QSS_DE_FMI {
	//! Class for representing the SpeedControl DEVS model state.struct SpeedControlState {
	struct TransducerState {
		double sigma;
		int cycles;
		int InputData;
		bool out;
		int StopMsg;
		//! SpeedControl state constructor.
		TransducerState(): sigma(0), cycles(0), InputData(0), out(0), StopMsg(0){}
	};
	/**
	 * Insertion operator for speedControlState objects. It displays the value of sigma and lightOn.
	 * @param out output stream.
	 * @param s state to be represented in the output stream.
	 * @return output stream with sigma and lightOn already inserted.
	 */
#ifndef NO_LOGGING 
	std::ostream& operator<<(std::ostream &out, const TransducerState& state) {
		out << "Trasnducer output:, " << state.out << "\r \n";
		return out;
	}
#endif
	//! Atomic DEVS model of SpeedControl.
	class Transducer : public Atomic<TransducerState> {
	 private:
		
	 public:
		Port<bool> out;  
		Port<int> input;  
		Port<int> terminate;

		/**
		 * Constructor function.
		 * @param id ID of the new SpeedControl model object.
		 */
		Transducer(const std::string& id): Atomic<TransducerState>(id, TransducerState()) {
			out = addOutPort<bool>("out");
			input  = addInPort<int>("input");
			terminate = addOutPort<int>("terminate");
			state.sigma = 1;
		}

		/**
		 * It updates the SpeedControlState::lightOn.
		 * @param state reference to the current state of the model.
		 */
		void internalTransition(TransducerState& state) const override {
			if(state.InputData%2)
			{
				state.out = ODD;
			}
			else
			{
				state.out = EVEN;
			}
			if(state.InputData == 10)
			{
				state.StopMsg = 1;
				state.sigma = std::numeric_limits<double>::infinity();
			}
			//state.sigma = std::numeric_limits<double>::infinity();
		}

		/**
		 * Updates speedControlState::fastToggle and speedControlState::sigma.
		 * @param state reference to the current model state.
		 * @param e time elapsed since the last state transition function was triggered.
		 * @param x reference to the model input port set.
		 */
		void externalTransition(TransducerState& state, double e) const override {
			//state.sigma = state.sigma - e;
			if(!input->empty()){
				
				for( const auto x : input->getBag()){
					state.InputData = input->getBag().back(); 
				}
				//std::cout << " Quantise disyance "<< state.InputData.Quantised_distance << std::endl;
			}
			state.sigma = 1;
		}

		/**
		 * It outputs the already processed speedControlState::lightOn via the out port.
		 * @param state reference to the current model state.
		 * @param y reference to the atomic model output port set.
		 */
		void output(const TransducerState& state) const override {
			std::cout << " Transducer Output " << state.out << std::endl;
			out->addMessage(state.out);	
			if(state.StopMsg != 0)
			{
				terminate->addMessage(state.StopMsg);
			}
		}

		/**
		 * It returns the value of speedControlState::sigma.
		 * @param state reference to the current model state.
		 * @return the sigma value.
		 */
		[[nodiscard]] double timeAdvance(const TransducerState& state) const override {
			return state.sigma;
		}
	};
}  //namespace cadmium::SpeedControlSystem

#endif //_TRANSDUCER_HPP__
