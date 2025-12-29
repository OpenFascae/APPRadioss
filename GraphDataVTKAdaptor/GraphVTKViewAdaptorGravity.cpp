#include "GraphVTKViewAdaptorGravity.h"
#include "GraphVTKObjectGravity.h"
#include "FITK_Component/FITKRadiossData/FITKGravity.h"
namespace Exchange
{
    bool GraphVTKViewAdaptorGravity::update()
    {
        if (_dataObj == nullptr) return false;

        if (!_needUpdate) return (_outputData != nullptr);

        Radioss::FITKGravity* gravity = dynamic_cast<Radioss::FITKGravity*>(_dataObj);
        if (gravity == nullptr) return false;

        if (_outputData)
        {
            delete _outputData;
            _outputData = nullptr;
        }

        GraphVTKObjectGravity* outputData = new GraphVTKObjectGravity(gravity);
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

