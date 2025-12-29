/**********************************************************************
 * @file   FITKPolarPlotProperty.h
 * @brief  极坐标图属性类  只能用于“FITKPolarPlotWindow”类
 * @author wangning (2185896382@qq.com)
 * @date   2024-10-25
 *********************************************************************/
#ifndef _FITK_POLARPLOT_PROPERTY_H___
#define _FITK_POLARPLOT_PROPERTY_H___

#include "FITKPlotWindowAPI.h"

class QwtPolarPlot;

namespace Plot
{
    class FITKPolarPlotWindow;

    class FITKPlotWindowAPI FITKPolarPlotProperty
    {
    public:
        FITKPolarPlotProperty(FITKPolarPlotWindow * Window);
        ~FITKPolarPlotProperty();

        /**
         * @brief 设置图表窗口标题
         * @param name 标题
         * @author wangning (2185896382@qq.com)
         * @date   2024-10-25
         */
        void setTitle(const QString &name);

    private:

        /**
         * @brief 管理的窗口
         * @author wangning (2185896382@qq.com)
         * @date   2024-10-25
         */
        FITKPolarPlotWindow * _window{};
    };
}

#endif
