/**********************************************************************
 * @file   PostGraphWidget.h
 * @brief  后处理模型显示
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-09-10
 *********************************************************************/
#ifndef _POSTGRAPHHWIDGET_H__
#define _POSTGRAPHHWIDGET_H__

#include "GUIWidgetAPI.h"
#include "GraphArea.h"

namespace GUI
{

    /**
     * @brief  后处理模型显示
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-09-10
     */
    class GUIWIDGETAPI PostGraphWidget : public GraphArea
    {
        Q_OBJECT
    public:
        /**
         * @brief    构造函数
         * @param[i] parent 
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-09-10
         */
        explicit PostGraphWidget(QWidget* parent);
        /**
         * @brief    析构函数
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-09-10
         */
        virtual ~PostGraphWidget() = default;

        virtual GraphAreaType getGraphAreaType() override;

    private:

    };
}

#endif
