/**
 * 
 * @file   FITKAbaLoadManager.h
 * @brief  载荷管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-03-28
 * 
 */
#ifndef FITKABALOADMANAGER_H
#define FITKABALOADMANAGER_H
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITKAbaAbstractLoad.h"
#include "FITK_Interface/FITKInterfacePhysics/FITKAbstractLoadBC.h"


namespace Interface {
    class FITKAbaAbstractStep;
    /**
     * @brief  载荷管理器
     * @author LiJin (1003680421@qq.com)
     * @date   2024-03-28
     */
    class FITKInterfaceStructuralAPI FITKAbaLoadManager:public FITKLoadManager
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaLoadManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaLoadManager() = default;
        /**
         * @brief  删除在分析步中创建的载荷
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-22
         */
        void deleteStepLoad(int stepId);
        /**
         * @brief  分析步替换时，对数据进行处理
         * @param[in]
         * @return
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-26
         */
        void replaceStep(int oldStep, int newStep);
    };

}

#endif // FITKABALOADMANAGER_H
