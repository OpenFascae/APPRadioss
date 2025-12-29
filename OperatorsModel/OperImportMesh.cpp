/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "OperImportMesh.h"
#include "MeshImporterNastran.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKComponents.h"
#include "FITK_Kernel/FITKAppFramework/FITKMessage.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppSettings.h" 
#include "FITK_Kernel/FITKCore/FITKThreadPool.h"

#include "OperatorsInterface/GraphEventOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "OperatorsInterface/TreeEventOperator.h"

#include <QFile>
#include <QFileDialog>

namespace ModelOper
{

    bool FITKOperatorImportMesh::execGUI()
    {
        //主界面
        QWidget* mw = FITKAPP->getGlobalData()->getMainWindow();
        //获取工作目录
        QString wk;
        auto settings = FITKAPP->getAppSettings();
        if (settings)
            wk = settings->getWorkingDir();
        // QString fileName = QFileDialog::getOpenFileName(mw, QObject::tr("Open INP File"),"" , "INP(*.inp)");

        QFileDialog dlg(mw, QObject::tr("Import Mesh File"), wk, "Nastran Files(*.bdf *.nas)");
        dlg.setAcceptMode(QFileDialog::AcceptOpen);  //打开模式
        dlg.show();
        
        //阻塞，否则键盘事件处理会出问题
        bool accept = false;
        QEventLoop loop;
        connect(&dlg, &QFileDialog::accepted, [&] {loop.quit(); accept = true;  });
        connect(&dlg, &QFileDialog::rejected, [&] {loop.quit(); accept = false;  });
        loop.exec();

        if (!accept) return false;
        QStringList files = dlg.selectedFiles(); //选择的文件名称
        if (files.isEmpty()) return false;
        QString fileName = files.at(0);

        if (fileName.isEmpty())
            return false;
        //存储信息
        if (_emitter == nullptr) return false;

        this->setArgs("FileName", fileName);
        return true;
    }   


    bool FITKOperatorImportMesh::execProfession()
    {
        QString fileName;
        bool ok = this->argValue<QString>("FileName", fileName);
        if (!ok) return false;
        QFileInfo finfo(fileName); 
        if (!finfo.exists()) return false;
        const QString suffix = finfo.suffix().toLower();

        //输出信息
        AppFrame::FITKMessageNormal(QString(tr("Reading mesh file %1 ...")).arg(fileName));
        
        Core::FITKThreadPool::getInstance()->wait(); //等待之前的任务完成

        if(suffix == "bdf" || suffix == "nas")
        {
            //读取Nastran网格文件
            ModelOper::FITKNastranMeshImporter* importor = new ModelOper::FITKNastranMeshImporter();
            
            importor->setFileName(fileName);
            connect(importor, &Core::FITKThreadTask::taskFinishedSig, this, &FITKOperatorImportMesh::ioThreadFinishedSlot);
            Core::FITKThreadPool::getInstance()->execTask(importor);
        }

        //读写组件获取
    }


    void FITKOperatorImportMesh::ioThreadFinishedSlot()
    {
         //获取Radioss IO接口
        EventOper::GraphEventOperator* graphOper = FITKOPERREPO->getOperatorT<EventOper::GraphEventOperator>("GraphPreprocess");
        if (!graphOper) return;
        graphOper->updateAllModel(false);
         
        // 通过树形菜单事件处理器刷新树
        QStringList listOperator = { "TreeAssemblyEvent", "TreeGroupEvent" ,"TreePropertyEvent","TreeSolutionEvent" };
        for (int i = 0; i < listOperator.size(); i++)
        {
            EventOper::TreeEventOperator* oper = dynamic_cast<EventOper::TreeEventOperator*>(Core::FITKOperatorRepo::getInstance()->getOperator(listOperator[i]));
            if (oper != nullptr)
            {
                oper->updateTree();
                // 通过模拟双击事件删除数据
                if (listOperator[i] == "PartTreeEvent") oper->on_itemDoubleClicked(nullptr, nullptr, 0);
            }
        }

    }



    FITKAbstractMeshImporter::FITKAbstractMeshImporter(QObject *parent)
        : FITKThreadTask(parent)
    {
        Q_UNUSED(parent);
    }
    
    FITKAbstractMeshImporter::~FITKAbstractMeshImporter()
    {}

    void FITKAbstractMeshImporter::setFileName(const QString& fileName)
    {
        _fileName = fileName;
    }

}