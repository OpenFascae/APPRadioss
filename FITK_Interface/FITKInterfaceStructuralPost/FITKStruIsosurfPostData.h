/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

/*****************************************************************//**
 * @file   FITKStruIsosurfPostData.h
 * @brief  后处理等值面数据类
 *
 * @author WuYizhen (wyz_hanhan@163.com)
 * @date   2025-12-22
 *********************************************************************/

#ifndef _FITKStruIsosurfPostData_H_
#define _FITKStruIsosurfPostData_H_

#include "FITKInterfaceStructuralPostAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractNDataObject.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITKAbstractStruPostVTK.h"


class vtkContourFilter;
class vtkAlgorithmOutput;
class vtkTrivialProducer;

namespace Interface {
    /**
     * @brief  后处理等值面数据类
     * @author WuYizhen (wyz_hanhan@163.com)
     * @date   2025-12-22
     */
    class FITKInterfaceStructuralPostAPI FITKStruIsosurfPostData : public Core::FITKAbstractNDataObject {
        FITKCLASS(Interface, FITKStruIsosurfPostData);
        Q_OBJECT;
    public:
        /**
         * @brief    构造函数
         * @param[i] 父对象ID
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        FITKStruIsosurfPostData();

        /**
         * @brief    析构函数
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        virtual ~FITKStruIsosurfPostData();

        /**
         * @brief    设置变量名称
         * @param[i] 变量名称
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void setFileName(const QString fileName);

        /**
         * @brief    获取变量名称
         * @return   变量名称
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        QString getFileName();

        /**
         * @brief    设置变量类型
         * @param[i] 变量类型
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void setType(const VariableLocation type);

        /**
         * @brief    获取变量类型
         * @return   变量类型
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        VariableLocation getType();

        /**
         * @brief    设置数据
         * @param[i] 数据
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void setValue(QList < double > value);

        /**
         * @brief    获取数据
         * @return   数据
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        QList<double> getValue();

        /**
         * @brief    获取数据对象
         * @return   数据对象
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        virtual vtkDataSet* getOutput();
        /**
         * @brief    获取算法输出
         * @return   算法输出
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        virtual vtkAlgorithmOutput* getOutputAlgorithm();

        /**
         *
         */
        virtual StruPostType getPostStructualType();

        /**
         * @brief    设置算法输入
         * @param[i] 算法输入
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void setInput(vtkDataSet* inp);

        /**
         * @brief    设置模型ID
         * @param[i] 模型ID
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void setModelID(int modelId);

        /**
         * @brief    获取模型ID
         * @return   模型ID
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        int getModelID();

        void update();

    private:
        /**
         * @brief    过滤器对象
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        vtkContourFilter* _contourFilter = nullptr;

        /**
         * @brief    数据数量
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        int _valueSize = 0;

        /**
         * @brief    变量名称
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        QString _fileName = "";

        /**
         * @brief    模型ID
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        int _modelID = -1;

        /**
         * @brief    变量类型
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        VariableLocation _fileType = VariableLocation::VALOCNode;

        vtkTrivialProducer* _producer = nullptr;

        vtkDataSet* _inp = nullptr;

        QList<double> _values;
    };
}

namespace Interface {
    class FITKInterfaceStructuralPostAPI FITKStruIsoPostDataManager :
        public Core::FITKAbstractDataManager<FITKStruIsosurfPostData> {
    public:
        /**
         * @brief    构造函数
         * @param[i] 后处理数据对象
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        explicit FITKStruIsoPostDataManager(FITKAbstractStructuralPostVTK* absPost);

        /**
         * @brief    析构函数
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        virtual ~FITKStruIsoPostDataManager() = default;

        /**
         * @brief    追加对象
         * @param[i] 对象
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void appendDataObj(Core::FITKAbstractDataObject* item) override;

        /**
         * @brief    插入对象
         * @param[i] 对象
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        void insertDataObj(int idx, Core::FITKAbstractDataObject* item) override;

    private:
        /**
         * @brief    管理可视化对象数据
         * @author   WuYizhen (wyz_hanhan@163.com)
         * @date     2025-12-22
         */
        FITKAbstractStructuralPostVTK* _postObj{};
    };
}

#endif // !_FITKStruIsosurfPostData_H_

