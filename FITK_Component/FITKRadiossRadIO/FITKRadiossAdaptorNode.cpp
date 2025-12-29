#include "FITKRadiossAdaptorNode.h"

#include "FITK_Kernel/FITKCore/FITKVec3D.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossNodesParts.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossMeshModel.h"

#include "FITKRadiossRadReader.h"
#include "FITKRadiossRadWriter.h"
#include "RadKeyLineSpliter.h"
#include "RadReadInformationMapper.h"

namespace Radioss
{
    QString FITKRadiossAdaptorNode::getAdaptorClass()
    {
        return "Radioss::FITKRadiossAdaptorNode";
    }

    bool FITKRadiossAdaptorNode::adaptR()
    {
        if (_caseData == nullptr || _reader == nullptr) return false;
        // 获取节点数据对象
        FITKRadiossNodes* nodes = _caseData->getMeshModel()->getNodes();
        if (nodes == nullptr) return false;
        //读取关键字
        RadKeyLineSpliter *keyLineSpliter = _reader->getKeyLineSpliter();
        if (!keyLineSpliter) return false;
        //获取id和关键字
        int uid = keyLineSpliter->getId();
        QString keyLine = keyLineSpliter->getCurrentLine();

        bool ok = false;
        while (_reader && !_reader->atEnd())
        {
            QString line = _reader->readLine();
            //其他关键字
            if (line.startsWith("/"))
            {
                _reader->backLine();
                break;
            }
            //读取节点数据
            ok = this->readNodes(nodes);
        }
        if (!ok)
        {
            _reader->consoleMessage(3, QString("Read Node Error: %1").arg(keyLine));
            return false;
        }
        _reader->consoleMessage(1, QString("Read Node : %1").arg(keyLine));
        return true;
    }

    bool FITKRadiossAdaptorNode::adaptW()
    {
        if (_caseData == nullptr || _writer == nullptr) return false;
        // 获取文件流及节点数据对象
        QTextStream* stream = _writer->getStream();
        FITKRadiossNodes* nodes = _caseData->getMeshModel()->getNodes();
        if (stream == nullptr || nodes == nullptr) return false;
        //注释行
        *stream << "#-  3. NODES:" << endl;
        *stream << "#---1----|----2----|----3----|----4----|----5----|----6----|----7----|----8----|----9----|---10----|" << endl;
        //关键字/NODE,暂不处理unitID
        *stream << "/NODE";
        *stream << endl;
        //获取节点数量，写出数据
        int nodeCount = nodes->getNodeCount();
        for (int i = 0; i < nodeCount; ++i)
        {
            Core::FITKNode* node = nodes->getNodeAt(i);
            int nodeId = node->getNodeID();
            double x = node->x();
            double y = node->y();
            double z = node->z();
            
            *stream << QString("%1").arg(nodeId, 10, 10, QChar(' '))
                << QString("%1").arg(x, 20, 'g', 10, QChar(' '))
                << QString("%1").arg(y, 20, 'g', 10, QChar(' '))
                << QString("%1").arg(z, 20, 'g', 10, QChar(' '))
                << endl;
        } 
        *stream << "#---1----|----2----|----3----|----4----|----5----|----6----|----7----|----8----|----9----|---10----|" << endl;
        return true;
    }

    bool FITKRadiossAdaptorNode::readNodes(FITKRadiossNodes * nodes)
    {
        if (nodes == nullptr || _reader == nullptr) return false;
        RadReadInformationMapper *infoMapper = _reader->getReadRadInformationMapper();
        if ( !infoMapper) return false;

        //没有名称，直接回退一行
        _reader->backLine();
        while (!_reader->atEnd())
        {
            QString line = _reader->readLine();
            if (line.startsWith("/"))
            {
                _reader->backLine();
                break;
            }
            QStringList nodeInf = line.simplified().split(" ");
            if (nodeInf.size() != 4)
            {
                _reader->consoleMessage(3, QString("Invalid Node line : %1.").arg(line));
                continue;
            }
            int radID = nodeInf[0].toInt();
            // 节点坐标
            double x = nodeInf[1].toDouble();
            double y = nodeInf[2].toDouble();
            double z = nodeInf[3].toDouble();
            int nodeID = nodes->addNode(x, y, z);
            infoMapper->insertNodeIDMap(radID, nodeID);

            _reader->sendCurrentPercent();
        }
        return true;
    }

}


