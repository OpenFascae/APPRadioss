/**********************************************************************
 * @file   GUIMaterialJohnsonCookDialog.h
 * @brief  Johnson-Cook 材料参数窗口声明
 * @author wangning (2185896382@qq.com)
 * @date   2025-05-23
 *********************************************************************/
#ifndef _GUIMaterialJohnsonCookDialog_H
#define _GUIMaterialJohnsonCookDialog_H

#include "GUIMaterialPropDialog.h"

namespace GUI
{
    /**
     * @brief Johnson-Cook 材料参数窗口
     */
    class GUIAnalysisDialogAPI GUIMaterialJohnsonCookDialog : public GUIMaterialPropDialog
    {
        Q_OBJECT;
    public:
        explicit GUIMaterialJohnsonCookDialog(Interface::FITKAbstractMaterial* obj,Core::FITKActionOperator* oper,QWidget* parent = nullptr);
        virtual~GUIMaterialJohnsonCookDialog() = default;

    protected:
        /**
        * @brief  初始化UI
        * @author wangning (2185896382@qq.com)
        * @date   2025-05-23
        */
        void initUI();
        /**
        * @brief  初始化数据
        * @author wangning (2185896382@qq.com)
        * @date   2025-05-23
        */
        void init() override;

        /**
        * @brief    检查
        * @return   QString
        * @author wangning (2185896382@qq.com)
        * @date   2025-05-23
        */
        virtual bool ckeckData()override;
        
        /**
        * @brief    从界面获取数据
        * @return   QString
        * @author wangning (2185896382@qq.com)
        * @date   2025-05-23
        */
        void getDataFormWidget() override;

    };
}

#endif
