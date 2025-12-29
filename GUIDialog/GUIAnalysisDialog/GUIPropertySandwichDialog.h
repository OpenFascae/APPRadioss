/**********************************************************************
 * @file   GUIPropertySandwichDialog.h
 * @brief  夹层属性窗口
 * @author wangning (2185896382@qq.com)
 * @date   2025-11-03
 *********************************************************************/
#ifndef _GUIPropertySandwichDialog_H
#define _GUIPropertySandwichDialog_H

#include "GUIPropertyDialog.h"

namespace GUI
{
    /**
     * @brief  夹层属性窗口
     * @author wangning (2185896382@qq.com)
     * @date   2025-08-26
     */
    class GUIAnalysisDialogAPI GUIPropertySandwichDialog : public GUIPropertyDialog
    {
        Q_OBJECT;
    public:
        /**
         * @brief 构造函数
         * @param[i]  obj          属性对象
         * @param[i]  oper           operator
         * @param[i]  parent
         * @author wangning (2185896382@qq.com)
         * @date   2025-05-23
         */
        explicit GUIPropertySandwichDialog(Core::FITKActionOperator* oper, Radioss::FITKPropAbstract* obj, QWidget* parent = nullptr);
        virtual ~GUIPropertySandwichDialog() = default;

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

    private slots:
        /**
        * @brief Layer Settings按钮信号
        * @return
        */
        void on_pushButtonLayerSettings_clicked();
    };
}

#endif
