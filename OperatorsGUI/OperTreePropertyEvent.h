/**********************************************************************
 * @file    OperTreePropertyEvent.h
 * @brief   属性树形菜单事件操作器
 * @author  lilongyuan(lilongyuan@diso.cn)
 * @date    2025-09-17
 *********************************************************************/
#ifndef __OPER_TREE_PROPERTY_EVENT_H__
#define __OPER_TREE_PROPERTY_EVENT_H__

#include "OperatorsInterface/TreeEventOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"

namespace GUIOper
{
    /**
     * @brief   属性树形菜单事件操作器
     * @author  lilongyuan(lilongyuan@diso.cn)
     * @date    2025-09-17
     */
    class  OperTreePropertyEvent : public EventOper::TreeEventOperator
    {
    public:
        /**
         * @brief   构造函数
         * @author  lilongyuan(lilongyuan@diso.cn)
         * @date    2025-09-17
         */
        explicit OperTreePropertyEvent() = default;
        /**
         * @brief   析构函数
         * @author  lilongyuan(lilongyuan@diso.cn)
         * @date    2025-09-17
         */
        virtual ~OperTreePropertyEvent() = default;
        /**
         * @brief   更新树形菜单
         * @author  lilongyuan(lilongyuan@diso.cn)
         * @date    2025-09-17
         */
        virtual void updateTree() override;
        /**
         * @brief     树形节点点击事件
         * @param[i]  w 树形菜单窗口
         * @param[i]  item 点击的树形菜单节点
         * @param[i]  col 点击列数
         * @author    lilongyuan(lilongyuan@diso.cn)
         * @date      2025-09-17
         */
        virtual void on_itemClicked(QTreeWidget* w, QTreeWidgetItem* item, int col = 0) override;
    };
    //注册事件操作器
    Register2FITKOperatorRepo(TreePropertyEvent, OperTreePropertyEvent);
}
#endif  // __OPER_TREE_PROPERTY_EVENT_H__