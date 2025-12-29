#include "FITKInteractionMultiUsageImpact.h"

namespace Radioss
{
    FITKInteractionMultiUsageImpact::FITKInteractionMultiUsageImpact()
    {
        _defaultValue = new FITKInteractionMultiUsageImpactDefaultValue();
    }

    FITKInteractionMultiUsageImpact::~FITKInteractionMultiUsageImpact()
    {
        FITKInteractionMultiUsageImpactDefaultValue * obj = _defaultValue.getObjectPtr();
        if (obj)
        {
            delete obj;
            obj = nullptr;
        }
    }

    FITKAbstractInteraction::InteractionType FITKInteractionMultiUsageImpact::getInteractionType()
    {
        return IT_MultiUsageImpact;
    }
    FITKInteractionMultiUsageImpactDefaultValue *FITKInteractionMultiUsageImpact::getValues()
    {
        return _defaultValue.getObjectPtr();
    }
    MultiUsageImpactOptionalData& FITKInteractionMultiUsageImpact::getOptionalData()
    {
        return _optionalData;
    }      
} // namespace Radioss
