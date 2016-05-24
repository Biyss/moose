/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef DISLOCATIONVARIABLEEIGENSTRAIN_H
#define DISLOCATIONARIABLEEIGENSTRAIN_H

#include "DislocationEigenstrain.h"
#include "DerivativeMaterialInterface.h"

/**
 * DislocationVariableEigenstrain computes an Eigenstrain that is a function of a single
 * variable defined by a base tensor and a scalar function defined in a Derivative Material.
 */
class DislocationVariableEigenstrain : public DerivativeMaterialInterface<DislocationEigenstrain>
{
public:
  DislocationVariableEigenstrain(const InputParameters & parameters);

protected:
  virtual void computeQpStressFreeStrain();

  /// number of variables the prefactor depends on
  const unsigned int _num_args;

  /// first derivatives of the prefactor w.r.t. to the args
  std::vector<const MaterialProperty<Real> *> _dprefactor;
  /// second derivatives of the prefactor w.r.t. to the args
  std::vector<std::vector<const MaterialProperty<Real> *> > _d2prefactor;

  /// first derivatives of the elastic strain w.r.t. to the args
  std::vector<MaterialProperty<RankTwoTensor> *> _delastic_strain;
  /// second derivatives of the elastic strain w.r.t. to the args
  std::vector<std::vector<MaterialProperty<RankTwoTensor> *> > _d2elastic_strain;
};

#endif //DISLOCATIONVARIABLEEIGENSTRAIN_H
