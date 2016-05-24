/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef DISLOCATIONEIGENSTRAIN_H
#define DISLOCATIONEIGENSTRAIN_H

#include "ComputeStressFreeStrainBase.h"

/**
 * DislocationEigenstrain computes an Eigenstrain that is caused by the misfit of a dislocation loop.
 */
class DislocationEigenstrain : public ComputeStressFreeStrainBase
{
public:
  DislocationEigenstrain(const InputParameters & parameters);

protected:
  virtual void computeQpStressFreeStrain();

  const MaterialProperty<Real> & _prefactor;

  RankTwoTensor _eigen_base_tensor;

private:
  RealVectorValue _burger_vector;
  RealVectorValue _plane_normal;
};

#endif //DISLOCATIONEIGENSTRAIN_H
