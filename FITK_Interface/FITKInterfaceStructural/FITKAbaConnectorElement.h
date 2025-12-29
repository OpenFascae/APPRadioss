/**
 *
 * @file FITKAbaAssemblyElements.h
 * @brief 装配单元类
 * @author LiBaojun (libaojunqd@foxmail.com)
 * @date 2024-06-24
 *
 */
#ifndef _FITKABA_CONNECTOR_ELEMENTS_H__
#define _FITKABA_CONNECTOR_ELEMENTS_H__

#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaAssemblyElements.h"

namespace Interface
{
    /**
     * @brief 三维二节点单元
     * @author LiBaojun (libaojunqd@foxmail.com)
     * @date 2024-06-24
     */
    class FITKInterfaceStructuralAPI FITKAbaAssEle3D2 : public FITKAbstractAbaAssemblyElement
        , public FITKAssemblyElementLine
    {
    public:
        /**
         * @brief Construct a new FITKAbaAssEle3D2 object
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-06-24
         */
        explicit FITKAbaAssEle3D2() = default;
        /**
         * @brief Destroy the FITKAbaAssEle3D2 object
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-06-24
         */
        virtual ~FITKAbaAssEle3D2() = default;


    };


    /**
     * @brief CONND3D2单元
     * @author LiBaojun (libaojunqd@foxmail.com)
     * @date 2024-06-24
     */
    class FITKInterfaceStructuralAPI FITKAbaAssEleCONN3D2: public FITKAbaAssEle3D2
    {
    public:
        using FITKAbaAssEle3D2::FITKAbaAssEle3D2;
        virtual ~FITKAbaAssEleCONN3D2() = default;
        /**
         * @brief 获取单元类型
         * @return FITKAssElementType
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-06-24
         */
        virtual FITKAssElementType getAssElementType()override;
        /**
         * @brief 获取单元的拷贝
         * @return FITKAbstractAbaAssemblyElement*
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-06-24
         */
        virtual FITKAbstractAbaAssemblyElement* getACopy() override;
    };

    class FITKInterfaceStructuralAPI FITKAbaAssEleSpringDashpot : public FITKAbaAssEle3D2
    {
    public:
        using FITKAbaAssEle3D2::FITKAbaAssEle3D2;
        virtual ~FITKAbaAssEleSpringDashpot() = default;
        /**
         * @brief 获取单元类型
         * @return FITKAssElementType
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-06-24
         */
        virtual FITKAssElementType getAssElementType()override;
        /**
         * @brief 获取单元的拷贝
         * @return FITKAbstractAbaAssemblyElement*
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-06-24
         */
        virtual FITKAbstractAbaAssemblyElement* getACopy() override;

    };

 

}



#endif
