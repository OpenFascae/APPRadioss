/**********************************************************************
 * @file   FITKNastranAdaptorMaterial.h
 * @brief  Nastran bdf 文件 材料读写适配器
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-03-12
 *********************************************************************/
#ifndef _FITKNASTRANADAPTORMATERIAL_H
#define _FITKNASTRANADAPTORMATERIAL_H

#include "FITKNastranAbstractAdaptor.h"

namespace Nastran
{
    class FITKNastranAdaptorMaterial : public FITKNastranAbstractAdaptor
    {
    public:
        explicit FITKNastranAdaptorMaterial() = default;
        virtual ~FITKNastranAdaptorMaterial() = default;

        /**
         * @brief  适配器读取
         * @return bool 状态 true成功， false失败
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-03-12
         */
        bool adaptR() override;

        /**
         * @brief  适配器写入
         * @return bool 状态 true成功， false失败
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-03-12
         */
        bool adaptW() override;

    private:

        bool readMAT1(QStringList data);

        bool writeMAT1();
    };

    Register2FITKIOAdaptorFactory(BDF, NastranMaterial, FITKNastranAdaptorMaterial);
} // namespace Nastran

#endif // FITKNASTRANADAPTORMAT1_H
