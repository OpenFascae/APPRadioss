/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "GUIRigidWallPlaneDialog.h"
#include "ui_GUIRigidWallDialog.h"

#include "FITK_Component/FITKRadiossData/FITKRWall.h"

#include <QMessageBox>

namespace GUI
{
    GUIRigidWallPlaneDialog::GUIRigidWallPlaneDialog(Radioss::FITKAbstractRWall* obj, Core::FITKActionOperator* oper, QWidget* parent)
        : GUIRigidWallDialog(obj, oper, parent)
    {
        QString RigidWalllName;
        _oper->argValue("RigidWallName", RigidWalllName);
        if (!_obj) {
            _ui->lineEdit_name->setReadOnly(true);
            setWindowTitle(tr("Create Rigid Wall"));
        }
        else
        {
            setWindowTitle(tr("Edit Rigid Wall"));
        }

        _ui->label_7->hide();
        _ui->lineEdit_diameter->hide();
        _ui->groupBox_2->setTitle(tr("Tool Point"));
        this->init();
    }

    bool GUIRigidWallPlaneDialog::ckeckData()
    {
        //获取名称，查重处理
        QString name = _ui->lineEdit_name->text();
        if (name.isEmpty()) {
            QMessageBox::warning(this, "", tr("Name cannot be empty."), QMessageBox::Ok);
            return false;
        }
        else if (_mgr->getDataByName(name) && name != _obj->getDataObjectName()) {
            QMessageBox::warning(this, "", tr("\"%1\" The name already exists").arg(name), QMessageBox::Ok);
            return false;
        }
        if (_ui->lineEdit_X_2->text().toDouble() == 0 && _ui->lineEdit_Y_2->text().toDouble() == 0 && _ui->lineEdit_Z_2->text().toDouble() == 0)
        {
            QMessageBox::warning(this, "", tr("Invalid Tool Point"), QMessageBox::Ok);
            return false;
        }
        return true;
    }
    void GUIRigidWallPlaneDialog::init()
    {
        _ui->lineEdit->setReadOnly(true);
        _ui->lineEdit_model->setReadOnly(true);
        //设置key word
        _ui->lineEdit->setText(Radioss::FITKRWallPlane::GetFITKRWallPlaneRadiossKeyWord());
        //设置类型
        _ui->lineEdit_model->setText("PLANE");
        if (_isCreate)
        {
            QString rigidWalllName;
            _oper->argValue("RigidWallName", rigidWalllName);
            _ui->lineEdit_name->setReadOnly(true);
            _ui->lineEdit_name->setText(rigidWalllName);
        }
        else
        {
            Radioss::FITKRWallPlane* plane = dynamic_cast<Radioss::FITKRWallPlane*>(_obj);
            if (!plane) return;
            //设置名称
            _ui->lineEdit_name->setText(plane->getDataObjectName());
            Radioss::FITKAbstractRWall::RWallSliding slidingType = plane->getSlidingType();
            if (slidingType == Radioss::FITKAbstractRWall::RWallSliding::Sliding)
                _ui->comboBox_Sliding->setCurrentIndex(0);
            else if (slidingType == Radioss::FITKAbstractRWall::RWallSliding::Tied)
                _ui->comboBox_Sliding->setCurrentIndex(1);
            else if (slidingType == Radioss::FITKAbstractRWall::RWallSliding::SlidingWithFriction)
                _ui->comboBox_Sliding->setCurrentIndex(2);

            int nodeId = plane->getNodeId();
            int nodeGroupId1 = plane->getNodeGroupId1();
            int nodeGroupId2 = plane->getNodeGroupId2();
            double DSearch = plane->getDSearch();
            double frictionCoef = plane->getFrictionCoef();
            double diameter = plane->getDiameter();
            double filteringFactor = plane->getFilteringFactor();
            int filteringFlag = plane->getFilteringFlag();
            double coordinatesM[3] = {};
            plane->getBasicPoint(coordinatesM[0], coordinatesM[1], coordinatesM[2]);
            double coordinatesM1[3] = {};
            plane->getNormalVector(coordinatesM1[0], coordinatesM1[1], coordinatesM1[2]);

            _ui->lineEdit_nodeID->setText(QString::number(nodeId));
            _ui->lineEdit_SearchDistance->setText(QString::number(DSearch));
            _ui->lineEdit_frictionCoef->setText(QString::number(frictionCoef));
            _ui->lineEdit_diameter->setText(QString::number(diameter));
            _ui->lineEdit_filteringFactor->setText(QString::number(filteringFactor));
            _ui->lineEdit_filtingFlag->setText(QString::number(filteringFlag));
            _ui->lineEdit_X->setText(QString::number(coordinatesM[0]));
            _ui->lineEdit_Y->setText(QString::number(coordinatesM[1]));
            _ui->lineEdit_Z->setText(QString::number(coordinatesM[2]));
            _ui->lineEdit_X_2->setText(QString::number(coordinatesM1[0] + coordinatesM[0]));
            _ui->lineEdit_Y_2->setText(QString::number(coordinatesM1[1] + coordinatesM[1]));
            _ui->lineEdit_Z_2->setText(QString::number(coordinatesM1[2] + coordinatesM[2]));
            _nodeGroup1->findNodeGroup(nodeGroupId1);
            _nodeGroup2->findNodeGroup(nodeGroupId2);
        }
    }
    void GUIRigidWallPlaneDialog::getDataFormWidget()
    {
        if (_isCreate)
        {
            _obj = new Radioss::FITKRWallPlane();

        }
        Radioss::FITKRWallPlane* plane = dynamic_cast<Radioss::FITKRWallPlane*>(_obj);
        if (!plane) return;

        int nodeId = _ui->lineEdit_nodeID->text().toInt();
        int nodeGroupId1 = _nodeGroup1->getNodeGroupId();
        int nodeGroupId2 = _nodeGroup2->getNodeGroupId();
        double DSearch = _ui->lineEdit_SearchDistance->text().toDouble();
        double frictionCoef = _ui->lineEdit_frictionCoef->text().toDouble();
        double diameter = _ui->lineEdit_diameter->text().toDouble();
        double filteringFactor = _ui->lineEdit_filteringFactor->text().toDouble();
        int filteringFlag = _ui->lineEdit_filtingFlag->text().toInt();
        double coordinatesM[3] = { _ui->lineEdit_X->text().toDouble(),
                                   _ui->lineEdit_Y->text().toDouble(),
                                   _ui->lineEdit_Z->text().toDouble(), };
        double coordinatesM1[3] = { _ui->lineEdit_X_2->text().toDouble() - _ui->lineEdit_X->text().toDouble(),
                                   _ui->lineEdit_Y_2->text().toDouble() - _ui->lineEdit_Y->text().toDouble(),
                                   _ui->lineEdit_Z_2->text().toDouble() - _ui->lineEdit_Z->text().toDouble(), };
        plane->setNodeId(nodeId);
        plane->setNodeGroupId1(nodeGroupId1);
        plane->setNodeGroupId2(nodeGroupId2);
        plane->setDSearch(DSearch);
        plane->setFrictionCoef(frictionCoef);
        plane->setDiameter(diameter);
        plane->setFilteringFactor(filteringFactor);
        plane->setFilteringFlag(filteringFlag);
        plane->setBasicPoint(coordinatesM[0], coordinatesM[1], coordinatesM[2]);
        plane->setNormalVector(coordinatesM1[0], coordinatesM1[1], coordinatesM1[2]);

        if (_ui->comboBox_Sliding->currentData().toInt() == 0)
        {
            plane->setSlidingType(Radioss::FITKAbstractRWall::RWallSliding::Sliding);
        }
        else if (_ui->comboBox_Sliding->currentData().toInt() == 1)
        {
            plane->setSlidingType(Radioss::FITKAbstractRWall::RWallSliding::Tied);
        }
        else if (_ui->comboBox_Sliding->currentData().toInt() == 2)
        {
            plane->setSlidingType(Radioss::FITKAbstractRWall::RWallSliding::SlidingWithFriction);
        }
    }

}