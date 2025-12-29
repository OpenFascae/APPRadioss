/**********************************************************************
 * @file   GraphVTKViewAdaptorField.h
 * @brief  初始化场可视化适配器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-09-05
 *********************************************************************/

#ifndef _GRAPHVTKVIEWADPATORFIELD_H__
#define _GRAPHVTKVIEWADPATORFIELD_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKViewAdaptorBase.h"

namespace Radioss
{
    class FITKInitialFieldTra;
    class FITKInitialFieldAxis;
}

namespace Exchange
{
    /**
     * @brief  初始化场可视化适配器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-09-05
     */
    class GraphDataVTKAdaptorAPI GraphVTKViewAdaptorField : public GraphVTKViewAdaptorBase
    {
        FITKCLASS(Exchange, GraphVTKViewAdaptorField);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-09-05
         */
        explicit GraphVTKViewAdaptorField() = default;
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-09-05
         */
        ~GraphVTKViewAdaptorField() = default;
        /**
         * @brief  更新
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-09-05
         */
        bool update() override;
    };
    Register2FITKViewAdaptorFactory(RadiossFieldTRA, Radioss::FITKInitialFieldTra, GraphVTKViewAdaptorField);
    Register2FITKViewAdaptorFactory(RadiossFieldAXIS, Radioss::FITKInitialFieldAxis, GraphVTKViewAdaptorField);
}
#endif // !_GRAPHVTKVIEWADPATORFIELD_H__
