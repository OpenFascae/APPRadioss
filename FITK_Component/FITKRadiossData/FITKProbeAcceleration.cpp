#include "FITKProbeAcceleration.h"
#include "FITK_Kernel/FITKCore/FITKDataRepo.h"
#include "FITK_Interface/FITKInterfaceModel/FITKModelSet.h"
namespace Radioss
{
    FITKProbeAcceleration::~FITKProbeAcceleration()
    {}

    FITKAbstractProbe::ProbeType FITKProbeAcceleration::getType() const
    {
        return ProbeType::Probe_Acceleration;
    }

    void FITKProbeAcceleration::setSystemID(int sysID)
    {
        m_systemID = sysID;
    }
    int FITKProbeAcceleration::getSystemID()
    {
        return m_systemID;
    }
    void FITKProbeAcceleration::setSetID(int setID)
    {
        m_SetID = setID;
    }
    int FITKProbeAcceleration::getNodeID()
    {
        Interface::FITKModelSet*  set = FITKDATAREPO->getTDataByID< Interface::FITKModelSet>(m_SetID);
        if (!set)return -1;
        QList<int> nodeIDs = set->getMember();
        if (nodeIDs.isEmpty())return -1;
        return nodeIDs[0];
    }
    int FITKProbeAcceleration::getSetID()
    {
        return m_SetID;
    }
    void FITKProbeAcceleration::setCutOffFreq(double freq)
    {
        m_frequencyCut = freq;
    }
    double FITKProbeAcceleration::getCutOffFreq()
    {
        return m_frequencyCut;
    }
}