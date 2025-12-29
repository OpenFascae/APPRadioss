#include "FITKContainerAlg.h"

namespace Core
{
    QList<int> FITKCoreAPI intersection(const QList<QList<int>>& lists)
    {
        if (lists.isEmpty()) return QList<int>();

        // 使用第一个列表作为基准
        QList<int> result = lists.first();

        for (int i = 1; i < lists.size(); ++i) {
            QList<int> temp;
            const QList<int>& currentList = lists[i];

            for (const int& value : result) {
                if (currentList.contains(value)) {
                    temp.append(value);
                }
            }

            result = temp;
            if (result.isEmpty()) break;
        }

        return result;
    }

}