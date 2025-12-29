#include "GUIFailureJOHNSON_Dialog.h"
#include "ui_GUIFailureModelDialog.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Component/FITKRadiossData/FITKFailureModelJOHNSON.h"

#include <QComboBox>
#include <QMessageBox>

namespace GUI
{
    GUIFailureJOHNSON_Dialog::GUIFailureJOHNSON_Dialog(Core::FITKActionOperator * oper, Radioss::FITKAbstractFailureModel * obj, QWidget * parent)
        : GUIFailureModelDialog(oper, obj, parent)
    {
        _obj = dynamic_cast<Radioss::FITKFailureModelJOHNSON*>(obj);
        if (_obj)
            _isEditMode = true;
        else
            _obj = new Radioss::FITKFailureModelJOHNSON();

        // 初始化
        this->initUI();
        this->init();
    }
    void GUIFailureJOHNSON_Dialog::initUI()
    {
        // 清空
        _ui->tableWidget->clear();
        _ui->tableWidget->setRowCount(0);
        // 设置列数
        _ui->tableWidget->setColumnCount(2);
        _ui->tableWidget->setHorizontalHeaderLabels(QStringList{ "Name","Value" });

        if (!_isEditMode) {
            QString name;
            _oper->argValue("FailureModelName", name);
            _ui->lineEditName->setText(name);
        }
        _ui->lineEditKeyWord->setText("/FAIL/JOHNSON");
        _ui->lineEditKeyWord->setReadOnly(true);
        _ui->lineEditType->setText("Johnson-Cook");
        _ui->lineEditType->setReadOnly(true);
        //D1
        this->addLineEdit("D1", "D1_LineEdit");
        //D2
        this->addLineEdit("D2", "D2_LineEdit");
        //D3
        this->addLineEdit("D3", "D3_LineEdit");
        //D4
        this->addLineEdit("D4", "D4_LineEdit");
        //D5
        this->addLineEdit("D5", "D5_LineEdit");
        //Eps0
        this->addLineEdit("Reference strain rate(Eps0)", "Eps0_LineEdit");
        //Ifailsh
        QComboBox* comBoboxIfailsh = addComboBox("Shell failure flag(Ifailsh)", "Ifailsh_Box");
        comBoboxIfailsh->addItem("Default", 1);
        comBoboxIfailsh->addItem("2", 2);
        //Ifailso
        QComboBox* comBoboxIfailso = addComboBox("Ifailso", "Ifailso_Box");
        comBoboxIfailso->addItem("Default", 1);
        comBoboxIfailso->addItem("2", 2);
        //Dadv
        this->addLineEdit("Criterion for the crack advancement(Dadv)", "Dadv_LineEdit");
        //Ixfem
        QComboBox* comBoboxIxfem = addComboBox("XFEM flag(Ixfem)", "Ixfem_Box");
        comBoboxIxfem->addItem("Default", 0);
        comBoboxIxfem->addItem("XFEM formulation", 1);

        // 行高
        _ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        // 宽度
        _ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    }
    void GUIFailureJOHNSON_Dialog::init()
    {
        Radioss::FITKFailureModelJOHNSON* obj = dynamic_cast<Radioss::FITKFailureModelJOHNSON*>(_obj);
        if (!obj)return;
        if (_isEditMode) {
            _ui->lineEditName->setText(obj->getDataObjectName());
        }
        //D1
        QLineEdit* edit = this->findChild<QLineEdit*>("D1_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getD1()));
        //D2
        edit = this->findChild<QLineEdit*>("D2_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getD2()));
        //D3
        edit = this->findChild<QLineEdit*>("D3_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getD3()));
        //D4
        edit = this->findChild<QLineEdit*>("D4_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getD4()));
        //D5
        edit = this->findChild<QLineEdit*>("D5_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getD5()));
        //Eps0
        edit = this->findChild<QLineEdit*>("Eps0_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getEps0()));
        //Ifailsh
        QComboBox* comBoboxIfailsh = this->findChild<QComboBox*>("Ifailsh_Box");
        if (comBoboxIfailsh) {
            int index = comBoboxIfailsh->findData(obj->getIfailsh());
            comBoboxIfailsh->setCurrentIndex(index);
        }
        //Ifailso
        QComboBox* comBoboxIfailso = this->findChild<QComboBox*>("Ifailso_Box");
        if (comBoboxIfailso) {
            int index = comBoboxIfailso->findData(obj->getIfailso());
            comBoboxIfailso->setCurrentIndex(index);
        }
        //Dadv
        edit = this->findChild<QLineEdit*>("Dadv_LineEdit");
        if (edit)
            edit->setText(QString::number(obj->getDadv()));
        //Ixfem
        QComboBox* comBoboxIxfem = this->findChild<QComboBox*>("Ixfem_Box");
        if (comBoboxIxfem) {
            int index = comBoboxIxfem->findData(obj->getIxfem());
            comBoboxIxfem->setCurrentIndex(index);
        }

    }

    bool GUIFailureJOHNSON_Dialog::ckeckData()
    {
        //获取名称，查重处理
        auto mgr = this->getFailureManager();
        if (!mgr)return false;
        QString name = _ui->lineEditName->text();
        if (name.isEmpty()) {
            QMessageBox::warning(this, "", tr("Name cannot be empty."), QMessageBox::Ok);
            return false;
        }
        else if (mgr->getDataByName(name) && name != _obj->getDataObjectName()) {
            QMessageBox::warning(this, "", tr("\"%1\" The name already exists").arg(name), QMessageBox::Ok);
            return false;
        }
        return true;
    }

    void GUIFailureJOHNSON_Dialog::getDataFormWidget()
    {
        Radioss::FITKFailureModelJOHNSON* obj = dynamic_cast<Radioss::FITKFailureModelJOHNSON*>(_obj);
        if (!obj)return;
        //D1
        QLineEdit* edit = this->findChild<QLineEdit*>("D1_LineEdit");
        if (edit)
            obj->setD1(edit->text().toDouble());
        //D2
        edit = this->findChild<QLineEdit*>("D2_LineEdit");
        if (edit)
            obj->setD2(edit->text().toDouble());
        //D3
        edit = this->findChild<QLineEdit*>("D3_LineEdit");
        if (edit)
            obj->setD3(edit->text().toDouble());
        //D4
        edit = this->findChild<QLineEdit*>("D4_LineEdit");
        if (edit)
            obj->setD4(edit->text().toDouble());
        //D5
        edit = this->findChild<QLineEdit*>("D5_LineEdit");
        if (edit)
            obj->setD5(edit->text().toDouble());
        //Eps0
        edit = this->findChild<QLineEdit*>("Eps0_LineEdit");
        if (edit)
            obj->setEps0(edit->text().toDouble());
        //Ifailsh
        QComboBox* comBoboxIfailsh = this->findChild<QComboBox*>("Ifailsh_Box");
        if (comBoboxIfailsh)
            obj->setIfailsh(comBoboxIfailsh->currentData().toInt());
        //Ifailso
        QComboBox* comBoboxIfailso = this->findChild<QComboBox*>("Ifailso_Box");
        if (comBoboxIfailso)
            obj->setIfailso(comBoboxIfailso->currentData().toInt());
        //Dadv
        edit = this->findChild<QLineEdit*>("Dadv_LineEdit");
        if (edit)
            obj->setDadv(edit->text().toDouble());
        //Ixfem
        QComboBox* comBoboxIxfem = this->findChild<QComboBox*>("Ixfem_Box");
        if (comBoboxIxfem)
            obj->setIxfem(comBoboxIxfem->currentData().toInt());

    }
}