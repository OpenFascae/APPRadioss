/**
 * 
 * @file   FITKAbaAbastractSectionAssign.h
 * @brief  界面指派抽象类
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-11
 * 
 */
#ifndef FITKABAABASTRACTSECTIONASSIGN_H
#define FITKABAABASTRACTSECTIONASSIGN_H
#include "FITKInterfaceStructuralAPI.h"
#include "FITK_Interface/FITKInterfacePhysics/FITKSectionAssign.h"


namespace Interface {
    
    /**
     * @brief  截面指派抽象类
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-11
     */
    class FITKInterfaceStructuralAPI FITKAbaAbastractSectionAssign: public FITKSectionAssign
    {
        Q_OBJECT
    public:
        /**
     * @brief  截面指派类型枚举
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-11
     */
        enum FITKAbaSectionAssignType
        {
            None,
            SolidHomogeneous,
            ShellHomogeneous,
            Beam,
            Truss,
        };
        Q_ENUM(FITKAbaSectionAssignType);
    public:
        /**
         * @brief  构造
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaAbastractSectionAssign() = default;
        /**
         * @brief  析构
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaAbastractSectionAssign() = default;
        /**
         * @brief  获取截面类型指派类型
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-11
         */
        virtual FITKAbaSectionAssignType getSectionAssignType() const = 0;
    };
}


#endif // FITKABAABASTRACTSECTIONASSIGN_H
