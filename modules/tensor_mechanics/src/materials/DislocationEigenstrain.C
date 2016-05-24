/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "DislocationEigenstrain.h"

template<>
InputParameters validParams<DislocationEigenstrain>()
{
  InputParameters params = validParams<ComputeStressFreeStrainBase>();
  params.addClassDescription("Computes a constant Eigenstrain based on Burger's vector and slip plane normal of a dislocation");
  params.addRequiredParam<RealVectorValue>("Burger_vector", "Burger's vector of the dislocation");
  params.addRequiredParam<RealVectorValue>("plane_normal", "Normal vector of slip plane");
  params.addParam<MaterialPropertyName>("prefactor", 1.0, "Name of material defining the variable dependence");
  return params;
}

DislocationEigenstrain::DislocationEigenstrain(const InputParameters & parameters) :
    ComputeStressFreeStrainBase(parameters),
    _prefactor(getMaterialProperty<Real>("prefactor")),
    _burger_vector(getParam<RealVectorValue>("Burger_vector")),
    _plane_normal(getParam<RealVectorValue>("plane_normal"))
{
  _eigen_base_tensor.vectorOuterProduct(_burger_vector, _plane_normal);
}

void
DislocationEigenstrain::computeQpStressFreeStrain()
{
  // Define Eigenstrain
  _stress_free_strain[_qp] = _eigen_base_tensor * _prefactor[_qp];
}
