/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "KinaseChain_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int KinaseChain_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[9] /* aplha variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[10] /* beta variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[11] /* lambda variable */) = data->simulationInfo->inputVars[2];
  
  TRACE_POP
  return 0;
}

int KinaseChain_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[9].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[10].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[11].attribute.start;
  
  TRACE_POP
  return 0;
}

int KinaseChain_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[9].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[10].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[11].attribute.start = data->simulationInfo->inputVars[2];
  
  TRACE_POP
  return 0;
}

int KinaseChain_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[9].info.name;
  names[1] = (char *) data->modelData->realVarsData[10].info.name;
  names[2] = (char *) data->modelData->realVarsData[11].info.name;
  
  TRACE_POP
  return 0;
}

int KinaseChain_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int KinaseChain_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KinaseChain_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KinaseChain_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KinaseChain_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KinaseChain_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 9
type: SIMPLE_ASSIGN
$cse1 = exp((-lambda) * time)
*/
void KinaseChain_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[8] /* $cse1 variable */) = exp(((-(data->localData[0]->realVars[11] /* lambda variable */))) * (data->localData[0]->timeValue));
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
$DER.X4 = aplha * X3 - beta * X4
*/
void KinaseChain_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[7] /* der(X4) STATE_DER */) = ((data->localData[0]->realVars[9] /* aplha variable */)) * ((data->localData[0]->realVars[2] /* X3 STATE(1) */)) - (((data->localData[0]->realVars[10] /* beta variable */)) * ((data->localData[0]->realVars[3] /* X4 STATE(1) */)));
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
$DER.X3 = aplha * X2 - beta * X3
*/
void KinaseChain_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[6] /* der(X3) STATE_DER */) = ((data->localData[0]->realVars[9] /* aplha variable */)) * ((data->localData[0]->realVars[1] /* X2 STATE(1) */)) - (((data->localData[0]->realVars[10] /* beta variable */)) * ((data->localData[0]->realVars[2] /* X3 STATE(1) */)));
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
$DER.X2 = aplha * X1 - beta * X2
*/
void KinaseChain_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[5] /* der(X2) STATE_DER */) = ((data->localData[0]->realVars[9] /* aplha variable */)) * ((data->localData[0]->realVars[0] /* X1 STATE(1) */)) - (((data->localData[0]->realVars[10] /* beta variable */)) * ((data->localData[0]->realVars[1] /* X2 STATE(1) */)));
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
$DER.X1 = aplha * $cse1 - beta * X1
*/
void KinaseChain_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[4] /* der(X1) STATE_DER */) = ((data->localData[0]->realVars[9] /* aplha variable */)) * ((data->localData[0]->realVars[8] /* $cse1 variable */)) - (((data->localData[0]->realVars[10] /* beta variable */)) * ((data->localData[0]->realVars[0] /* X1 STATE(1) */)));
  TRACE_POP
}

