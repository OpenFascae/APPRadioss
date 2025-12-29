/**********************************************************************
 * @file   GUIPropertyTypeDialog.h
 * @brief  属性创建，类型选择对话框声明
 * @author wangning (2185896382@qq.com)
 * @date   2025-05-23
 *********************************************************************/
#ifndef _GUIPropertyTypeDialog_H
#define _GUIPropertyTypeDialog_H

#include <QDialog>
#include "GUIAnalysisDialogAPI.h"

namespace Ui
{
    class GUIPropertyTypeDialog;
}

namespace GUI
{
    /**
     * @brief 属性创建，类型选择对话框
     */
    class GUIAnalysisDialogAPI GUIPropertyTypeDialog : public QDialog
    {
        Q_OBJECT
    public:
        explicit GUIPropertyTypeDialog(QWidget* parent = nullptr);
        ~GUIPropertyTypeDialog();

        /**
         * @brief 获取属性类型
         * @return 类型
         */
        int getPropType();
        /**
         * @brief 获取名称
         * @return 名字
         */
        QString getName();

    private slots:
        /**
        * @brief OK按钮信号
        * @return
        */
        void on_pushButtonOK_clicked();
        /**
        * @brief cancel按钮信号
        * @return
        */
        void on_pushButtonCancel_clicked();
        /**
         * @brief    comboBox页切换
         * @param[i] index
         */
        void on_comboBox_type_currentIndexChanged(int index);

    private:
        Ui::GUIPropertyTypeDialog* _ui;
    };
}

#endif
