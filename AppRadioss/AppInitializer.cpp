/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "AppInitializer.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKComponents.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKRunTimeSetting.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"
#include <QMessageBox>
#include <QFile>

bool AppInitializer::init()
{
    bool isInitFinish = true;
    //初始化软件运行时的配置
    this->initRunTimeSetting();

    return isInitFinish;
}

void AppInitializer::initRunTimeSetting()
{
    AppFrame::FITKGlobalData* globalData = FITKAPP->getGlobalData();
    if (!globalData) return;
    //获取运行时的设置
    AppFrame::FITKRunTimeSetting* runTimeSetting = globalData->getRunTimeSetting();
    if (!runTimeSetting) return;
    //设置软件运行时的初始化配置
    runTimeSetting->setValue("GeoPoint", true);
    runTimeSetting->setValue("GeoLine", true);
    runTimeSetting->setValue("Geo", true);
    runTimeSetting->setValue("MeshPoint", true);
    runTimeSetting->setValue("MeshLine", true);
    runTimeSetting->setValue("Part", true);
}

