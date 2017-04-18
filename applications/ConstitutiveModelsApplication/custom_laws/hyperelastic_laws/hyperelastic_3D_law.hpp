//
//   Project Name:        KratosConstitutiveModelsApplication $
//   Created by:          $Author:                JMCarbonell $
//   Last modified by:    $Co-Author:                         $
//   Date:                $Date:                December 2016 $
//   Revision:            $Revision:                      0.0 $
//
//

#if !defined (KRATOS_HYPERELASTIC_3D_LAW_H_INCLUDED)
#define  KRATOS_HYPERELASTIC_3D_LAW_H_INCLUDED

// System includes

// External includes

// Project includes
#include "custom_laws/elastic_3D_law.hpp"
#include "custom_models/elasticity_models/hyperelastic_models/hyperelastic_model.hpp"

namespace Kratos
{
  /**
   * Defines a hyperelastic isotropic constitutive law
   * the functionality is limited to large displacements elasticity.
   */
  class KRATOS_API(CONSTITUTIVE_MODELS_APPLICATION) HyperElastic3DLaw : public Elastic3DLaw
  {
  public:

    ///@name Type Definitions
    ///@{
    typedef HyperElasticModel      ModelType;
    
    /// Pointer definition of HyperElastic3DLaw
    KRATOS_CLASS_POINTER_DEFINITION( HyperElastic3DLaw );
	
    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    HyperElastic3DLaw();

    /// Constructor.
    HyperElastic3DLaw(ModelType::Pointer pModel);
    
    /// Copy constructor.
    HyperElastic3DLaw(const HyperElastic3DLaw& rOther);

    /// Clone.
    ConstitutiveLaw::Pointer Clone() const override;

    /// Assignment operator.
    HyperElastic3DLaw& operator=(const HyperElastic3DLaw& rOther);

    /// Destructor.
    virtual ~HyperElastic3DLaw();

    ///@}
    ///@name Operators
    ///@{

    
    ///@}
    ///@name Operations
    ///@{


    /**
     * Computes the material response:
     * PK2 stresses and algorithmic ConstitutiveMatrix
     * @param rValues
     * @see   Parameters
     */
    virtual void CalculateMaterialResponsePK2(Parameters & rValues) override;

    /**
     * Computes the material response:
     * Kirchhoff stresses and algorithmic ConstitutiveMatrix
     * @param rValues
     * @see   Parameters
     */
    virtual void CalculateMaterialResponseKirchhoff (Parameters & rValues) override;

    
    /**
     * This function is designed to be called once to check compatibility with element
     * @param rFeatures
     */
    void GetLawFeatures(Features& rFeatures) override;

    /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param rMaterialProperties
     * @param rElementGeometry
     * @param rCurrentProcessInfo
     * @return
     */
    int Check(const Properties& rMaterialProperties, const GeometryType& rElementGeometry, const ProcessInfo& rCurrentProcessInfo) override;

    ///@}
    ///@name Access
    ///@{
        
    /**
     * Has Values
     */
    
    bool Has( const Variable<double>& rThisVariable ) override;

    /**
     * Set Values
     */

    void SetValue( const Variable<double>& rVariable,
                   const double& rValue,
                   const ProcessInfo& rCurrentProcessInfo ) override;
    
    void SetValue( const Variable<Vector>& rVariable,
                   const Vector& rValue,
                   const ProcessInfo& rCurrentProcessInfo ) override;

    void SetValue( const Variable<Matrix>& rVariable,
                   const Matrix& rValue,
                   const ProcessInfo& rCurrentProcessInfo ) override;   
    
    /**
     * Get Values
     */
   
    double& GetValue( const Variable<double>& rThisVariable, double& rValue )  override;
    
    ///@}
    ///@name Inquiry
    ///@{
        
    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const override
    {
        std::stringstream buffer;
        buffer << "HyperElastic3DLaw";
        return buffer.str();
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << "HyperElastic3DLaw";
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const override
    {
      rOStream << "HyperElastic3DLaw Data";
      mpModel->PrintData(rOStream);
    }


    ///@}
    ///@name Friends
    ///@{


    ///@}

    
  protected:

    ///@name Protected static Member Variables
    ///@{
    
    ///@}
    ///@name Protected member Variables
    ///@{

    //hyper elastic model
    ModelType::Pointer mpModel;
    
    //internal elastic variables

    //stored total deformation gradient for incremental strain update
    double        mDeterminantF0;
    MatrixType    mInverseDeformationGradientF0;

    //elastic cauchy green tensor / including initial strains
    VectorType    mCauchyGreenVector;
    
    ///@}
    ///@name Protected Operators
    ///@{

    ///@}
    ///@name Protected Operations
    ///@{

    /**
     * Initialize ModelData type:
     */
    virtual void InitializeModelData(Parameters& rValues, ModelDataType& rModelValues);	


    /**
     * Finalize ModelData type:
     */
    virtual void FinalizeModelData(Parameters& rValues, ModelDataType& rModelValues);
    
    /**
     * Calculates the stress vector
     * matrix is to be generated for
     * @param rResult Vector the result (Stress Vector) will be stored in
     */
    virtual void CalculateStressVector(ModelDataType& rModelValues, Vector& rStressVector);

    
    /**
     * Calculates the constitutive matrix
     * matrix is to be generated for
     * @param rResult Matrix the result (Constitutive Matrix) will be stored in
     */
    virtual void CalculateConstitutiveMatrix(ModelDataType& rModelValues, Matrix& rConstitutiveMatrix);   


    /**
     * Calculates the stress vector and constitutive matrix
     * matrix is to be generated for
     * @param rResult Vector the result (Stress Vector) will be stored in
     * @param rResult Matrix the result (ConstitutiveMatrix) will be stored in
     */
    virtual void CalculateStressVectorAndConstitutiveMatrix(ModelDataType& rModelValues, Vector& rStressVector, Matrix& rConstitutiveMatrix);

    
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

    virtual void save(Serializer& rSerializer) const override
    {
      KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, Elastic3DLaw )

      rSerializer.save("mpModel",mpModel);
      rSerializer.save("mDeterminantF0",mDeterminantF0);
      rSerializer.save("mInverseDeformationGradientF0",mInverseDeformationGradientF0);
      rSerializer.save("mCauchyGreenVector",mCauchyGreenVector);
    }

    virtual void load(Serializer& rSerializer) override
    {
      KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, Elastic3DLaw )

      rSerializer.load("mpModel",mpModel);
      rSerializer.load("mDeterminantF0",mDeterminantF0);
      rSerializer.load("mInverseDeformationGradientF0",mInverseDeformationGradientF0);
      rSerializer.load("mCauchyGreenVector",mCauchyGreenVector);
    }


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{

    ///@}
  }; // Class HyperElastic3DLaw

  ///@}

  ///@name Type Definitions
  ///@{


  ///@}
  ///@name Input and output
  ///@{

  ///@}

  ///@} addtogroup block
  
}  // namespace Kratos.
#endif // KRATOS_HYPERELASTIC_3D_LAW_H_INCLUDED  defined 
