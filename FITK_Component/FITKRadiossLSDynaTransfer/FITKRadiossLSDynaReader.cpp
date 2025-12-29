/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "FITKRadiossLSDynaReader.h"
#include "FITK_Kernel/FITKAppFramework/FITKMessage.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"

namespace Radioss
{
    FITKRadiossLSDynaReader::FITKRadiossLSDynaReader(bool & success)
        : _success(success)
    {
    }

    void FITKRadiossLSDynaReader::run()
    {
        // 执行读取操作
        //获取算例数据
        Radioss::FITKRadiossCase* caseData = dynamic_cast<Radioss::FITKRadiossCase*>(_data);
        if (!caseData)
        {
            consoleMessage(3, "Failed to get Radioss case data.");
            _success = false;
            return;
        }

        //todo: 读取key文件内容
    }

    void FITKRadiossLSDynaReader::consoleMessage(int level, const QString& str)
    {
        // 打印控制台消息
        switch (level)
        {
        case 1:
            AppFrame::FITKMessageNormal(str);
            break;
        case 2:
            AppFrame::FITKMessageWarning(str);
            break;
        case 3:
            AppFrame::FITKMessageError(str);
            break;
        default:
            AppFrame::FITKMessageError(str);
            break;
        }
    }
}
