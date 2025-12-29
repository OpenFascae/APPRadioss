#include "GraphVTKViewAdaptorSet.h"
#include "GraphVTKObjectSet.h"

#include "FITK_Interface/FITKInterfaceModel/FITKModelSet.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossNodeGroup.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossElementGroup.h"

namespace Exchange
{
    bool GraphVTKViewAdaptorSet::update()
    {
        if (_dataObj == nullptr) {
            return false;
        }

        if (!_needUpdate)
        {
            return (_outputData != nullptr);
        }

        Radioss::FITKRadiossNodeGroup* model = dynamic_cast<Radioss::FITKRadiossNodeGroup*>(_dataObj);
        Radioss::FITKRadiossElementGroup* modelSet = dynamic_cast<Radioss::FITKRadiossElementGroup*>(_dataObj);
        if (_outputData) {
            delete _outputData;
            _outputData = nullptr;
        }
        GraphVTKObjectSet* outputData = nullptr;
        if (model)
        {
            outputData = new GraphVTKObjectSet(model, _details.toInt());
        }
        else if (modelSet)
        {

            outputData = new GraphVTKObjectSet(modelSet, _details.toInt());
        }

        _needUpdate = false;

        if (outputData->getActorCount() == 0) {
            delete outputData;
            return false;
        }

        _outputData = outputData;
        return true;
    }
}