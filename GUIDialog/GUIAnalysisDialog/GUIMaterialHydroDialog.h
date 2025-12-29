/**********************************************************************
 * @file   GUIMaterialHydroDialog.h
 * @brief  Hydro(LAW6) 材料参数窗口声明
 * @author wangning (2185896382@qq.com)
 * @date   2025-05-23
 *********************************************************************/
#ifndef _GUIMaterialHydroDialog_H
#define _GUIMaterialHydroDialog_H

#include "GUIMaterialPropDialog.h"

namespace GUI
{
    /**
     * @brief Hydro(LAW6)  材料参数窗口
     */
    class GUIAnalysisDialogAPI GUIMaterialHydroDialog : public GUIMaterialPropDialog
    {
        Q_OBJECT;
    public:
        explicit GUIMaterialHydroDialog(Interface::FITKAbstractMaterial* obj, Core::FITKActionOperator* oper, QWidget* parent = nullptr);
        virtual~GUIMaterialHydroDialog() = default;

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
