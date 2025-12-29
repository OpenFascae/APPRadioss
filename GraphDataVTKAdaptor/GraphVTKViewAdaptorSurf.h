/**********************************************************************
 * @file   GraphVTKViewAdaptorSurf.h
 * @brief  表面适配器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-08-21
 *********************************************************************/
#ifndef __GraphVTKViewAdaptorSurf_H__
#define __GraphVTKViewAdaptorSurf_H__

#include "GraphVTKViewAdaptorBase.h"
#include "GraphDataVTKAdaptorAPI.h"

namespace Exchange
{
    /**
     * @brief  表面适配器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-08-21
     */
    class GraphDataVTKAdaptorAPI GraphVTKViewAdaptorSurf : public GraphVTKViewAdaptorBase
    {
        FITKCLASS(Exchange, GraphVTKViewAdaptorSurf);
    public:
        /**
         * @brief    构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-08-21
         */
        explicit GraphVTKViewAdaptorSurf() = default;
        /**
         * @brief    析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-08-21
         */
        virtual ~GraphVTKViewAdaptorSurf() = default;
        /**
         * @brief    执行适配
         * @return   bool                    是否成功
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-08-21
         */
        bool update() override;

    };
    Register2FITKViewAdaptorFactory(SurfEle, Interface::FITKMeshSurfaceElement, GraphVTKViewAdaptorSurf);
    Register2FITKViewAdaptorFactory(SurfEleSeg, Radioss::FITKRadiossSurfaceSeg, GraphVTKViewAdaptorSurf);
    Register2FITKViewAdaptorFactory(SurfNode, Interface::FITKMeshSurfaceNode, GraphVTKViewAdaptorSurf);
}

#endif
