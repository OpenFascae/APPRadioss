/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

/**********************************************************************
 * @file   GUIGeometryBoxDialog.h
 * @brief  长方体
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-15
 *********************************************************************/
#ifndef GUIGEOMETRYBOXDIALOG_H
#define GUIGEOMETRYBOXDIALOG_H

#include "FITK_Kernel/FITKCore/FITKAbstractGUIDialog.h"
#include "GUIGeometryDialogAPI.h"
#include "PickDataProvider/GUIPickInfo.h"

namespace Ui { class GUIGeometryBoxDialog; }
namespace Interface {
    class FITKAbsGeoPart;
}
namespace Core
{
    class FITKActionOperator;
}
namespace GUI {
    /**
     * @brief  创建长方体
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-15
     */
    class GUIGeometryDialogAPI GUIGeometryBoxDialog : public Core::FITKDialog
    {
        Q_OBJECT

    public:

        GUIGeometryBoxDialog(Core::FITKActionOperator* oper,QWidget* parent = nullptr);
        ~GUIGeometryBoxDialog();
    private:
        /**
         * @brief    初始化
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-15
         */
        void init();
        /**
         * @brief    处理拾取到的数据
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-15
         */
        void pickFinishedOper();
        /**
         * @brief    设置拾取方式
         * @param[i] objType
         * @param[i] methodType
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-16
         */
        void enablePickSig(GUI::GUIPickInfo::PickObjType objType, GUI::GUIPickInfo::PickMethod methodType);

    private slots:
        /**
         * @brief  OK按钮
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-15
         */
        void on_pushButton_OK_clicked();
        /**
         * @brief    取消按钮
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-15
         */
        void on_pushButton_Cancel_clicked();
        /**
         * @brief    拾取点的按钮
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-15
         */
        void on_point1_pick_clicked();
    private:
        /**
         * @brief  ui
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-15
         */
        Ui::GUIGeometryBoxDialog *_ui{};
        /**
         * @brief  操作器
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-15
         */
        Core::FITKActionOperator* _oper{};
        /**
         * @brief  几何数据管理器
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-15
         */
        Interface::FITKAbsGeoPart* _geometryData{};
    };
}
#endif 
