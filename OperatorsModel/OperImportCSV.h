/**********************************************************************
 * @file   OperImportCSV.h
 * @brief  CSV文件导入操作器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-10-20
 *********************************************************************/
#ifndef _OPERIMPORTCSV_H
#define _OPERIMPORTCSV_H

#include "FITK_Kernel/FITKCore/FITKActionOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include <array>

namespace ModelOper
{
    /**
     * @brief  CSV文件导入操作器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-10-20
     */
    class OperImportCSV :public Core::FITKActionOperator
    {
        Q_OBJECT;
    public:

        explicit OperImportCSV() = default;
        virtual ~OperImportCSV() = default;
        /**
         * @brief    界面逻辑
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-10-20
         */
        virtual bool execGUI() override;
        /**
         * @brief    业务逻辑
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-10-20
         */
        virtual bool execProfession() override;

    };

    // 按钮注册相关操作
    Register2FITKOperatorRepo(actionImportCSVResult, OperImportCSV);
}

#endif