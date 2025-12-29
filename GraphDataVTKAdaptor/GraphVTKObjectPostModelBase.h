/**********************************************************************
 * @file   GraphVTKObjectPostModelBase.h
 * @brief  后处理模型渲染基类
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-09-10
 *********************************************************************/

#ifndef _GRAPHVTKOBJECTPOSTMODELBASE_H__
#define _GRAPHVTKOBJECTPOSTMODELBASE_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKObject3DPostBase.h"

namespace Exchange
{
    /**
     * @brief  后处理模型渲染基类
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-09-10
     */
    class GraphDataVTKAdaptorAPI GraphVTKObjectPostModelBase : public GraphVTKObject3DPostBase
    {
        Q_OBJECT;
        FITKGraphObjectRegist(GraphVTKObjectPostModelBase, GraphVTKObject3DPostBase);
        FITKCLASS(Exchange, GraphVTKObjectPostModelBase);
    public:
        /**
         * @brief  构造函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-09-10
         */
        GraphVTKObjectPostModelBase(Core::FITKAbstractDataObject* dataObj);
        /**
         * @brief  析构函数
         * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date   2025-09-10
         */
        virtual ~GraphVTKObjectPostModelBase();

    };
}
#endif // !_GRAPHVTKOBJECTPOSTMODELBASE_H__
