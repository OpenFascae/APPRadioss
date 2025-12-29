/**********************************************************************
 * @file   GUIDialogBase.h
 * @brief  对话框基类
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-07-22
 *********************************************************************/
#ifndef _GUIDialogBase_H
#define _GUIDialogBase_H

#include "GUIWidgetAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractGUI.h"
#include <QStandardItem>

#ifndef CASEIDROLE
#define CASEIDROLE Qt::UserRole + 101
#endif // !CASEIDROLE
#ifndef OBJIDROLE
#define OBJIDROLE Qt::UserRole + 102
#endif // !OBJIDROLE
#define STEPIDROLE Qt::UserRole + 103
#define OperatorData Core::FITKOperatorRepo::getInstance()

namespace Core
{
    class FITKAbstractOperator;
    class FITKAbstractNDataObject;
    class FITKActionOperator;
}

namespace GUI
{
    /**
     * @brief  对话框基类
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-07-22
     */
    class MainWindow;
    class GUIWIDGETAPI GUIDialogBase :public Core::FITKDialog
    {
        Q_OBJECT;
    public:
        /**
         * @brief    构造函数
         * @param[i] parent 
         * @return   void
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        GUIDialogBase(QWidget* parent);
        /**
         * @brief    析构函数
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        virtual ~GUIDialogBase();
        /**
         * @brief  设置参数
         * @param  oper 操作器
         * @param  item 列表项
         * @param  button 按钮
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        void setOperArgs(Core::FITKAbstractOperator* oper, QStandardItem* item, QObject* button);
        /**
         * @brief  设置参数
         * @param  oper 操作器
         * @param  item 列表项
         * @param  button 按钮
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        void setOperArgs(Core::FITKAbstractOperator* oper, QList<QStandardItem*> items, QObject* button);
    protected:
        /**
         * @brief  检测名称格式的合法性
         * @param  name 名称字符串
         * @return 返回检查结果
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        bool checkNameFormat(QString name, bool showMsg = true) const;
        /**
         * @brief 校验字符串是否可以正确转化数字类型
         * @param[in] value 要校验的字符串
         * @param[in] type 数字类型，可选择：int、float、double
         * @param[in] showMsg 如果发生错误时是否弹出警告信息
         * @return 如果数据校验通过则返回true，否则返回false
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        bool checkDataFromat(QString value, QString type, bool showMsg = true) const;
        /**
         * @brief 校验对话框数据是否合法
         * @return 如果数据校验通过则返回true，否则返回false
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        virtual bool checkDialogData() const;
    protected:
        /**
         * @brief  主窗口
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        QWidget* _mainWindow{ };
        /**
         * @brief  对话框唯一标识
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-07-22
         */
        QString _uniqueFlag;
    };

}

#endif