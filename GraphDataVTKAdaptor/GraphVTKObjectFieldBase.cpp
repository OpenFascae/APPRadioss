#include "GraphVTKObjectFieldBase.h"

#include "FITK_Component/FITKRadiossData/FITKAbstractInitialField.h"
namespace Exchange
{
    GraphVTKObjectFieldBase::GraphVTKObjectFieldBase(Radioss::FITKAbstractInitialField* dataObj):
        GraphVTKObjectModelBase(dataObj)
    {
    }
    GraphVTKObjectFieldBase::~GraphVTKObjectFieldBase()
    {
    }
}
