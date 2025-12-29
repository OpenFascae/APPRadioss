#include "FITKAbstractInteraction.h"

namespace Radioss
{
    FITKAbstractInteraction::~FITKAbstractInteraction()
    {
    }

    FITKAbstractInteraction::InteractionType 
        FITKAbstractInteraction::getInteractionType()
    {
        return FITKAbstractInteraction::InteractionType::IT_None;
    }
    void FITKAbstractInteraction::setMasterSurfaceID(int id)
    {
        m_masterSurfaceID = id;
    }

    int FITKAbstractInteraction::getMasterSurfaceID() const
    {
        return m_masterSurfaceID;
    }

    void FITKAbstractInteraction::setNodeGroupID(int id)
    {
        m_nodeGroupID = id;
    }

    int FITKAbstractInteraction::getNodeGroupID() const
    {
        return m_nodeGroupID;
    }

} // namespace Radioss

 