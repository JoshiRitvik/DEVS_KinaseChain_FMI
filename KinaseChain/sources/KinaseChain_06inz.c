/* Initialization */
#include "KinaseChain_model.h"
#include "KinaseChain_11mix.h"
#include "KinaseChain_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void KinaseChain_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
X1 = $START.X1
*/
void KinaseChain_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[0] /* X1 STATE(1) */) = (data->modelData->realVarsData[0] /* X1 STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
$DER.X1 = aplha * exp((-lambda) * time) - beta * X1
*/
void KinaseChain_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[4] /* der(X1) STATE_DER */) = ((data->localData[0]->realVars[9] /* aplha variable */)) * (exp(((-(data->localData[0]->realVars[11] /* lambda variable */))) * (data->localData[0]->timeValue))) - (((data->localData[0]->realVars[10] /* beta variable */)) * ((data->localData[0]->realVars[0] /* X1 STATE(1) */)));
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
X2 = $START.X2
*/
void KinaseChain_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[1] /* X2 STATE(1) */) = (data->modelData->realVarsData[1] /* X2 STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KinaseChain_eqFunction_12(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
X3 = $START.X3
*/
void KinaseChain_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[2] /* X3 STATE(1) */) = (data->modelData->realVarsData[2] /* X3 STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KinaseChain_eqFunction_11(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
X4 = $START.X4
*/
void KinaseChain_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[3] /* X4 STATE(1) */) = (data->modelData->realVarsData[3] /* X4 STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KinaseChain_eqFunction_10(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void KinaseChain_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  KinaseChain_eqFunction_1(data, threadData);
  KinaseChain_eqFunction_2(data, threadData);
  KinaseChain_eqFunction_3(data, threadData);
  KinaseChain_eqFunction_12(data, threadData);
  KinaseChain_eqFunction_5(data, threadData);
  KinaseChain_eqFunction_11(data, threadData);
  KinaseChain_eqFunction_7(data, threadData);
  KinaseChain_eqFunction_10(data, threadData);
  TRACE_POP
}

int KinaseChain_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  KinaseChain_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No KinaseChain_functionInitialEquations_lambda0 function */

int KinaseChain_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

