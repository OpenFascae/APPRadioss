#include "FITKAbstractTimeHistory.h"

namespace Radioss
{
    FITKAbstractTimeHistory::~FITKAbstractTimeHistory()
    {
    }

    FITKAbstractTimeHistory::TimeHistoryType FITKAbstractTimeHistory::getTimeHistoryType()
    {
        return FITKAbstractTimeHistory::TimeHistoryType::TimeHistory_Unknown;
    }

    void FITKAbstractTimeHistory::setObjIDs(QList<int> objIDs)
    {
        m_objID = objIDs;
    }

    QList<int> FITKAbstractTimeHistory::getObjIDs()
    {
        return m_objID;
    }

    QList<FITKAbstractTimeHistory*> FITKTimeHistoryManager::getTimeHistoryByType(FITKAbstractTimeHistory::TimeHistoryType type)
    {
        QList<FITKAbstractTimeHistory*> dataList;
        //通过类型获取时间历程
        int count = this->getDataCount();
        for (int i = 0; i < count; ++i)
        {
            FITKAbstractTimeHistory* data = this->getDataByIndex(i);
            if (!data) continue;
            if (data->getTimeHistoryType() != type) continue;
            dataList.append(data);
        }
        return dataList;
    }

} // namespace Radioss

 