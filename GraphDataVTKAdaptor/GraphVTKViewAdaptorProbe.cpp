#include "GraphVTKViewAdaptorProbe.h"
#include "GraphVTKObjectProbeAcceleration.h"
#include "GraphVTKObjectProbeSection.h"

#include "FITK_Component/FITKRadiossData/FITKAbstractProbe.h"
#include "FITK_Component/FITKRadiossData/FITKProbeAcceleration.h"
#include "FITK_Component/FITKRadiossData/FITKProbeSection.h"

namespace Exchange
{
    bool GraphVTKViewAdaptorProbe::update()
    {
        if (_dataObj == nullptr) return false;

        if (!_needUpdate) return (_outputData != nullptr);

        Radioss::FITKProbeAcceleration* accelProbe = dynamic_cast<Radioss::FITKProbeAcceleration*>(_dataObj);
        Radioss::FITKProbeSection* sectionProbe = dynamic_cast<Radioss::FITKProbeSection*>(_dataObj);

        GraphVTKObjectModelBase* outputData = nullptr;

        if (accelProbe)
        {
            outputData = new GraphVTKObjectProbeAcceleration(accelProbe);
        }
        if(sectionProbe)
        {
            outputData = new GraphVTKObjectProbeSection(sectionProbe);
        }

        if (_outputData)
        {
            delete _outputData;
            _outputData = nullptr;
        }

     
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
