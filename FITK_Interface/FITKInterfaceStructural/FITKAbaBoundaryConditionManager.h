/**
 * 
 * @file   FITKAbaBoundaryConditionManager.h
 * @brief  边界条件管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-22
 * 
 */
#ifndef FITKABABOUNDARYCONDITIONMANAGER_H
#define FITKABABOUNDARYCONDITIONMANAGER_H
#include "FITK_Interface/FITKInterfacePhysics/FITKAbstractLoadBC.h"
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaAbstractStep.h"


namespace Interface {
    /**
     * @brief  边界条件管理器类
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-22
     */
    class FITKInterfaceStructuralAPI FITKAbaBoundaryConditionManager: public FITKBCManager
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaBoundaryConditionManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaBoundaryConditionManager() = default;
        /**
         * @brief  删除在stepId中创建的边界条件
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-22
         */
        void deleteStepBoundaryConditions(int stepId);
        /**
         * @brief  分析步替换时对数据进行处理
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-26
         */
        void replaceStep(int oldStep, int newStep);
    };
}


#endif // FITKABABOUNDARYCONDITIONMANAGER_H
