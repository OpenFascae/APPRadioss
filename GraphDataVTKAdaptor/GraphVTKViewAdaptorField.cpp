#include "GraphVTKViewAdaptorField.h"
#include "GraphVTKObjectFieldTRA.h"
#include "GraphVTKObjectFieldAXIS.h"
#include "FITK_Component/FITKRadiossData/FITKInitialField.h"
namespace Exchange
{
    bool GraphVTKViewAdaptorField::update()
    {
        if (_dataObj == nullptr) return false;

        if (!_needUpdate) return (_outputData != nullptr);

        Radioss::FITKAbstractInitialField* field = dynamic_cast<Radioss::FITKAbstractInitialField*>(_dataObj);
        if (field == nullptr) return false;

        if (_outputData)
        {
            delete _outputData;
            _outputData = nullptr;
        }
        auto type = field->getType();
        GraphVTKObjectFieldBase* outputData = nullptr;
        if (type == Radioss::FITKAbstractInitialField::InitialFieldType::TRA)
            outputData = new GraphVTKObjectFieldTRA(field);
        else if(type == Radioss::FITKAbstractInitialField::InitialFieldType::AXIS)
            outputData = new GraphVTKObjectFieldAXIS(field);

        _needUpdate = false;

        if (outputData->getActorCount() == 0)
        {
            delete outputData;
            return false;
        }

        _outputData = outputData;
        return true;
    }
}
