#include "GraphVTKViewAdaptorInteraction.h"
#include "GraphVTKObjectInteraction.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractInteraction.h"
namespace Exchange
{
    bool GraphVTKViewAdaptorInteraction::update()
    {
        if (_dataObj == nullptr) return false;

        if (!_needUpdate) return (_outputData != nullptr);

        Radioss::FITKAbstractInteraction* Interaction = dynamic_cast<Radioss::FITKAbstractInteraction*>(_dataObj);
        if (Interaction == nullptr) return false;

        if (_outputData)
        {
            delete _outputData;
            _outputData = nullptr;
        }
        GraphVTKObjectInteraction* outputData = new GraphVTKObjectInteraction(Interaction);
        
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
