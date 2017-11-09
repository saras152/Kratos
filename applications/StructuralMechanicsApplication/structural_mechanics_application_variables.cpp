// KRATOS  ___|  |                   |                   |
//       \___ \  __|  __| |   |  __| __| |   |  __| _` | |
//             | |   |    |   | (    |   |   | |   (   | |
//       _____/ \__|_|   \__,_|\___|\__|\__,_|_|  \__,_|_| MECHANICS
//
//  License:		 BSD License
//					 license: structural_mechanics_application/license.txt
//
//  Main authors:    Riccardo Rossi
//
#include "structural_mechanics_application_variables.h"

namespace Kratos
{
typedef array_1d<double, 3> Vector3;

// Generalized eigenvalue problem
KRATOS_CREATE_VARIABLE(int, BUILD_LEVEL)
KRATOS_CREATE_VARIABLE(Vector, EIGENVALUE_VECTOR)
KRATOS_CREATE_VARIABLE(Matrix, EIGENVECTOR_MATRIX)

// Geometrical
KRATOS_CREATE_VARIABLE(double, AREA)
KRATOS_CREATE_VARIABLE(double, IT)
KRATOS_CREATE_VARIABLE(double, IY)
KRATOS_CREATE_VARIABLE(double, IZ)
KRATOS_CREATE_VARIABLE(double, CROSS_AREA)
KRATOS_CREATE_VARIABLE(double, MEAN_RADIUS)
KRATOS_CREATE_VARIABLE(int, SECTION_SIDES)
KRATOS_CREATE_VARIABLE(Matrix, GEOMETRIC_STIFFNESS)
KRATOS_CREATE_VARIABLE(Vector, LOCAL_AXIS_VECTOR_1)
KRATOS_CREATE_VARIABLE(Matrix, LOCAL_ELEMENT_ORIENTATION)
KRATOS_CREATE_VARIABLE(double, ORTHOTROPIC_ORIENTATION_ASSIGNMENT)
KRATOS_CREATE_VARIABLE(Vector, ORTHOTROPIC_FIBER_ORIENTATION_1)

// Truss generalized variables
KRATOS_CREATE_VARIABLE(double, TRUSS_PRESTRESS_PK2)
KRATOS_CREATE_VARIABLE(bool, TRUSS_IS_CABLE)

// Beam generalized variables
KRATOS_CREATE_VARIABLE(double, AREA_EFFECTIVE_Y)
KRATOS_CREATE_VARIABLE(double, AREA_EFFECTIVE_Z)
KRATOS_CREATE_VARIABLE(double, INERTIA_ROT_Y)
KRATOS_CREATE_VARIABLE(double, INERTIA_ROT_Z)
KRATOS_CREATE_VARIABLE(Vector, LOCAL_AXES_VECTOR)
KRATOS_CREATE_VARIABLE(double, TORSIONAL_INERTIA)
KRATOS_CREATE_VARIABLE(double, I22)
KRATOS_CREATE_VARIABLE(double, I33)
KRATOS_CREATE_VARIABLE(bool, LUMPED_MASS_MATRIX)

// Shell generalized variables
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRAIN)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRAIN_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_CURVATURE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_CURVATURE_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_FORCE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_FORCE_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_MOMENT)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_MOMENT_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRESS_TOP_SURFACE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRESS_TOP_SURFACE_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRESS_MIDDLE_SURFACE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRESS_MIDDLE_SURFACE_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRESS_BOTTOM_SURFACE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_STRESS_BOTTOM_SURFACE_GLOBAL)
KRATOS_CREATE_VARIABLE(double, VON_MISES_STRESS_TOP_SURFACE)
KRATOS_CREATE_VARIABLE(double, VON_MISES_STRESS_MIDDLE_SURFACE)
KRATOS_CREATE_VARIABLE(double, VON_MISES_STRESS_BOTTOM_SURFACE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_STRESS_BOTTOM_SURFACE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_STRESS_TOP_SURFACE)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_STRESS_BOTTOM_SURFACE_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_STRESS_TOP_SURFACE_GLOBAL)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_4PLY_THROUGH_THICKNESS)
KRATOS_CREATE_VARIABLE(double, TSAI_WU_RESERVE_FACTOR)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_LAMINA_STRENGTHS)

