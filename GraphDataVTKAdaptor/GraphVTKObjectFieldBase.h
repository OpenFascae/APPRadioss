/**********************************************************************
 * @file   GraphVTKObjectFieldBase.h
 * @brief  初始化场可视化对象基类
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-11-11
 *********************************************************************/
#ifndef _GraphVTKObjectFieldBase_H__
#define _GraphVTKObjectFieldBase_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKObjectModelBase.h"


 // Forward declaration
class vtkUnstructuredGrid;
class RadiossVTKGraphActor;

namespace Radioss
{
    class FITKAbstractInitialField;
}

namespace Exchange
{
    /**
     * @brief  角速度场可视化对象
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-11-11
     */
    class GraphDataVTKAdaptorAPI GraphVTKObjectFieldBase : public GraphVTKObjectModelBase
    {
        // Regist
        FITKGraphObjectRegist(GraphVTKObjectFieldBase, GraphVTKObjectModelBase);
        FITKCLASS(Exchange, GraphVTKObjectFieldBase);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-11
         */
        GraphVTKObjectFieldBase(Radioss::FITKAbstractInitialField* dataObj);
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-11
         */
        virtual ~GraphVTKObjectFieldBase();

    };
}
#endif // !_GraphVTKObjectFieldBase_H__
