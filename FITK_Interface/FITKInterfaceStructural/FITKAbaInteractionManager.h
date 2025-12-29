/**
 * 
 * @file   FITKAbaInteractionManager.h
 * @brief  相互作用管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-17
 * 
 */
#ifndef FITKABAINTERACTIONMANAGER_H
#define FITKABAINTERACTIONMANAGER_H
#include "FITKAbaAbstractInteraction.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"


namespace Interface {
    class FITKAbaAbstractStep;
    /**
     * @brief  相互作用管理器
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-17
     */
    class FITKInterfaceStructuralAPI FITKAbaInteractionManager: public Core::FITKAbstractDataObject,
        public Core::FITKAbstractDataManager<FITKAbaAbstractInteraction>
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaInteractionManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaInteractionManager() = default;
        /**
         * @brief  删除在分析步中创建的相互作用
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-22
         */
        void deleteStepInteractions(int stepId);
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


#endif // FITKABAINTERACTIONMANAGER_H