OMC_DISABLE_OPT
int KinaseChain_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  KinaseChain_functionLocalKnownVars(data, threadData);
  KinaseChain_eqFunction_9(data, threadData);

  KinaseChain_eqFunction_10(data, threadData);

  KinaseChain_eqFunction_11(data, threadData);

  KinaseChain_eqFunction_12(data, threadData);

  KinaseChain_eqFunction_13(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int KinaseChain_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void KinaseChain_eqFunction_9(DATA* data, threadData_t *threadData);
extern void KinaseChain_eqFunction_10(DATA* data, threadData_t *threadData);
extern void KinaseChain_eqFunction_11(DATA* data, threadData_t *threadData);
extern void KinaseChain_eqFunction_12(DATA* data, threadData_t *threadData);
extern void KinaseChain_eqFunction_13(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  {
    KinaseChain_eqFunction_9(data, threadData);
    threadData->lastEquationSolved = 9;
  }
  {
    KinaseChain_eqFunction_10(data, threadData);
    threadData->lastEquationSolved = 10;
  }
  {
    KinaseChain_eqFunction_11(data, threadData);
    threadData->lastEquationSolved = 11;
  }
  {
    KinaseChain_eqFunction_12(data, threadData);
    threadData->lastEquationSolved = 12;
  }
  {
    KinaseChain_eqFunction_13(data, threadData);
    threadData->lastEquationSolved = 13;
  }
}

int KinaseChain_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  KinaseChain_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "KinaseChain_12jac.h"
#include "KinaseChain_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks KinaseChain_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   KinaseChain_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   KinaseChain_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   KinaseChain_initializeDAEmodeData,
   KinaseChain_functionODE,
   KinaseChain_functionAlgebraics,
   KinaseChain_functionDAE,
   KinaseChain_functionLocalKnownVars,
   KinaseChain_input_function,
   KinaseChain_input_function_init,
   KinaseChain_input_function_updateStartValues,
   KinaseChain_data_function,
   KinaseChain_output_function,
   KinaseChain_setc_function,
   KinaseChain_setb_function,
   KinaseChain_function_storeDelayed,
   KinaseChain_function_storeSpatialDistribution,
   KinaseChain_function_initSpatialDistribution,
   KinaseChain_updateBoundVariableAttributes,
   KinaseChain_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   KinaseChain_functionRemovedInitialEquations,
   KinaseChain_updateBoundParameters,
   KinaseChain_checkForAsserts,
   KinaseChain_function_ZeroCrossingsEquations,
   KinaseChain_function_ZeroCrossings,
   KinaseChain_function_updateRelations,
   KinaseChain_zeroCrossingDescription,
   KinaseChain_relationDescription,
   KinaseChain_function_initSample,
   KinaseChain_INDEX_JAC_A,
   KinaseChain_INDEX_JAC_B,
   KinaseChain_INDEX_JAC_C,
   KinaseChain_INDEX_JAC_D,
   KinaseChain_INDEX_JAC_F,
   KinaseChain_INDEX_JAC_H,
   KinaseChain_initialAnalyticJacobianA,
   KinaseChain_initialAnalyticJacobianB,
   KinaseChain_initialAnalyticJacobianC,
   KinaseChain_initialAnalyticJacobianD,
   KinaseChain_initialAnalyticJacobianF,
   KinaseChain_initialAnalyticJacobianH,
   KinaseChain_functionJacA_column,
   KinaseChain_functionJacB_column,
   KinaseChain_functionJacC_column,
   KinaseChain_functionJacD_column,
   KinaseChain_functionJacF_column,
   KinaseChain_functionJacH_column,
   KinaseChain_linear_model_frame,
   KinaseChain_linear_model_datarecovery_frame,
   KinaseChain_mayer,
   KinaseChain_lagrange,
   KinaseChain_pickUpBoundsForInputsInOptimization,
   KinaseChain_setInputData,
   KinaseChain_getTimeGrid,
   KinaseChain_symbolicInlineSystem,
   KinaseChain_function_initSynchronous,
   KinaseChain_function_updateSynchronous,
   KinaseChain_function_equationsSynchronous,
   KinaseChain_inputNames,
   KinaseChain_dataReconciliationInputNames,
   KinaseChain_dataReconciliationUnmeasuredVariables,
   KinaseChain_read_input_fmu,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/intern/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,59,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "KinaseChain"
#define _OMC_LIT_RESOURCE_1_dir_data "/home/intern"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,11,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,12,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "/home/intern/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,60,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "/home/intern/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,68,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void KinaseChain_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &KinaseChain_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "KinaseChain";
  data->modelData->modelFilePrefix = "KinaseChain";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/intern";
  data->modelData->modelGUID = "{35d61dbc-871a-46fc-b014-8652b7a50b9c}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/KinaseChain_info.json", data->modelData->resourcesDir);
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 4;
  data->modelData->nVariablesReal = 12;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 0;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 3;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 14;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

