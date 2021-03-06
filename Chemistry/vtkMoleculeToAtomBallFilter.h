/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkMoleculeToAtomBallFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkMoleculeToAtomBallFilter - Generate polydata with spheres
// representing atoms
//
// .SECTION Description
// This filter is used to generate one sphere for each atom in the
// input vtkMolecule. Each sphere is centered at the atom center and
// can be scaled using either covalent or van der Waals radii. The
// point scalars of the output vtkPolyData contains the atomic number
// of the appropriate atom for color mapping.
//
// \note Consider using the faster, simpler vtkMoleculeMapper class,
// rather than generating polydata manually via these filters.
//
// .SECTION See Also
// vtkMoleculeMapper vtkMoleculeToBondStickFilter

#ifndef __vtkMoleculeToAtomBallFilter_h
#define __vtkMoleculeToAtomBallFilter_h

#include "vtkMoleculeToPolyDataFilter.h"

class vtkMolecule;

class VTK_CHEMISTRY_EXPORT vtkMoleculeToAtomBallFilter
: public vtkMoleculeToPolyDataFilter
{
 public:
  vtkTypeMacro(vtkMoleculeToAtomBallFilter,vtkMoleculeToPolyDataFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  static vtkMoleculeToAtomBallFilter *New();

  enum RadiusType {
    CovalentRadius = 0,
    VDWRadius,
    UnitRadius
  }; // TODO Custom radii from array/fieldData

  vtkGetMacro(RadiusSource, RadiusType);
  vtkSetMacro(RadiusSource, RadiusType);

  vtkGetMacro(Resolution, int);
  vtkSetMacro(Resolution, int);

  vtkGetMacro(RadiusScale, double);
  vtkSetMacro(RadiusScale, double);

protected:
  vtkMoleculeToAtomBallFilter();
  ~vtkMoleculeToAtomBallFilter();

  int RequestData(vtkInformation *, vtkInformationVector **,
                  vtkInformationVector *);

  RadiusType RadiusSource;
  int Resolution;
  double RadiusScale;

private:
  vtkMoleculeToAtomBallFilter(const vtkMoleculeToAtomBallFilter&);  // Not implemented.
  void operator=(const vtkMoleculeToAtomBallFilter&);  // Not implemented.
};

#endif
