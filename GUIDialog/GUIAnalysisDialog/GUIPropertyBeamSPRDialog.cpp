/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "GUIPropertyBeamSPRDialog.h"
#include "ui_GUIPropertyDialog.h"
#include "FITK_Component/FITKRadiossData/FITKPropBeamSPR.h"
#include "GUIPropertyBeamSPR_DOF_Dialog.h"

#include <QComboBox>
#include <QMessageBox>
#include <QCheckBox>

namespace GUI
{
    GUIPropertyBeamSPRDialog::GUIPropertyBeamSPRDialog(Core::FITKActionOperator* oper, Radioss::FITKPropAbstract* obj, QWidget* parent)
        : GUIPropertyDialog(oper, obj, parent)
    {
        _obj = dynamic_cast<Radioss::FITKPropBeamSPR*>(obj);
        if (_obj)
            _isEditMode = true;
        else
            _obj = new Radioss::FITKPropBeamSPR();

        // 初始化
        this->initUI();
        this->init();
    }
    void GUIPropertyBeamSPRDialog::initUI()
    {
        // 清空
        _ui->tableWidgetValue->clear();
        _ui->tableWidgetValue->setRowCount(0);
        // 设置列数
        _ui->tableWidgetValue->setColumnCount(2);
        _ui->tableWidgetValue->setHorizontalHeaderLabels(QStringList{ "Name","Value" });

        if (!_isEditMode) {
            QString name;
            _oper->argValue("AnalysisPropertyName", name);
            _ui->lineEditName->setText(name);
        }
        _ui->lineEditPropertyID->setReadOnly(true);
        _ui->lineEditType->setText("BeamSPR");
        _ui->lineEditType->setReadOnly(true);
        //mass
        this->addLineEdit("Mass", "Mass_LineEdit");
        //inertia
        this->addLineEdit("Inertia", "Inertia_LineEdit");
        //skewID
        QComboBox* comBobox = addComboBox("Skew_ID", "SkewID_Box");
        comBobox->addItem(tr("Global"), 0);
        //sensID
        comBobox = addComboBox("Sensor_Identifier", "Sensor_Box");
        comBobox->addItem(tr("Active"), 0);
        comBobox->addItem(tr("Inactive"), 1);
        //Isflag
        comBobox = addComboBox("Sensor_Flag", "IsFlag_Box");
        comBobox->addItem(tr("Activat when Sensor activates"), 0);
        comBobox->addItem(tr("Inactive when Sensor activates"), 1);
        comBobox->addItem(tr("State matches the Sensor"), 2);
        //Ifail
        comBobox = addComboBox("Failure_Criteria", "Ifail_Box");
        comBobox->addItem(tr("Uni-directional"), 0);
        comBobox->addItem(tr("Multi-directional"), 1);
        //Ileng
        comBobox = addComboBox("Input_Per_Unit_Length", "Ileng_Box");
        comBobox->addItem(tr("Use definition table"), 0);
        comBobox->addItem(tr("Not used definition table"), 1);
        //Ifai2
        comBobox = addComboBox("Failure_Model", "Ifail2_Box");
        comBobox->addItem(tr("Displacement and rotation"), 0);
        comBobox->addItem(tr("Displacement and rotation with velocity"), 1);
        comBobox->addItem(tr("Force and moment"), 2);
        comBobox->addItem(tr("Internal energy"), 3);

        //Tension_Compression
        QPushButton* button = this->addPushButton("Tension_Compression", "Tension Compression Settings");
        connect(button, &QPushButton::clicked, this, [this]() { this->onDOFButtonClicked(Radioss::DOF_SPR::Tension_Compression); });
        //Shear_XY
        button = this->addPushButton("Shear_XY", "Shear XY Settings");
        connect(button, &QPushButton::clicked, this, [this]() { this->onDOFButtonClicked(Radioss::DOF_SPR::Shear_XY); });
        //Shear_XZ
        button = this->addPushButton("Shear_XZ", "Shear XZ Settings");
        connect(button, &QPushButton::clicked, this, [this]() { this->onDOFButtonClicked(Radioss::DOF_SPR::Shear_XZ); });
        //Torsion
        button = this->addPushButton("Torsion", "Torsion Settings");
        connect(button, &QPushButton::clicked, this, [this]() { this->onDOFButtonClicked(Radioss::DOF_SPR::Torsion); });
        //Bending_Y
        button = this->addPushButton("Bending_Y", "Bending Y Settings");
        connect(button, &QPushButton::clicked, this, [this]() { this->onDOFButtonClicked(Radioss::DOF_SPR::Bending_Y); });
        //Bending_Z
        button = this->addPushButton("Bending_Z", "Bending Z Settings");
        connect(button, &QPushButton::clicked, this, [this]() { this->onDOFButtonClicked(Radioss::DOF_SPR::Bending_Z); });

        //v0
        this->addLineEdit("Reference_Velocity", "Reference_Velocity_LineEdit");
        //w0
        this->addLineEdit("Reference_Angular_Velocity", "Reference_Angular_Velocity_LineEdit");
        //Fcut
        this->addLineEdit("Strain_Rate_Cutoff_Frequency", "Strain_Rate_Cutoff_Frequency_LineEdit");
        //Fsmooth
        comBobox = addComboBox("Strain_Rate_Smoothing_Flag", "Strain_Rate_Smoothing_Flag_Box");
        comBobox->addItem(tr("Inactive"), 0);
        comBobox->addItem(tr("Active"), 1);

        //调整宽度
        _ui->tableWidgetValue->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    void GUIPropertyBeamSPRDialog::init()
    {
        Radioss::FITKPropBeamSPR* obj = dynamic_cast<Radioss::FITKPropBeamSPR*>(_obj);
        if (!obj)return;
        Radioss::FITKPropValueBeamSPR* value = obj->getValue();
        if (!value)return;
        if (_isEditMode) {
            _ui->lineEditName->setText(obj->getDataObjectName());
        }
        _ui->lineEditPropertyID->setText(obj->GetFITKPropBeamSPRRadiossKeyWord());
        //mass
        QLineEdit* edit = this->findChild<QLineEdit*>("Mass_LineEdit");
        if (!edit)return;
        edit->setText(QString::number(value->getMass()));
        //inertia
        edit = this->findChild<QLineEdit*>("Inertia_LineEdit");
        if (!edit)return;
        edit->setText(QString::number(value->getInertia()));
        //skewID
        QComboBox* comBobox = this->findChild<QComboBox*>("SkewID_Box");
        if (!comBobox)return;          
        int index = comBobox->findData(value->getSkewID());
        comBobox->setCurrentIndex(index);
        //sensID
        comBobox = this->findChild<QComboBox*>("Sensor_Box");
        if (!comBobox)return;
        index = comBobox->findData(value->getSensID());
        comBobox->setCurrentIndex(index);
        //Isflag
        comBobox = this->findChild<QComboBox*>("IsFlag_Box");
        if (!comBobox)return;
        index = comBobox->findData(value->getIsflag());
        comBobox->setCurrentIndex(index);
        //Ifail
        comBobox = this->findChild<QComboBox*>("Ifail_Box");
        if (!comBobox)return;
        index = comBobox->findData(value->getIfail());
        comBobox->setCurrentIndex(index);
        //Ileng
        comBobox = this->findChild<QComboBox*>("Ileng_Box");
        if (!comBobox)return;
        index = comBobox->findData(value->getIleng());
        comBobox->setCurrentIndex(index);
        //Ifail2
        comBobox = this->findChild<QComboBox*>("Ifail2_Box");
        if (!comBobox)return;
        index = comBobox->findData(value->getIfail2());
        comBobox->setCurrentIndex(index);
        //v0
        edit = this->findChild<QLineEdit*>("Reference_Velocity_LineEdit");
        if (!edit)return;
        edit->setText(QString::number(value->getV0()));
        //w0
        edit = this->findChild<QLineEdit*>("Reference_Angular_Velocity_LineEdit");
        if (!edit)return;
        edit->setText(QString::number(value->getW0()));
        //Fcut
        edit = this->findChild<QLineEdit*>("Strain_Rate_Cutoff_Frequency_LineEdit");
        if (!edit)return;
        edit->setText(QString::number(value->getFcut()));
        //Fsmooth
        comBobox = this->findChild<QComboBox*>("Strain_Rate_Smoothing_Flag_Box");
        if (!comBobox)return;
        index = comBobox->findData(value->getFsmooth());
        comBobox->setCurrentIndex(index);

    }
    bool GUIPropertyBeamSPRDialog::ckeckData()
    {
        //获取名称，查重处理
        auto mgr = this->getSectionManager();
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
    void GUIPropertyBeamSPRDialog::getDataFormWidget()
    {
        Radioss::FITKPropBeamSPR* obj = dynamic_cast<Radioss::FITKPropBeamSPR*>(_obj);
        if (!obj)return;
        Radioss::FITKPropValueBeamSPR* value = obj->getValue();
        if (!value)return;
        //mass
        QLineEdit* edit = this->findChild<QLineEdit*>("Mass_LineEdit");
        if (!edit)return;
        value->setMass(edit->text().toDouble());
        //inertia
        edit = this->findChild<QLineEdit*>("Inertia_LineEdit");
        if (!edit)return;
        value->setInertia(edit->text().toDouble());
        //skewID
        QComboBox* comBobox = this->findChild<QComboBox*>("SkewID_Box");
        if (!comBobox)return;
        value->setSkewID(comBobox->currentData().toInt());
        //sensID
        comBobox = this->findChild<QComboBox*>("Sensor_Box");
        if (!comBobox)return;
        value->setSensID(comBobox->currentData().toInt());
        //Isflag
        comBobox = this->findChild<QComboBox*>("IsFlag_Box");
        if (!comBobox)return;
        value->setIsflag(comBobox->currentData().toInt());
        //Ifail
        comBobox = this->findChild<QComboBox*>("Ifail_Box");
        if (!comBobox)return;
        value->setIfail(comBobox->currentData().toInt());
        //Ileng
        comBobox = this->findChild<QComboBox*>("Ileng_Box");
        if (!comBobox)return;
        value->setIleng(comBobox->currentData().toInt());
        //Ifail2
        comBobox = this->findChild<QComboBox*>("Ifail2_Box");
        if (!comBobox)return;
        value->setIfail2(comBobox->currentData().toInt());
        //v0
        edit = this->findChild<QLineEdit*>("Reference_Velocity_LineEdit");
        if (!edit)return;
        value->setV0(edit->text().toDouble());
        //w0
        edit = this->findChild<QLineEdit*>("Reference_Angular_Velocity_LineEdit");
        if (!edit)return;
        value->setW0(edit->text().toDouble());
        //Fcut
        edit = this->findChild<QLineEdit*>("Strain_Rate_Cutoff_Frequency_LineEdit");
        if (!edit)return;
        value->setFcut(edit->text().toDouble());
        //Fsmooth
        comBobox = this->findChild<QComboBox*>("Strain_Rate_Smoothing_Flag_Box");
        if (!comBobox)return;
        value->setFsmooth(comBobox->currentData().toInt());

    }

    QPushButton* GUIPropertyBeamSPRDialog::addPushButton(const QString& label, const QString& buttonText)
    {
        int row = _ui->tableWidgetValue->rowCount();
        _ui->tableWidgetValue->insertRow(row);
        QTableWidgetItem* item = new QTableWidgetItem(label);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        _ui->tableWidgetValue->setItem(row, 0, item);

        QPushButton* button = new QPushButton(buttonText);
        _ui->tableWidgetValue->setCellWidget(row, 1, button);
        return button;
    }

    void GUIPropertyBeamSPRDialog::onDOFButtonClicked(int Type)
    {
        Radioss::FITKPropBeamSPR* obj = dynamic_cast<Radioss::FITKPropBeamSPR*>(_obj);
        if (!obj)return;
        Radioss::FITKPropValueBeamSPR* value = obj->getValue();
        if (!value)return;
        Radioss::ValueDOF& dofValue = value->getValueDOF(static_cast<Radioss::DOF_SPR>(Type));
        GUIPropertyBeamSPR_DOF_Dialog* dlg = new GUIPropertyBeamSPR_DOF_Dialog(dofValue, this);
        dlg->exec();
    }
}