/*
==============================================================================
KratosShallowWaterApplication 
A library based on:
Kratos
A General Purpose Software for Multi-Physics Finite Element Analysis
Version 1.0 (Released on march 05, 2007).

Copyright 2007
Pooyan Dadvand, Riccardo Rossi, Janosch Stascheit, Felix Nagel 
pooyan@cimne.upc.edu 
rrossi@cimne.upc.edu
janosch.stascheit@rub.de
nagel@sd.rub.de
- CIMNE (International Center for Numerical Methods in Engineering),
Gran Capita' s/n, 08034 Barcelona, Spain
- Ruhr-University Bochum, Institute for Structural Mechanics, Germany


Permission is hereby granted, free  of charge, to any person obtaining
a  copy  of this  software  and  associated  documentation files  (the
"Software"), to  deal in  the Software without  restriction, including
without limitation  the rights to  use, copy, modify,  merge, publish,
distribute,  sublicense and/or  sell copies  of the  Software,  and to
permit persons to whom the Software  is furnished to do so, subject to
the following condition:

Distribution of this code for  any  commercial purpose  is permissible
ONLY BY DIRECT ARRANGEMENT WITH THE COPYRIGHT OWNERS.

The  above  copyright  notice  and  this permission  notice  shall  be
included in all copies or substantial portions of the Software.

THE  SOFTWARE IS  PROVIDED  "AS  IS", WITHOUT  WARRANTY  OF ANY  KIND,
EXPRESS OR  IMPLIED, INCLUDING  BUT NOT LIMITED  TO THE  WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT  SHALL THE AUTHORS OR COPYRIGHT HOLDERS  BE LIABLE FOR ANY
CLAIM, DAMAGES OR  OTHER LIABILITY, WHETHER IN AN  ACTION OF CONTRACT,
TORT  OR OTHERWISE, ARISING  FROM, OUT  OF OR  IN CONNECTION  WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==============================================================================
*/
 
//   
//   Project Name:        Kratos       
//   Last modified by:    Miguel Masó Sotomayor
//   Date:                May 2017
//   Revision:            1.3
//
//

// System includes 

#if defined(KRATOS_PYTHON)

// External includes 
#include <boost/python.hpp>

// Project includes 
#include "includes/define.h"
#include "shallow_water_application.h"
#include "custom_python/add_custom_strategies_to_python.h"
#include "custom_python/add_custom_utilities_to_python.h"

 
namespace Kratos
{

namespace Python
{

  using namespace boost::python;

  
  BOOST_PYTHON_MODULE(KratosShallowWaterApplication)
  {
    class_<KratosShallowWaterApplication, 
        KratosShallowWaterApplication::Pointer, 
        bases<KratosApplication>, boost::noncopyable >("KratosShallowWaterApplication")
        ;

    AddCustomStrategiesToPython();
    AddCustomUtilitiesToPython();

    // Registering variables in python
    // Shallow water variables
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(HEIGHT);
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BATHYMETRY);
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RAIN);
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FREE_SURFACE_ELEVATION);
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(MANNING);

    // Specific variables for PFEM2
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(MEAN_SIZE);
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DELTA_SCALAR1)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PROJECTED_SCALAR1)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(DELTA_VECTOR1)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(PROJECTED_VECTOR1)

    // Units conversion
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(TIME_UNIT_CONVERTER)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(WATER_HEIGHT_UNIT_CONVERTER)
  }
  
}  // namespace Python.
  
}  // namespace Kratos.

#endif // KRATOS_PYTHON defined