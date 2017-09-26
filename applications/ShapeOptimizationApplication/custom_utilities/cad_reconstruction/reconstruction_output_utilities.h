// ==============================================================================
//  KratosShapeOptimizationApplication
//
//  License:         BSD License
//                   license: ShapeOptimizationApplication/license.txt
//
//  Main authors:    Baumgaertner Daniel, https://github.com/dbaumgaertner
//
// ==============================================================================

#ifndef CAD_RECONSTRUCTION_OUTPUT_UTILITIES
#define CAD_RECONSTRUCTION_OUTPUT_UTILITIES

// ------------------------------------------------------------------------------
// System includes
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// External includes
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Project includes
// ------------------------------------------------------------------------------
#include "includes/define.h"
#include "processes/process.h"
#include "includes/node.h"
#include "includes/element.h"
#include "includes/model_part.h"
#include "includes/kratos_flags.h"
#include "reconstruction_data_base.h"

// ==============================================================================

namespace Kratos
{
class ReconstructionOutputUtilities
{
  public:
    ///@name Type Definitions
    ///@{

    typedef Node<3> NodeType;

    /// Pointer definition of ReconstructionOutputUtilities
    KRATOS_CLASS_POINTER_DEFINITION(ReconstructionOutputUtilities);

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    ReconstructionOutputUtilities( ReconstructionDataBase& reconstruction_data_base )
    : mpReconstructionDataBase( reconstruction_data_base )
    {      
    }

    /// Destructor.
    virtual ~ReconstructionOutputUtilities()
    {
    }

    // --------------------------------------------------------------------------
    void OutputCADSurfacePoints( std::string output_filename, const unsigned int u_resolution, const unsigned int v_resolution )
    {
	    std::cout << "\n> Start writing surface points of given CAD geometry to file..." << std::endl;
      std::ofstream file_to_write(output_filename);
	
    	// Set a max value for the coordinte output to avoid clutter through points that moving uncontrolled
      double max_coordinate = 1000;
      std::cout << "> Max value for control point coordinates set to " << max_coordinate << "." << std::endl;

      std::vector<Patch>& patches = mpReconstructionDataBase.GetPatchVector();
      for(auto & patch_i : patches) 
			{
				std::vector<double>& knot_vec_u_i = patch_i.GetSurface().GetKnotVectorU();
        std::vector<double>& knot_vec_v_i = patch_i.GetSurface().GetKnotVectorV();
      
				double u_min = knot_vec_u_i[0];
				double u_max = knot_vec_u_i[knot_vec_u_i.size()-1];
				double v_min = knot_vec_v_i[0];
				double v_max = knot_vec_v_i[knot_vec_v_i.size()-1];
				double delta_u = (u_max-u_min) / u_resolution;
				double delta_v = (v_max-v_min) / v_resolution;

				// Loop over all u & v according to specified resolution
				for(unsigned int i=0; i<=u_resolution; i++)
				{
					double u_i = u_min + i*delta_u;

					for(unsigned int j=0; j<=v_resolution; j++)
					{
						double v_j = v_min + j*delta_v;

						// Check if u_i and v_j represent a point inside the closed boundary loop
						array_1d<double, 2> point_of_interest;
						point_of_interest[0] = u_i;
						point_of_interest[1] = v_j;
						bool point_is_inside = patch_i.IsPointInside(point_of_interest);

						if(point_is_inside)
						{
							Point<3> cad_point;
							patch_i.GetSurface().EvaluateSurfacePoint(cad_point, u_i, v_j);

							if(std::abs(cad_point.X())>max_coordinate)
								cad_point.X() = MathUtils<int>::Sign(cad_point.X()) * max_coordinate;
							if(std::abs(cad_point.Y())>max_coordinate)
								cad_point.Y() = MathUtils<int>::Sign(cad_point.Y()) * max_coordinate;
							if(std::abs(cad_point.Z())>max_coordinate)
								cad_point.Z() = MathUtils<int>::Sign(cad_point.Z()) * max_coordinate;														

							file_to_write << cad_point.X() << " " << cad_point.Y() << " " << cad_point.Z() << std::endl;
						}
					}
				}
      }
      file_to_write.close();
      std::cout << "> Finished writing surface points of given CAD geometry to file." << std::endl;
    }

