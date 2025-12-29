/**
 * 
 * @file MeshImporterNastran.h
 * @brief Nastran网格 bdf nas 导入器类声明
 * @author LiBaojun (libaojunqd@foxmail.com)
 * @date 2025-10-21
 * 
 */
#ifndef _MESH_IMPORTER_NASTRAN_H_
#define _MESH_IMPORTER_NASTRAN_H_
#include "OperImportMesh.h"

namespace ModelOper
{
    /**
     * @brief Nastran网格 bdf nas 导入器类
     * @author LiBaojun (libaojunqd@foxmail.com)
     */
    class FITKNastranMeshImporter : public FITKAbstractMeshImporter
    {
    public:
        /**
         * @brief Construct a new FITKNastranMeshImporter object
         * @param[i]  parent         父对象
         * @author LiBaojun (libaojunqd@foxmail.com)
         */
        explicit FITKNastranMeshImporter(QObject* parent = nullptr);
        /**
         * @brief Destroy the FITKNastranMeshImporter object
         * @author LiBaojun (libaojunqd@foxmail.com)
         */
        virtual ~FITKNastranMeshImporter() = default;

        /**
         * @brief 线程执行函数
         * @author LiBaojun (libaojunqd@foxmail.com)
         */
        virtual void run() override;

    private:
    };
}

#endif