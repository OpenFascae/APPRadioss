/**********************************************************************
 * @file   GraphVTKViewAdaptorRigidWall.h
 * @brief  刚性墙渲染适配器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-08-27
 *********************************************************************/
#ifndef _GRAPHVTKVIEWADAPTORRIGIDWALL_H__
#define _GRAPHVTKVIEWADAPTORRIGIDWALL_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKViewAdaptorBase.h"
namespace Radioss {
    class FITKRWallPlane;
    class FITKRWallCylinder;
}

namespace Exchange
{
    /**
     * @brief  刚性墙渲染适配器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-08-27
     */
    class GraphDataVTKAdaptorAPI GraphVTKViewAdaptorRigidWall : public GraphVTKViewAdaptorBase
    {
        FITKCLASS(Exchange, GraphVTKViewAdaptorRigidWall);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-08-27
         */
        explicit GraphVTKViewAdaptorRigidWall() = default;
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-08-27
         */
        ~GraphVTKViewAdaptorRigidWall() = default;
        /**
         * @brief  更新
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-08-27
         */
        bool update() override;
    };
    Register2FITKViewAdaptorFactory(RadiossPlaneWall, Radioss::FITKRWallPlane, GraphVTKViewAdaptorRigidWall);
    Register2FITKViewAdaptorFactory(RadiossCylWall, Radioss::FITKRWallCylinder, GraphVTKViewAdaptorRigidWall);
}

#endif // !_GRAPHVTKVIEWADAPTORRIGIDWALL_H__
