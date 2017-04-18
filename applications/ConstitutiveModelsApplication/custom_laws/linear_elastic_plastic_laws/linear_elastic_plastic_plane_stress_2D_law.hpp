//
//   Project Name:        KratosConstitutiveModelsApplication $
//   Created by:          $Author:                JMCarbonell $
//   Last modified by:    $Co-Author:                         $
//   Date:                $Date:                December 2016 $
//   Revision:            $Revision:                      0.0 $
//
//

#if !defined (KRATOS_LINEAR_ELASTIC_PLASTIC_PLANE_STRESS_2D_LAW_H_INCLUDED)
#define  KRATOS_LINEAR_ELASTIC_PLASTIC_PLANE_STRESS_2D_LAW_H_INCLUDED

// System includes

// External includes

// Project includes
#include "plasticity_models/linear_elastic_plastic_laws/linear_elastic_plastic_plane_strain_2D_law.hpp"


namespace Kratos
{


class KRATOS_API(CONSTITUTIVE_MODELS_APPLICATION) LinearElasticPlasticPlaneStress2DLaw : public LinearElasticPlasticPlaneStrain2DLaw
{
public:
    /**
     * Type Definitions
     */
    typedef ProcessInfo      ProcessInfoType;
    typedef ConstitutiveLaw         BaseType;
    typedef std::size_t             SizeType;

    typedef FlowRule::Pointer                FlowRulePointer;
    typedef YieldCriterion::Pointer    YieldCriterionPointer;
    typedef HardeningLaw::Pointer        HardeningLawPointer;
    typedef Properties::Pointer            PropertiesPointer;

    /**
     * Counted pointer of LinearElasticPlasticPlaneStress2DLaw
     */

    KRATOS_CLASS_POINTER_DEFINITION( LinearElasticPlasticPlaneStress2DLaw );

    /**
     * Life Cycle
     */

    /**
     * Default constructor.
     */
    LinearElasticPlasticPlaneStress2DLaw();


    LinearElasticPlasticPlaneStress2DLaw(FlowRulePointer pFlowRule, YieldCriterionPointer pYieldCriterion, HardeningLawPointer pHardeningLaw); 

    /**
     * Copy constructor.
     */
    LinearElasticPlasticPlaneStress2DLaw (const LinearElasticPlasticPlaneStress2DLaw& rOther);


    /**
     * Assignment operator.
     */

    //LinearElasticPlasticPlaneStress2DLaw& operator=(const LinearElasticPlasticPlaneStress2DLaw& rOther);

    /**
     * Clone function (has to be implemented by any derived class)
     * @return a pointer to a new instance of this constitutive law
     */
    ConstitutiveLaw::Pointer Clone() const;

    /**
     * Destructor.
     */
    virtual ~LinearElasticPlasticPlaneStress2DLaw();

    /**
     * Operators
     */

    /**
     * Operations needed by the base class:
     */

    /**
     * This function is designed to be called once to check compatibility with element
     * @param rFeatures
     */
    void GetLawFeatures(Features& rFeatures);

    /**
     * Input and output
     */
    /**
     * Turn back information as a string.
     */
    //virtual String Info() const;
    /**
     * Print information about this object.
     */
    //virtual void PrintInfo(std::ostream& rOStream) const;
    /**
     * Print object's data.
     */
    //virtual void PrintData(std::ostream& rOStream) const;

protected:

    ///@name Protected static Member Variables
    ///@{
    ///@}
    ///@name Protected member Variables
    ///@{
    ///@}
    ///@name Protected Operators
    ///@{
    ///@}
    ///@name Protected Operations
    ///@{

    /**
     * calculates the linear elastic constitutive matrix in terms of Young's modulus and
     * Poisson ratio
     * @param E the Young's modulus
     * @param NU the Poisson ratio
     * @return the linear elastic constitutive matrix
     */


    void CalculateLinearElasticMatrix( Matrix& rLinearElasticMatrix,
                                    const double& YoungModulus,
                                    const double& PoissonCoefficient );

    ///@}

private:

    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{


    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{


    ///@}
    ///@name Private  Access
    ///@{
    ///@}


    ///@}
    ///@name Serialization
    ///@{
    friend class Serializer;

    virtual void save(Serializer& rSerializer) const
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, LinearElasticPlasticPlaneStrain2DLaw )
    }

    virtual void load(Serializer& rSerializer)
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, LinearElasticPlasticPlaneStrain2DLaw )
    }



}; // Class LinearElasticPlasticPlaneStress2DLaw
}  // namespace Kratos.
#endif // KRATOS_LINEAR_ELASTIC_PLASTIC_PLANE_STRESS_2D_LAW_H_INCLUDED defined
