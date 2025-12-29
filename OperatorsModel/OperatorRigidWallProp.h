/**********************************************************************
 * @file   OperatorRigidWallProp.h
 * @brief  刚性壁操作器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-08-26
 *********************************************************************/
#ifndef __OperatorRigidWallProp_H__
#define __OperatorRigidWallProp_H__

#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "FITK_Kernel/FITKCore/FITKActionOperator.h"


namespace OperModel
{
    /**
     * @brief  刚性壁操作器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-08-26
     */
    class OperatorRigidWallProp :public Core::FITKActionOperator
    {
    public:
        explicit OperatorRigidWallProp() = default;
        virtual ~OperatorRigidWallProp() = default;
        /**
         * @brief    执行界面操作
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        virtual bool execGUI();
        /**
         * @brief    执行业务处理逻辑
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        virtual bool execProfession();
    private:
        /**
         * @brief    重命名刚性壁
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        bool rigidWallPropRenameOper();
        /**
         * @brief    删除刚性壁
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        bool deleteRigidWall();
    };

    // 按钮注册相关操作
    Register2FITKOperatorRepo(actionRigidWallCreate, OperatorRigidWallProp);
    Register2FITKOperatorRepo(actionRigidWallEdit, OperatorRigidWallProp);

}

#endif
