#include "GraphVTKObjectPostModel.h"

#include "FITK_Interface/FITKInterfaceStructuralPost/FITKAbstractStruPostVTK.h"
#include "FITK_Interface/FITKInterfaceStructuralPost/FITKStruPostMessageText.h"
#include "FITK_Interface/FITKVTKAlgorithm/FITKGraphActor.h"

#include <vtkActor.h>
#include <vtkAlgorithm.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>

namespace Exchange
{
    GraphVTKObjectPostModel::GraphVTKObjectPostModel(Interface::FITKAbstractStructuralPostVTK* postData) :
        GraphVTKObjectPostModelBase(postData)
    {
        if (postData == nullptr) {
            return;
        }

        vtkAlgorithm* postDataAlg = postData->getOutputAlgorithm();
        if (postDataAlg == nullptr) {
            return;
        }

        init();
        _postActor->setInputConnection(postDataAlg->GetOutputPort());
    }

    GraphVTKObjectPostModel::~GraphVTKObjectPostModel()
    {

    }
    vtkScalarBarActor* GraphVTKObjectPostModel::getScalarBarActor()
    {
        return _scalarBarActor;
    }
}