    // --------------------------------------------------------------------------
    void OutputGaussPointsOfFEMesh( std::string output_filename, int integration_degree )
    {
	    std::cout << "\n> Start writing Gauss points of given FE-mesh..." << std::endl;
      std::ofstream file_to_write(output_filename);
  
      Element::GeometryType::IntegrationMethod integration_method;
      switch(integration_degree)
      {
        case 1 : integration_method = GeometryData::GI_GAUSS_1; break;
        case 2 : integration_method = GeometryData::GI_GAUSS_2; break;
        case 3 : integration_method = GeometryData::GI_GAUSS_3; break;
        case 4 : integration_method = GeometryData::GI_GAUSS_4; break;
        case 5 : integration_method = GeometryData::GI_GAUSS_5; break;                                                           
      }

      ModelPart& r_fe_model_part = mpReconstructionDataBase.GetFEModelPart();
      for (ModelPart::ElementsContainerType::iterator elem_i = r_fe_model_part.ElementsBegin(); elem_i != r_fe_model_part.ElementsEnd(); ++elem_i)
      {
        Element::GeometryType& geom_i = elem_i->GetGeometry();
        const Element::GeometryType::IntegrationPointsArrayType& integration_points = geom_i.IntegrationPoints(integration_method);
        const unsigned int number_of_integration_points = integration_points.size();

        for ( unsigned int PointNumber = 0; PointNumber < number_of_integration_points; PointNumber++ )
        {
          NodeType::CoordinatesArrayType ip_coordinates = geom_i.GlobalCoordinates(ip_coordinates, integration_points[PointNumber].Coordinates());

          file_to_write << ip_coordinates[0] << " " << ip_coordinates[1] << " " << ip_coordinates[2] << std::endl;
        }
      }
    file_to_write.close();
    std::cout << "> Finished writing Gauss points of given FE-mesh." << std::endl;
  }

  // --------------------------------------------------------------------------
    void OutputControlPointDisplacementsInRhinoFormat( std::string output_filename )
    {
      std::cout << "\n> Start writing displacements of control points into Rhino results file..." << std::endl;
      std::ofstream output_file(output_filename);

      output_file << "Rhino Post Results File 1.0" << std::endl;
      output_file << "Result \"Displacement\" \"Load Case\" 0 Vector OnNodes" << std::endl;
      output_file << "Values" << std::endl;

      unsigned int control_point_iterator = 0;
      std::vector<Patch>& patches = mpReconstructionDataBase.GetPatchVector();
      for(auto & patch_i : patches) 
			{
        std::vector<ControlPoint>& control_points = patch_i.GetSurface().GetControlPoints();
        for(auto & control_point_i : control_points)
        {
          // It is important to iterate outside to stick to the carat settings
          ++control_point_iterator;
          
          if(control_point_i.IsRelevantForMapping())
            output_file << control_point_iterator << " " << control_point_i.GetdX() << " " << control_point_i.GetdY() << " " << control_point_i.GetdZ() << std::endl;
        }
      }

      output_file << "End Values" << std::endl;
      output_file.close();
      std::cout << "> Finished writing displacements of control points into Rhino results file..." << std::endl;
    }

    // ==============================================================================

    /// Turn back information as a string.
    virtual std::string Info() const
    {
		return "ReconstructionOutputUtilities";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream &rOStream) const
    {
		rOStream << "ReconstructionOutputUtilities";
    }

    /// Print object's data.
    virtual void PrintData(std::ostream &rOStream) const
    {
    }

  private:

	// ==============================================================================
    // Solver and strategies
    // ==============================================================================
    ReconstructionDataBase& mpReconstructionDataBase;

    /// Assignment operator.
    //      ReconstructionOutputUtilities& operator=(ReconstructionOutputUtilities const& rOther);

    /// Copy constructor.
    //      ReconstructionOutputUtilities(ReconstructionOutputUtilities const& rOther);

}; // Class ReconstructionOutputUtilities
} // namespace Kratos.

#endif // CAD_RECONSTRUCTION_OUTPUT_UTILITIES