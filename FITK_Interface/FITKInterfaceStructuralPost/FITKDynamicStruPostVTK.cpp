/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "FITKDynamicStruPostVTK.h"
#include "FITKStruPostMessageText.h"

#include <QFile>
#include <QFileInfo>
#include <QCollator>

#include <vtkDataSetReader.h>

namespace Interface
{
    FITKDynamicStruPostVTK::FITKDynamicStruPostVTK(StruPostFileType type):
        FITKAbstractStructuralPostVTK(type)
    {
    }

    FITKDynamicStruPostVTK::~FITKDynamicStruPostVTK()
    {
    }

    StruPostType FITKDynamicStruPostVTK::getPostStructualType()
    {
        //显式分析
        return SPTDynamicExplict;
    }

    void FITKDynamicStruPostVTK::setFiles(const QStringList & files)
    {
        //文件列表
        _fileList = files;

        //对文件排序
        QCollator collator;
        collator.setNumericMode(true);
        std::sort(_fileList.begin(), _fileList.end(),
            [&collator](const QString & str1, const QString & str2)
            {
                return collator.compare(str1, str2) < 0;
            });
        if (_fileList.isEmpty()) return;

        this->setFileIndex(_fileList.size() - 1);

        // 初始化显示分组All。
        this->resetDisplayGroup();
    }

    void FITKDynamicStruPostVTK::nextFrame()
    {
        //当前文件索引
        const int index = this->getFileIndex();
        //正确性判断
        if ( index + 1 < 0 || index +1 >= _fileList.size() ) return;
        this->setFileIndex(index + 1);
    }

    void FITKDynamicStruPostVTK::previousFrame()
    {
        //当前文件索引
        const int index = this->getFileIndex();
        //正确性判断
        if (index - 1 < 0 || index - 1 >= _fileList.size()) return;
        this->setFileIndex(index - 1);
    }

    void FITKDynamicStruPostVTK::firstFrame()
    {
        //当前文件索引
        const int index = this->getFileIndex();
        //已经是第一个
        if (index == 0) return;
        this->setFileIndex(0);
    }

    void FITKDynamicStruPostVTK::lastFrame()
    {
        //当前文件索引
        const int index = this->getFileIndex();
        //已经是最后一个
        if (index == _fileList.size()-1) return;
        this->setFileIndex(_fileList.size() - 1);
    }

    void FITKDynamicStruPostVTK::setCurFrame(int curFrame)
    {
        if (curFrame >= _fileList.size() || curFrame < 0) {
            return;
        }
        //当前文件索引
        const int index = this->getFileIndex();
        if(curFrame == index){
            return;
        }
        this->setFileIndex(curFrame);
    }

    int FITKDynamicStruPostVTK::frameNum()
    {
        return _fileList.size();
    }

    int FITKDynamicStruPostVTK::getCurFrame()
    {
        return this->getFileIndex();
    }

    void FITKDynamicStruPostVTK::updateText()
    {
        if (_textData) {
            QString filePath = (getInputFile());
            QFile file(filePath);
            QFileInfo fileInfo(file);
            QString fileName = fileInfo.fileName();
            //QString message = QString("VTK: %1  \nStep: %2  \nIncrement %3  \nStep Time = %4").arg(fileName).arg("").arg("").arg("").arg("");
            QString message = QString("VTK: %1 ").arg(fileName);
            _textData->setText(message);
        }
    }

    void FITKDynamicStruPostVTK::setFileIndex(const int index)
    {
        if (index >= _fileList.size() || index < 0) return;
        const QString f = _fileList.at(index);
        if (!QFile::exists(f)) return;
        this->setInputFile(f);
    }

    int FITKDynamicStruPostVTK::getFileIndex()
    {
        QString currentFile = this->getInputFile();
        return _fileList.indexOf(currentFile);
    }

}



