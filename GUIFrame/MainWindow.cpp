/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ActionEventHandler.h"
#include "CentralWidget.h"
#include "MessageTableWidget.h"
#include "SARibbonBarHelper.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "GUIWidget/ControlPanel.h"
#include "GUIWidget/ParamWidget.h"

#include <QAction>
#include <QPushButton>
#include <QList>
#include <QSplitter>
#include <QProgressBar>
#include <QToolBar>


namespace GUI
{
    MainWindow::MainWindow(QWidget *parent) : SARibbonMainWindow(parent)
    {
        //创建UI对象
        _ui = new Ui::MainWindow;
        _ui->setupUi(this);
        //初始化Ribbon        
        _ribbonBarHelper = new SARibbonBarHelper(this);
        _ribbonBarHelper->initRibbonBar();

        //连接信号槽
        m_ActionHandler = new ActionEventHandler();
        QList<QAction*> actionList = this->findChildren<QAction*>();
        for (QAction* action : actionList)
        {
            if (action == nullptr)continue;
            connect(action, SIGNAL(triggered()), this->getActionEventHandle(), SLOT(execOperator()));
        }

        //初始化窗口
        this->initWindow();
        this->setWindowTitle("FastCAE-OpenRadioss");
    }

    MainWindow::~MainWindow()
    {
        if (m_ActionHandler) delete m_ActionHandler;
        if (_ribbonBarHelper) delete _ribbonBarHelper;
        if (_ui) delete _ui;
    }

    ActionEventHandler * MainWindow::getActionEventHandle() const
    {
        return m_ActionHandler;
    }

    MainWindow* MainWindow::GetMainWindowFromFramework()
    {
        //访问全局数据
        AppFrame::FITKGlobalData* data = FITKAPP->getGlobalData();
        if (data == nullptr) return nullptr;
        QWidget* w = data->getMainWindow();
        //强制类型转换
        return dynamic_cast<MainWindow*>(w);
    }

    GUI::CentralWidget* MainWindow::getCentralWidget()
    {
        return _centralWidget;
    }

    void MainWindow::setProgressValue(int value)
    {
        if (_progerssBar == nullptr) return;
        //设置进度值
        _progerssBar->setValue(value);
        //设置可见性 只有在(0,100) 区间可见
        _progerssBar->setVisible(value < 100 && value > 0);
    }

    GUI::ControlPanel* MainWindow::getControlPanel()
    {
        return _controlPanel;
    }

    ModelLayerPanel * MainWindow::getModelLayerPanel()
    {
        return _modelLayerPanel;
    }

    //QWidget* MainWindow::getCurrentPropWidget()
    //{
    //    if (_controlPanel == nullptr) return nullptr;
    //    GUI::ParamWidget* pw = _controlPanel->getParamWidget();
    //    if (pw == nullptr) return nullptr;
    //    return pw->getCurrentWidget();
    //}

    SARibbonBarHelper * MainWindow::getRibbonBarHelper() const
    {
        return _ribbonBarHelper;
    }

    void MainWindow::initWindow()
    {
        // 子部件水平排布
        QSplitter *spliterLayout = new QSplitter(Qt::Vertical, this);
        spliterLayout->setMouseTracking(true);
        spliterLayout->setHandleWidth(5);
        spliterLayout->setSizes({ 20000, 6000 });// 设置大小
        //left dock widget
        _controlPanel = new ControlPanel(this);
        this->addDockWidget(Qt::LeftDockWidgetArea, _controlPanel);
         
        QList<QDockWidget*> docks{ _controlPanel };
        QList<int> sizes{ 500 };               // 期望的像素宽度
        this->resizeDocks(docks, sizes, Qt::Horizontal);

        //central mdi area
        _centralWidget = new CentralWidget(this);
        spliterLayout->addWidget(_centralWidget);

        //message widget
        _messageTab = new MessageTabWidget(this);
        spliterLayout->addWidget(_messageTab);

        //add spliterLayout
        this->setCentralWidget(spliterLayout);

        //进度条
        _progerssBar = new QProgressBar(this);
        _progerssBar->setRange(0, 100);
        this->statusBar()->addPermanentWidget(_progerssBar);
        this->setProgressValue(0);
    }



}
