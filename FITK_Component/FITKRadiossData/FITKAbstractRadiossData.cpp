#include "FITKAbstractRadiossData.h"

Radioss::FITKAbstractRadiossData::~FITKAbstractRadiossData()
{
}

void Radioss::FITKAbstractRadiossData::setVisible(bool isVisible)
{
    _isVisible = isVisible;
}

bool Radioss::FITKAbstractRadiossData::getVisible()
{
    return _isVisible;
}

//QString Radioss::FITKAbstractRadiossData::getRadiossFormatKeyWords() const
//{
//    return QString();
//}
