#include "GUIDialogBase.h"

#include "GUIFrame/MainWindow.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"

#include "FITK_Kernel/FITKCore/FITKAbstractOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "OperatorsInterface/GraphEventOperator.h"
#include <QMessageBox>
namespace GUI
{
    GUIDialogBase::GUIDialogBase(QWidget * parent) :
        Core::FITKDialog(parent), _mainWindow(parent)
    {

    }

    GUIDialogBase::~GUIDialogBase()
    {
      
    }
    // 设置操作参数
    void GUIDialogBase::setOperArgs(Core::FITKAbstractOperator* oper, QStandardItem* item, QObject* button)
    {
        // 如果操作器为空，则直接返回
        if (oper == nullptr)
            return;
        if (button != nullptr)
        {
            oper->setArgs("btnName", button->objectName()); // 设置按钮名称作为操作器参数
        }
        if (item != nullptr)
        {
            // 如果提供了标准项，则从中获取案例ID、对象ID和步骤ID，并设置为操作器参数
            int caseID = item->data(CASEIDROLE).toInt();
            int objID = item->data(OBJIDROLE).toInt();
            int stepID = item->data(STEPIDROLE).toInt();
            oper->setArgs("caseID", caseID);
            oper->setArgs("objID", objID);
            oper->setArgs("stepID", stepID);
            oper->setArgs("IsMultiOper", false); // 是否为多选项操作
        }
        // 将对话框自身设置为操作器参数
        oper->setArgs("dlg", QVariant::fromValue<QDialog*>(this));
    }
    // 设置操作参数
    void GUIDialogBase::setOperArgs(Core::FITKAbstractOperator* oper, QList<QStandardItem*> items, QObject* button)
    {
        // 如果操作器为空，则直接返回
        if (oper == nullptr)
            return;
        if (button != nullptr)
        {
            oper->setArgs("btnName", button->objectName()); // 设置按钮名称作为操作器参数
        }
        QList<QVariant> caseIDs = {};
        QList<QVariant> objIDs = {};
        QList<QVariant> stepIDs = {};
        for (auto item : items) {
            if (item == nullptr) continue;
            caseIDs.append(item->data(CASEIDROLE).toInt());
            objIDs.append(item->data(OBJIDROLE).toInt());
            stepIDs.append(item->data(STEPIDROLE).toInt());
        }
        oper->setArgs("caseIDs", caseIDs);
        oper->setArgs("objIDs", objIDs);
        oper->setArgs("stepIDs", stepIDs);
        oper->setArgs("IsMultiOper", true);  // 是否为多选项操作

        // 将对话框自身设置为操作器参数
        oper->setArgs("dlg", QVariant::fromValue<QDialog*>(this));
    }

    // 检查名称格式是否符合要求
  // 格式要求：名称长度必须为1 - 38个字符，不能以数字开头，不能以空格或下划线开头或结尾，不能包含双引号、句号、反斜杠或不可打印的字符。
    bool GUIDialogBase::checkNameFormat(QString name, bool showMsg) const
    {
        // 1. 长度为1到38个字符
        if (name.length() < 1 || name.length() > 38) {
            if (showMsg) {
                QMessageBox::critical(nullptr, tr("Error Information"), tr("Invalid name\n\nNames must be 1-38 characters long,\nmay not begin with a number, may not\nbegin or end with a space or an\nunderscore, and may not contain double\nquotes, periods, backward slashes, or\nnon-printable characters."));
            }
            return false;
        }

        auto firstChar = name.at(0).toLatin1();
        auto lastChar = name.back().toLatin1();

        // 2. 不以数字开头
//         if (isdigit(firstChar)) {
//             if (showMsg) {
//                 QMessageBox::critical(nullptr, tr("Error Information"), tr("Invalid name\n\nNames must be 1-38 characters long,\nmay not begin with a number, may not\nbegin or end with a space or an\nunderscore, and may not contain double\nquotes, periods, backward slashes, or\nnon-printable characters."));
//             }
//             return false;
//         }

        // 3. 不以空格或下划线开头或结尾
        if (firstChar == ' ' || firstChar == '_') {
            if (showMsg) {
                QMessageBox::critical(nullptr, tr("Error Information"), tr("Invalid name\n\nNames must be 1-38 characters long,\nmay not begin with a number, may not\nbegin or end with a space or an\nunderscore, and may not contain double\nquotes, periods, backward slashes, or\nnon-printable characters."));
            }
            return false;
        }
        if (lastChar == ' ' || lastChar == '_') {
            if (showMsg) {
                QMessageBox::critical(nullptr, tr("Error Information"), tr("Invalid name\n\nNames must be 1-38 characters long,\nmay not begin with a number, may not\nbegin or end with a space or an\nunderscore, and may not contain double\nquotes, periods, backward slashes, or\nnon-printable characters."));
            }
            return false;
        }

        // 4. 不包含双引号、句号、反斜杠或不可打印的字符
        for (auto c : name) {
            if (c == '\"' || c == '.' || c == '\\' || !isprint(static_cast<unsigned char>(c.toLatin1()))) {
                if (showMsg) {
                    QMessageBox::critical(nullptr, tr("Error Information"), tr("Invalid name\n\nNames must be 1-38 characters long,\nmay not begin with a number, may not\nbegin or end with a space or an\nunderscore, and may not contain double\nquotes, periods, backward slashes, or\nnon-printable characters."));
                }
                return false;
            }
        }

        return true;
    }
    //检验字符的类型
    bool GUIDialogBase::checkDataFromat(QString value, QString type, bool showMsg) const
    {
        // 当值为空时，如果设置为显示消息，则弹出错误信息
        if (value.simplified().isEmpty())
        {
            if (showMsg)
            {
                QMessageBox::critical(nullptr, tr("Error Information"), tr("Missing value!"));
            }
            return false;
        }
        // 根据预期类型尝试转换值
        bool result{ false };
        if (type == "int")
        {
            value.toInt(&result);
        }
        else if (type == "double")
        {
            value.toDouble(&result);
        }
        else if (type == "float")
        {
            value.toFloat(&result);
        }
        // 如果转换成功，则返回 true
        if (result)
        {
            return true;
        }
        // 转换失败且设置为显示消息时，弹出包含具体错误信息的消息框
        if (showMsg)
        {
            QMessageBox::critical(nullptr, tr("Error Information"), QString(tr("The syntax error in the expression below must be corrected.\n%1")).arg(value));
        }
        return false;
    }


    bool GUIDialogBase::checkDialogData() const
    {
        return true;
    }
}