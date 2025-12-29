/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

/*****************************************************************//**
 * @file        FITKGlobalMeshingParameter.h
 * @brief       通用网格划分参数。
 *
 * @author      ChengHaotian (yeguangbaozi@foxmail.com)
 * @date        2025-08-27
 *********************************************************************/

#ifndef __FITKGLOBALMESHINGPARAMETER__H__
#define __FITKGLOBALMESHINGPARAMETER__H__

#include "FITKAbaqusDataAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"

#include <QObject>
#include <QMetaEnum>

namespace AbaqusData
{
    /**
     * @brief       通用网格划分参数。
     * @author      ChengHaotian (yeguangbaozi@foxmail.com)
     * @date        2025-08-27
     */
    class FITKAbaqusDataAPI FITKGlobalMeshingParameter : public Core::FITKAbstractDataObject
    {
        Q_OBJECT;
    public:
        /**
         * @brief       网格单元类型。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        enum ElementType2D3D
        {
            ET_Quad = 0,
            ET_Tri
        };
        Q_ENUM(ElementType2D3D);

    public:
        /**
         * @brief       构造函数。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        explicit FITKGlobalMeshingParameter() = default;

        /**
         * @brief       析构函数。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        virtual ~FITKGlobalMeshingParameter() = default;

        /**
         * @brief       设置网格尺寸因子。
         * @param[in]   fac：尺寸因子
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        void setMeshSizeFactor(double fac);

        /**
         * @brief       获取网格尺寸因子。
         * @return      尺寸因子
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        double getMeshSizeFactor();

        /**
         * @brief       设置最小网格尺寸。
         * @param[in]   size：尺寸
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        void setMinMeshSize(double size);

        /**
         * @brief       获取最小网格尺寸。
         * @return      尺寸
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        double getMinMeshSize();

        /**
         * @brief       设置最大网格尺寸。
         * @param[in]   size：尺寸
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        void setMaxMeshSize(double size);

        /**
         * @brief       获取最大网格尺寸。
         * @return      尺寸
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        double getMaxMeshSize();

        /**
         * @brief       设置高阶单元标记。
         * @param[in]   flag：是否划分高阶单元
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        void setHighOrderFlag(bool flag);

        /**
         * @brief       获取高阶单元标记。
         * @return      是否划分高阶单元
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        bool getHighOrderFlag();

        /**
         * @brief       设置体网格与面网格划分单元类型。
         * @param[in]   type：单元类型（四面体+三角形 & 六面体+四边形）
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        void setElementType(ElementType2D3D type);

        /**
         * @brief       获取体网格与面网格划分单元类型。
         * @return      单元类型（四面体+三角形 & 六面体+四边形）
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        ElementType2D3D getElementType();

    protected:
        /**
         * @brief       网格尺寸因子。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        double m_sizeFactor = 1.;

        /**
         * @brief       最小网格尺寸。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        double m_minMeshSize = 1.;

        /**
         * @brief       最大网格尺寸。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-27
         */
        double m_maxMeshSize = 5.;
 
        /**
         * @brief       高阶单元标记。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        bool m_highOrderFlag = false;

        /**
         * @brief       网格划分单元类型。
         * @author      ChengHaotian (yeguangbaozi@foxmail.com)
         * @date        2025-08-28
         */
        ElementType2D3D m_eType = ElementType2D3D::ET_Quad;

    };
}
#endif
