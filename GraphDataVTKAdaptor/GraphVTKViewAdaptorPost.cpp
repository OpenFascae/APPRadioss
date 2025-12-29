#include "GraphVTKViewAdaptorPost.h"
#include "GraphVTKObjectPostModel.h"
#include "FITK_Interface/FITKInterfaceStructuralPost/FITKAbstractStruPostVTK.h"
namespace Exchange
{
    bool GraphVTKViewAdaptorPost::update()
    {
        if (!_dataObj) {
            return false;
        }

        if (!_needUpdate) {
            return (_outputData != nullptr);
        }

        Interface::FITKAbstractStructuralPostVTK* model = dynamic_cast<Interface::FITKAbstractStructuralPostVTK*>(_dataObj);
        if (!model) {
            return false;
        }

        if (_outputData) {
            delete _outputData;
            _outputData = nullptr;
        }

        // The output data object for view
        GraphVTKObjectPostModel* outputData = new GraphVTKObjectPostModel(model);

        _needUpdate = false;

        // If the actor count is 0, then this graph object is invalid.
        if (outputData->getActorCount() == 0)
        {
            delete outputData;
            return false;
        }

        _outputData = outputData;

        return true;
    }
}
