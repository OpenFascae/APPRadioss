#include "ModelCaseTree.h"
#include "FITK_Component/FITKWidget/FITKTreeWidget.h"

#include "GUIEnumType.h" 
#include <QMenu>

namespace GUI
{
    ModelCaseTree::ModelCaseTree(QTreeWidgetItem* parentItem/*,AbaqusData::FITKDataCase* caseData*/)
        :_parentItem(parentItem)/*,_caseData(caseData)*/
    {
        this->initTree();
    }

    ModelCaseTree::~ModelCaseTree()
    {
        //TODO: delete
    }

    void ModelCaseTree::itemClicked(QTreeWidgetItem* item)
    {
        Q_UNUSED(item);
    }

    void ModelCaseTree::contextMenu(const QList<QTreeWidgetItem*>& items, QMenu* menu)
    {
        if (items.isEmpty()) return;
        QTreeWidgetItem* item = items.at(0);

        if (item == nullptr || menu == nullptr) return;
        GUI::PartTreeItemType itemType = (GUI::PartTreeItemType)item->type();

        switch (itemType)
        {
        default:
            break;
        }

    }

    void ModelCaseTree::updateTree(GUI::PartTreeItemType type)
    {
        switch (type)
        {
        default:
            break;
        }
    }

    void ModelCaseTree::initTree()
    {
        if (_parentItem == nullptr) return;
      /*  const QString caseName = _caseData->getDataObjectName();
        _caseRoot = Comp::FITKTreeWidget::CreateTreeItem(_parentItem, caseName, GUI::MITCaseRoot, "");
        if (_caseRoot == nullptr) return;
        _caseRoot->setExpanded(true);
        this->addTreeItemInfo(_caseRoot, -1);*/
    }

    void ModelCaseTree::addTreeItemInfo(QTreeWidgetItem* item, const int dataObjID)
    {
        if (item == nullptr ) return;

    }

}


