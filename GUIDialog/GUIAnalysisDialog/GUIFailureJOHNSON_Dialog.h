/**********************************************************************
 * @file   GUIFailureJOHNSON_Dialog.h
 * @brief  JOHNSON型失效窗口
 * @author wangning (2185896382@qq.com)
 * @date   2025-11-12
 *********************************************************************/
#ifndef _GUIFailureJOHNSON_Dialog_H
#define _GUIFailureJOHNSON_Dialog_H

#include "GUIFailureModelDialog.h"

namespace GUI
{
    /**
     * @brief  BIQUAD型失效窗口
     * @author wangning (2185896382@qq.com)
     * @date   2025-11-12
     */
    class GUIAnalysisDialogAPI GUIFailureJOHNSON_Dialog : public GUIFailureModelDialog
    {
        Q_OBJECT;
    public:
        /**
         * @brief 构造函数
         * @param[i]  obj          属性对象
         * @param[i]  oper           operator
         * @param[i]  parent
         * @author wangning (2185896382@qq.com)
         * @date    2025-11-12
         */
        explicit GUIFailureJOHNSON_Dialog(Core::FITKActionOperator* oper, Radioss::FITKAbstractFailureModel* obj, QWidget* parent = nullptr);
        virtual ~GUIFailureJOHNSON_Dialog() = default;

    protected:
        /**
        * @brief    UI初始化
        * @return   void
        * @author wangning (2185896382@qq.com)
        * @date   2025-08-26
        */
        void initUI();
        /**
        * @brief    数据初始化
        * @return   void
        * @author wangning (2185896382@qq.com)
        * @date   2025-05-23
        */
        void init() override;
        /**
         * @brief    检查
         * @author wangning (2185896382@qq.com)
         * @date   2025-05-23
         */
        bool ckeckData() override;
        /**
         * @brief    从界面获取数据
         * @return   void
         * @author wangning (2185896382@qq.com)
         * @date   2025-05-23
         */
        void getDataFormWidget() override;
    };
}

#endif