// Shell energies
KRATOS_CREATE_VARIABLE(double, SHELL_ELEMENT_MEMBRANE_ENERGY)
KRATOS_CREATE_VARIABLE(double, SHELL_ELEMENT_BENDING_ENERGY)
KRATOS_CREATE_VARIABLE(double, SHELL_ELEMENT_SHEAR_ENERGY)
KRATOS_CREATE_VARIABLE(double, SHELL_ELEMENT_MEMBRANE_ENERGY_FRACTION)
KRATOS_CREATE_VARIABLE(double, SHELL_ELEMENT_BENDING_ENERGY_FRACTION)
KRATOS_CREATE_VARIABLE(double, SHELL_ELEMENT_SHEAR_ENERGY_FRACTION)

// Membrane variables
KRATOS_CREATE_VARIABLE(Vector, MEMBRANE_PRESTRESS)

// Cross section
KRATOS_CREATE_VARIABLE(ShellCrossSection::Pointer, SHELL_CROSS_SECTION)
KRATOS_CREATE_VARIABLE(int, SHELL_CROSS_SECTION_OUTPUT_PLY_ID)
KRATOS_CREATE_VARIABLE(double, SHELL_CROSS_SECTION_OUTPUT_PLY_LOCATION)
KRATOS_CREATE_VARIABLE(Matrix, SHELL_ORTHOTROPIC_LAYERS)

// Nodal stiffness for the nodal concentrated element
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(NODAL_STIFFNESS)
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(NODAL_DAMPING_RATIO)

// For explicit central difference scheme
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(MIDDLE_VELOCITY)
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(NODAL_INERTIA)
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(MIDDLE_ANGULAR_VELOCITY)

// CONDITIONS
/* Beam conditions */
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(POINT_MOMENT)
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(LOCAL_POINT_MOMENT)
/* Torque conditions */
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(POINT_TORQUE)

// Adding the SPRISM EAS variables
KRATOS_CREATE_VARIABLE(double, ALPHA_EAS);
KRATOS_CREATE_VARIABLE(bool, EAS_IMP);
KRATOS_CREATE_VARIABLE(bool, SPRISM_TL_UL);

// Adding the SPRISM additional variables
KRATOS_CREATE_VARIABLE(double, ANG_ROT);

// Adding the Sprism number of transversal integration points
KRATOS_CREATE_VARIABLE(int, NINT_TRANS);

// Adding the SPRISM variable to deactivate the quadratic interpolation
KRATOS_CREATE_VARIABLE(bool, QUAD_ON);

// Additional strain measures
KRATOS_CREATE_VARIABLE(Vector, HENCKY_STRAIN_VECTOR);
KRATOS_CREATE_VARIABLE(Matrix, HENCKY_STRAIN_TENSOR);

KRATOS_CREATE_VARIABLE(double, VON_MISES_STRESS)

KRATOS_CREATE_VARIABLE(Matrix, REFERENCE_DEFORMATION_GRADIENT);
KRATOS_CREATE_VARIABLE(double, REFERENCE_DEFORMATION_GRADIENT_DETERMINANT);

// Rayleigh variables
KRATOS_CREATE_VARIABLE(double, RAYLEIGH_ALPHA)
KRATOS_CREATE_VARIABLE(double, RAYLEIGH_BETA)

// Nodal load variables
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(POINT_LOAD)
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(LINE_LOAD)
KRATOS_CREATE_3D_VARIABLE_WITH_COMPONENTS(SURFACE_LOAD)

// Condition load variables
KRATOS_CREATE_VARIABLE(Vector, POINT_LOADS_VECTOR)
KRATOS_CREATE_VARIABLE(Vector, LINE_LOADS_VECTOR)
KRATOS_CREATE_VARIABLE(Vector, SURFACE_LOADS_VECTOR)
KRATOS_CREATE_VARIABLE(Vector, POSITIVE_FACE_PRESSURES_VECTOR)
KRATOS_CREATE_VARIABLE(Vector, NEGATIVE_FACE_PRESSURES_VECTOR)

KRATOS_CREATE_VARIABLE(MpcDataSharedPointerVectorType, MPC_DATA_CONTAINER)
}
