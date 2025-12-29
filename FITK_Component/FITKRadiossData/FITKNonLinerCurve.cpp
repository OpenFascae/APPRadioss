#include "FITKNonLinerCurve.h"

namespace Radioss
{
    QList<FITKNonLinerCurve::FITKNonLinerCurvePoint> FITKNonLinerCurve::getPoints() const
    {
        return m_points;
    }

    void FITKNonLinerCurve::addPoint(const FITKNonLinerCurvePoint& point)
    {
        m_points.append(point);
    }

    bool FITKNonLinerCurve::removePoint(int index)
    {
        if (index < 0 || index >= m_points.size())
            return false;
        m_points.removeAt(index);
        return true;
    }

    bool FITKNonLinerCurve::updatePoint(int index, const FITKNonLinerCurvePoint& point)
    {
        if (index < 0 || index >= m_points.size())
            return false;
        m_points[index] = point;
        return true;
    }

    FITKNonLinerCurve::FITKNonLinerCurvePoint FITKNonLinerCurve::getPoint(int index) const
    {
        if (index < 0 || index >= m_points.size())
            return FITKNonLinerCurvePoint{0.0, 0.0};
        return m_points[index];
    }

    int FITKNonLinerCurve::getPointCount() const
    {
        return m_points.size();
    }
    void FITKNonLinerCurve::removeAllPoints()
    {
        m_points.clear();
    }
}
