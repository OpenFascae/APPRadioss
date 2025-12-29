#include "GraphVTKViewAdaptorModel.h"
#include "GraphVTKObjectModel.h"
#include "FITK_Interface/FITKInterfaceGeometry/FITKAbsGeoCommand.h"

namespace Exchange
{
    bool GraphVTKViewAdaptorModel::update()
    {
        if (_dataObj == nullptr) return false;

        if (!_needUpdate) return (_outputData != nullptr);

        Interface::FITKAbsGeoCommand* geoCommand = dynamic_cast<Interface::FITKAbsGeoCommand*>(_dataObj);
        if (!geoCommand) return false;

        if (_outputData) {
            delete _outputData;
            _outputData = nullptr;
        }
        GraphVTKObjectModel* outputData = new GraphVTKObjectModel(geoCommand);

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
