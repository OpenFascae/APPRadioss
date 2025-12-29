#include "GraphVTKViewAdaptorBase.h"

// Graph and data
#include "FITK_Kernel/FITKCore/FITKAbstractNDataObject.h"
#include "GraphVTKObject3D.h"

namespace Exchange
{
    void GraphVTKViewAdaptorBase::setDataObject(Core::FITKAbstractDataObject* data)
    {
        if (data && data != _dataObj)
        {
            _needUpdate = true;
        }

        Adaptor::FITKAbstractViewAdaptor::setDataObject(data);
    }

    void GraphVTKViewAdaptorBase::setDetails(QVariant details)
    {
        // Set the details information for exchanging data.
        _details = details;
    }

    Exchange::GraphVTKObject3D* GraphVTKViewAdaptorBase::getOutputData()
    {
        // The data exchanged to the output
        return _outputData;
    }

    bool GraphVTKViewAdaptorBase::update()
    {
        // override in subclass
        return true;
    }
}   // namespace Exchange
