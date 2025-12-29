#include "GraphMarkProvider.h"

#include "GraphDataVTKAdaptor/GraphVTKObject3D.h"
#include "GraphDataVTKAdaptor/GraphVTKViewAdaptorBase.h"
#include "GraphDataVTKAdaptor/GraphVTKObjectLoadBase.h"

#include "FITK_Kernel/FITKCore/FITKAbstractGraphWidget.h"
#include "FITK_Component/FITKRenderWindowVTK/FITKGraph3DWindowVTK.h"
#include "FITK_Component/FITKRenderWindowVTK/FITKGraphRender.h"



namespace GraphData
{
    QString GraphMarkProvider::getClassName()
    {
        return "GraphMarkProvider";
    }

    QList<Exchange::GraphVTKObject3D*> GraphMarkProvider::getCurrentGraphObjs()
    {
        // 当前所有模型可视化对象数据。
        QList<Exchange::GraphVTKObject3D*> objs;

        return objs;
    }

   
    GraphMarkProvider::GraphMarkProvider(Comp::FITKGraph3DWindowVTK* graphWidget)
        : GraphProviderBase(graphWidget)
    {

    }

    GraphMarkProvider::~GraphMarkProvider()
    {

    }
}   // namespace GraphData