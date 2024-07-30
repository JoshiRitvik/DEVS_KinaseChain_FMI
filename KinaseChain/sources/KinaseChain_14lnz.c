/* Linearization */
#include "KinaseChain_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *KinaseChain_linear_model_frame()
{
  return "model linearized_model \"KinaseChain\"\n"
  "  parameter Integer n = 4 \"number of states\";\n"
  "  parameter Integer m = 3 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_X1' = x[1];\n"
  "  Real 'x_X2' = x[2];\n"
  "  Real 'x_X3' = x[3];\n"
  "  Real 'x_X4' = x[4];\n"
  "  Real 'u_aplha' = u[1];\n"
  "  Real 'u_beta' = u[2];\n"
  "  Real 'u_lambda' = u[3];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *KinaseChain_linear_model_datarecovery_frame()
{
  return "model linearized_model \"KinaseChain\"\n"
  "  parameter Integer n = 4 \"number of states\";\n"
  "  parameter Integer m = 3 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Integer nz = 4 \"data recovery variables\";\n"
  "  parameter Real x0[4] = %s;\n"
  "  parameter Real u0[3] = %s;\n"
  "  parameter Real z0[4] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_X1' = x[1];\n"
  "  Real 'x_X2' = x[2];\n"
  "  Real 'x_X3' = x[3];\n"
  "  Real 'x_X4' = x[4];\n"
  "  Real 'u_aplha' = u[1];\n"
  "  Real 'u_beta' = u[2];\n"
  "  Real 'u_lambda' = u[3];\n"
  "  Real 'z_$cse1' = z[1];\n"
  "  Real 'z_aplha' = z[2];\n"
  "  Real 'z_beta' = z[3];\n"
  "  Real 'z_lambda' = z[4];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

