/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "FITKRadiossAbstractAdaptor.h"

namespace Radioss
{
    QHash<QString, std::function<FITKRadiossAbstractAdaptor*()>> FITKRadiossAbstractAdaptor::_adaptorCreators
        = QHash<QString, std::function<FITKRadiossAbstractAdaptor*()>>();

    FITKRadiossAbstractAdaptor::~FITKRadiossAbstractAdaptor()
    {
    }

    void FITKRadiossAbstractAdaptor::setFileReader(FITKRadiossRadReader * reader)
    {
        //设置读取器
        _reader = reader;
    }

    void FITKRadiossAbstractAdaptor::setFileWriter(FITKRadiossRadWriter * writer)
    {
        //设置写入器
        _writer = writer;
    }

    void FITKRadiossAbstractAdaptor::setCaseData(FITKRadiossCase * casedata)
    {
        //设置案例数据
        _caseData = casedata;
    }

    void FITKRadiossAbstractAdaptor::registerAdaptor(const QString &keywords, 
        std::function<FITKRadiossAbstractAdaptor*()> creator)
    {
        //注册适配器
        _adaptorCreators.insert(keywords.toUpper(), creator);
    }

    FITKRadiossAbstractAdaptor* FITKRadiossAbstractAdaptor::createAdaptor(const QString & keywords)
    {
        std::function<FITKRadiossAbstractAdaptor*()> creator = _adaptorCreators.value(keywords.toUpper());
        if (creator)
        {
            return creator();
        }
        return nullptr;
    }


}
