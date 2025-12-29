#include "FITKRadiossCaseManager.h"

namespace Radioss
{
    void FITKRadiossCaseManager::setCurrentCaseID(int caseID)
    {
        _currentCaseID = caseID;
    }

    int FITKRadiossCaseManager::getCurrentCaseID() const
    {
        return _currentCaseID;
    }

    FITKRadiossCase* FITKRadiossCaseManager::getCurrentCase()
    {
        FITKRadiossCase* currentCase = this->getDataByID(_currentCaseID);
        if (!currentCase) return currentCase;
        //寻找第一个不是nullptr的元素
        const int n = this->getDataCount();
        for (int i = 0; i<n; ++i)
        {
            currentCase = this->getDataByIndex(i);
            if (currentCase != nullptr)
            {
                _currentCaseID = currentCase->getDataObjectID();
                return currentCase;
            }
        }
        return nullptr;
    }

} // namespace Radioss
