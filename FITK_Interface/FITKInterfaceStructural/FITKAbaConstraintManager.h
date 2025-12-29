/**
 * 
 * @file   FITKAbaConstraintManager.h
 * @brief  相互作用约束管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-17
 * 
 */
#ifndef FITKABACONSTRAINTMANAGER_H
#define FITKABACONSTRAINTMANAGER_H
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"
#include "FITKAbaAbstractConstraint.h"


namespace Interface {
    /**
     * @brief  相互作用约束管理器类
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-17
     */
    class FITKInterfaceStructuralAPI FITKAbaConstraintManager: public Core::FITKAbstractDataObject,
        public Core::FITKAbstractDataManager<FITKAbaAbstractConstraint>
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaConstraintManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaConstraintManager() = default;
    };
}


#endif // FITKABACONSTRAINTMANAGER_H
