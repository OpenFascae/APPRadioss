/**********************************************************************
 * @file   GraphVTKViewAdaptorInteraction.h
 * @brief  相互作用可视化适配器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-11-10
 *********************************************************************/

#ifndef _GraphVTKViewAdaptorInteraction_H__
#define _GraphVTKViewAdaptorInteraction_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKViewAdaptorBase.h"

namespace Radioss
{
    class FITKInteractionKinematicTied;
    class FITKInteractionMultiUsageImpact;
}

namespace Exchange
{
    /**
     * @brief  相互作用可视化适配器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-11-10
     */
    class GraphDataVTKAdaptorAPI GraphVTKViewAdaptorInteraction : public GraphVTKViewAdaptorBase
    {
        FITKCLASS(Exchange, GraphVTKViewAdaptorInteraction);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-10
         */
        explicit GraphVTKViewAdaptorInteraction() = default;
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-10
         */
        ~GraphVTKViewAdaptorInteraction() = default;
        /**
         * @brief  更新
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-11-10
         */
        bool update() override;
    };
    Register2FITKViewAdaptorFactory(RadiossIKT, Radioss::FITKInteractionKinematicTied, GraphVTKViewAdaptorInteraction);
    Register2FITKViewAdaptorFactory(RadiossIMI, Radioss::FITKInteractionMultiUsageImpact, GraphVTKViewAdaptorInteraction);
}
#endif // !_GRAPHVTKVIEWADPATORFIELD_H__
