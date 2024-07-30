embedded:
	mbed compile --target NUCLEO_F411RE --toolchain GCC_ARM --profile ../cadmium.json --flash --sterm

clean-embedded:
	rm -rf ../BUILD/

all: main.o
	g++ -g -o DEVS_FMI_Output main.o -ldl

main.o: main_rt_model.cpp include/
	g++ -g -c -std=c++17 -I ../../cadmium_v2/include -I include main_rt_model.cpp -o main.o

clean:
	rm -f *.o
	rm -f *.csv
	rm -f DEVS_FMI_Output
