/**********************************************************************
 * @file   OperGmshSettings.h
 * @brief  Gmsh网格尺寸设置
 * @author guqingtao (15598887859@163.com)
 * @date   2025-06-20
 *********************************************************************/
#ifndef __OPERGMSHSETTINGS____
#define __OPERGMSHSETTINGS____

#include "FITK_Kernel/FITKCore/FITKActionOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"

namespace ModelOper
{
    class OperGmshSettings :public Core::FITKActionOperator
    {
        Q_OBJECT;
    public:
        /**
         * @brief    Gmsh网格尺寸操作器
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-06-06
         */
        explicit OperGmshSettings() = default;
        virtual ~OperGmshSettings() = default;

        /**
         * @brief 执行界面操作
         * @return true     执行成功
         * @return false     执行失败
         * @author guqingtao (15598887859@163.com)
         * @date 2025-06-06
         */
        virtual bool execGUI() override;
        /**
         * @brief 执行读入操作
         * @return true     执行成功
         * @return false     执行失败
         * @author guqingtao (15598887859@163.com)
         * @date 2025-06-06
         */
        virtual bool execProfession() override;

    private:

    };
    //Register2FITKOperatorRepo(actionGmshSettings, OperGmshSettings);

}
#endif