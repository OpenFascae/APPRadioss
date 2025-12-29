#include "GUIRenameDialog.h"
#include "ui_GUIRenameDialog.h"

#include "FITK_Kernel/FITKCore/FITKAbstractNDataObject.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManagerPrivate.h"

#include <QMessageBox>

namespace GUI
{
    GUIRenameDialog::GUIRenameDialog(Core::FITKActionOperator* oper, QWidget* parent) : GUIDialogBase(parent),
        _ui(new Ui::GUIRenameDialog())
    {
        _ui->setupUi(this);
    }

    GUIRenameDialog::GUIRenameDialog(Core::FITKActionOperator* oper, Core::FITKAbstractNDataObject* obj, Core::FITKAbstractDataManagerPrivate* manager, QWidget* parent) : GUIDialogBase(parent),
        _obj(obj),
        _objManager(manager),
        _ui(new Ui::GUIRenameDialog())
    {
        _ui->setupUi(this);
        //初始化窗口
        this->init();
    }

    GUIRenameDialog::~GUIRenameDialog()
    {
        //销毁ui
        if (_ui) delete _ui;
    }

    void GUIRenameDialog::setObjData(Core::FITKAbstractNDataObject * obj)
    {
        //设置数据对象
        _obj = obj;
    }

    void GUIRenameDialog::setObjManager(Core::FITKAbstractDataManagerPrivate * manager)
    {
        //设置数据对象管理器
        _objManager = manager;
    }

    void GUIRenameDialog::init()
    {
        if (_obj == nullptr) return;
        //初始化界面数据
        _ui->lineEdit_Name->setText(_obj->getDataObjectName());
    }

    void GUIRenameDialog::on_pushButton_OK_clicked()
    {
        //数据对象是否为空
        if (_obj == nullptr) {
            accept();
            return;
        }
        //设置名称
        QString name = _ui->lineEdit_Name->text();
        QString messageText;
        if (name.isEmpty())
            messageText = QObject::tr("The name cannot be empty, whether to rename or not?");
        else if (name == _obj->getDataObjectName())
            messageText = QObject::tr("The name is consistent with the original name, whether to rename or not?");
        else if (_objManager && _objManager->getDataObjectByName(name))
            messageText = QObject::tr("The name is reused, whether to rename or not?");
        if (!messageText.isEmpty())
        {
            QMessageBox::StandardButton but = QMessageBox::warning(this, QObject::tr("Warning"), messageText, QMessageBox::Ok | QMessageBox::Cancel);
            if (but == QMessageBox::Ok)
                return;
        }
        else
            _obj->setDataObjectName(name);
        accept();
    }

    void GUIRenameDialog::on_pushButton_Cancel_clicked()
    {
        reject();
    }

}
