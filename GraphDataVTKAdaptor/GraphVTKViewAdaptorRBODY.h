/**********************************************************************
 * @file   GraphVTKViewAdaptorRBODY.h
 * @brief  刚性体连接可视化适配器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-11-10
 *********************************************************************/

#ifndef _GraphVTKViewAdaptorRBODY_H__
#define _GraphVTKViewAdaptorRBODY_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKViewAdaptorBase.h"

namespace Radioss
{
    class FITKConnectionRBODY;
}

namespace Exchange
{
    /**
     * @brief  刚性体连接可视化适配器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-11-10
     */
    class GraphDataVTKAdaptorAPI GraphVTKViewAdaptorRBODY : public GraphVTKViewAdaptorBase
    {
        FITKCLASS(Exchange, GraphVTKViewAdaptorRBODY);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-10
         */
        explicit GraphVTKViewAdaptorRBODY() = default;
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-10
         */
        ~GraphVTKViewAdaptorRBODY() = default;
        /**
         * @brief  更新
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-10
         */
        bool update() override;
    };
    Register2FITKViewAdaptorFactory(RadiossRBODY, Radioss::FITKConnectionRBODY, GraphVTKViewAdaptorRBODY);
}
#endif // !_GRAPHVTKVIEWADPATORFIELD_H__
