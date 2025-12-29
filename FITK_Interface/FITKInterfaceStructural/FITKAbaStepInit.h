/**
 * 
 * @file   FITKAbaStepInit.h
 * @brief  初始分析步
 * @author LiJin (1003680421@qq.com)
 * @date   2024-03-26
 * 
 */
#ifndef FITKABASTEPINIT_H
#define FITKABASTEPINIT_H
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaAbstractStep.h"


namespace Interface {
    /**
     * @brief  初始分析步，分析步时间为-1，几何非线性为false
     * @author LiJin (1003680421@qq.com)
     * @date   2024-03-26
     */
    class FITKInterfaceStructuralAPI FITKAbaStepInit: public FITKAbaAbstractStep
    {
        FITKCLASS(Interface, FITKAbaStepInit)
    public:
        /**
         * @brief  获取分析步类型
         * @param[in]
         * @return FITKAbaStepType枚举类型值
         * @author libaojun (libaojunqd@foxmail.com)
         * @date   2024-03-28
         */
        virtual FITKAbaStepType getStepType() const override;

        /**
         * @brief  获取分析步时间，初始分析步返回-1
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-03-26
         */
        double getTime() const override;
        /**
         * @brief  获取几何非线性状态，初始分析步返回false
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-03-26
         */
        bool getNlgeom() const override;
    };
}


#endif // FITKABASTEPINIT_H
