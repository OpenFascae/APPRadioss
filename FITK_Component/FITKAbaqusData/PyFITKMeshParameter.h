/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

/**
 * @file PyFITKMeshParameter.h
 * @brief 网格操作 为python装饰器接口准备的封装类
 * @author wangning (2185896382@qq.com)
 * @date 2025-07-04
 */
#ifndef _PY_FITKMeshBehavior_H___
#define _PY_FITKMeshBehavior_H___

#include <QString>
#include "FITKAbaqusDataAPI.h"
#include "FITK_Interface/FITKInterfaceGeometry/FITKAbsGeoCommand.h"

namespace AbaqusData
{
    class FITKSurfaceMeshingParameter;
    class FITKVolumeMeshingParameter;
    class FITKAbaqusPart;
    /**
     * @brief 网格操作
     * @author wangning (2185896382@qq.com)
     * @date 2025-07-04
     */
    class FITKAbaqusDataAPI PyFITKMeshParameter
    {
    public:
        explicit PyFITKMeshParameter(FITKAbaqusPart* part);
        virtual ~PyFITKMeshParameter() = default;
        /**
         * @brief  设置体划分类型
         * @param[i] index块索引，ElementType划分类型
         * @author wangning (2185896382@qq.com)
         * @date   2025-07-04
         */
        bool setVolumeEleType(const QList<int>& indexs, int ElementType );
        /**
         * @brief  设置面划分类型
         * @param[i] index面索引，ElementType划分类型
         * @author wangning (2185896382@qq.com)
         * @date   2025-07-04
         */
        bool setSurfaceEleType(const QList<int>& indexs, int ElementType);
        /**
         * @brief  设置全局种子点尺寸
         * @param[i] size网格尺寸
         * @author wangning (2185896382@qq.com)
         * @date   2025-07-04
         */
        bool setSeedGlobalSize(double size);
        /**
         * @brief  移除全局种子点尺寸
         * @author wangning (2185896382@qq.com)
         * @date   2025-07-04
         */
        bool removeSeedGlobalSize();
        /**
         * @brief  设置局部种子点尺寸（通过尺寸）
         * @param[i] indexs边索引 size网格尺寸 curSeedBias布种方式(0到2) curSeedCon限制条件(0到2)
         * @author wangning (2185896382@qq.com)
         * @date   2025-07-04
         */
        bool setSeedLocalBySize(const QList<int>& indexs,double size,int curSeedBias = 0, int curSeedCon = 2);
        /**
         * @brief  设置局部种子点尺寸（通过一条边的单元划分数量）
         * @param[i] indexs边索引 num一条边的单元数量 curSeedBias布种方式(0到2) curSeedCon限制条件(0到2) biasRatio偏心率
         * @author wangning (2185896382@qq.com)
         * @date   2025-07-04
         */
        bool setSeedLocalByNum(const QList<int>& indexs, int eleNum, int curSeedBias=0, int curSeedCon=2, double biasRatio=5.0);
        /**
        * @brief  移除局部种子点尺寸
        * @param[i] indexs边索引
        * @author wangning (2185896382@qq.com)
        * @date   2025-07-04
        */
        bool removeSeedLocalSize(const QList<int>& indexs);

    private:
        /**
        * @brief  通过边索引获取虚拓扑链表
        * @param[i]cmdID几何命令ID index特征索引 type类型
        * @author wangning (2185896382@qq.com)
        * @date   2025-06-25
        */
        QList<Interface::VirtualShape> getShapes(const QList<int>& indexs);

    private:
        /**
        * @brief  部件
        * @author wangning (2185896382@qq.com)
        * @date   2025-07-04
        */
        FITKAbaqusPart* _part{};

    };
}

#endif

