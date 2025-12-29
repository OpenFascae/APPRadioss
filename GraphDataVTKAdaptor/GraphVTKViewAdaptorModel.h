/**********************************************************************
 * @file   GraphVTKViewAdaptorModel.h
 * @brief  模型可视化适配器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-07-18
 *********************************************************************/

#ifndef _GRAPHVTKVIEWADAPTORMODEL_H__
#define _GRAPHVTKVIEWADAPTORMODEL_H__

#include "GraphVTKViewAdaptorBase.h"

#include "GraphDataVTKAdaptorAPI.h"

namespace Interface {
    class FITKAbsGeoModelImport;
}

namespace Exchange
{
    /**
     * @brief  模型可视化适配器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-07-18
     */
    class GraphDataVTKAdaptorAPI GraphVTKViewAdaptorModel : public GraphVTKViewAdaptorBase
    {
        FITKCLASS(Exchange, GraphVTKViewAdaptorModel);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-07-18
         */
        explicit GraphVTKViewAdaptorModel() = default;
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-07-18
         */
        ~GraphVTKViewAdaptorModel() = default;
        /**
         * @brief  更新
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-07-18
         */
        bool update() override;

    };
    Register2FITKViewAdaptorFactory(PartGeo, Interface::FITKAbsGeoShapeAgent, GraphVTKViewAdaptorModel);

}

#endif
