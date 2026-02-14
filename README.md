# DEVS_KinaseChain_FMI

This repository is an example for model export from [MS4ME tool](https://ms4systems.com/home) and its import in [Cadmium](https://github.com/SimulationEverywhere/cadmium_v2) tool.
<img width="1191" height="596" alt="image" src="https://github.com/user-attachments/assets/a31431d0-14a5-4653-8465-014310a03a8a" />
The GenrFMU directory has Parameter Generator model exported by MS4ME tool and KinaseChain dirctory has model exported by OpenModelica. The implementation for importer for Cadmium is included in the forked verion of cadmium_v2. 
Modelica model in Openmodelica - 
```Modelica
model KinaseChain
Real X1(start = 0) "state variable x1";
Real X2(start = 0) "state variable x2";
Real X3(start = 0) "state variable x3";
Real X4(start = 0) "state variable x4";
Modelica.Blocks.Interfaces.RealInput alpha "input variable alpha";
Modelica.Blocks.Interfaces.RealInput beta "input variable beta";
Modelica.Blocks.Interfaces.RealInput lambda "input variable lambda";
equation
der(X1) = aplha*(exp(-lambda*time)) - beta*X1;
der(X2) = aplha*(X1) - beta*X2;
der(X3) = aplha*(X2) - beta*X3;
der(X4) = aplha*(X3) - beta*X4;
end KinaseChain;
```

For executing the implementation - 

Step 1 : git clone along with the froked Cadmium Version 

git clone --recurse-submodules https://github.com/JoshiRitvik/DEVS_KinaseChain_FMI

Step 2 : download FMI V2 headers from [FMI package 2.0](https://fmi-standard.org/assets/releases/FMI_for_ModelExchange_and_CoSimulation_v2.0.zip)

Step 3 : Extract zip and rename the folder as "FMI_v2.0"

Step 4 : Copy FMI_v2.0 in DEVS_KinaseChain_FMI/cadmium_v2/include/

Step 5 : Go to the top model in DEVS_FMI_code/top_model and run 

make clean; make all

Step 6 : Run model

./DEVS_FMI_Output

The FMI importer in Cadmium is also tested for models exported from other tools like Simulink which support FMIV2.0.
