#ifndef _FITKABASTEP_BUCKLE_H___
#define _FITKABASTEP_BUCKLE_H___

#include "FITKAbaAbstractStep.h"


namespace Interface
{
    class FITKInterfaceStructuralAPI FITKAbaStepBuckle : public FITKAbaAbstractStep
    {
        FITKCLASS(Interface, FITKAbaStepBuckle);
    public:
        explicit FITKAbaStepBuckle() ;
        virtual ~FITKAbaStepBuckle() = default;

        bool copy(FITKAbstractDataObject* obj) override;
        /**
         * @brief  获取分析步类型
         * @param[in]
         * @return
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-25
         */
        FITKAbaAbstractStep::FITKAbaStepType getStepType() const override;

        void setEigensolver(Eigensolver s);
        Eigensolver getEigensolver() const;

        void setNumberOfEigenValuesRequset(int n);
        int getNumberOfEigenValuesRequset() const;

        void enableMinEigenvalueInterest(bool enable);
        bool isEnableMinEigenvalueInterest() const;
        void setMinEigenvalueInterest(const double v);
        double getMinEigenvalueInterest()const;

        void enableMaxEigenvalueInterest(bool enable);
        bool isEnableMaxEigenvalueInterest() const;
        void setMaxEigenvalueInterest(const double v);
        double getMaxEigenvalueInterest()const;

        void setBlockSize(BlockSize b);
        BlockSize getBlockSize() const;

        void setBlockSizeValue(int v);
        int getBlockSizeValue()const;

        void setMaximumNumberOfBlockLanczosStep(MaximumNumberOfBlockLanczosStep tp);
        MaximumNumberOfBlockLanczosStep getMaximumNumberOfBlockLanczosStep() const;

        void setMaximumNumberOfBlockLanczosStepValue(int n);
        int getMaximumNumberOfBlockLanczosStepValue() const;

        void setVectorsUsedPerIteration(int n);
        int getVectorsUsedPerIteration() const;

        void setMaxNumberOfIterations(const int n);
        int getMaxNumberOfIterations() const;


        void setMatrixStorage(MatrixStorage m);
        MatrixStorage getMatrixStorage() const;

    private:
        Eigensolver _eigenSolver{ Eigensolver::Subspace };
        int _numberOfEigenValues{ 0 };

        bool _isMinEigenvalueInterest{ false };
        double _minEigenvalueInterest{ 0 };

        bool _isMaxEigenvalueInterest{ false };
        double _maxEigenvalueInterest{ 0 };

        BlockSize _blockSize{ BlockSize::DefaultBlock };
        int _blockSizeValue{ 0 };
        MaximumNumberOfBlockLanczosStep _maxNumOfBlockLanczos{ MaximumNumberOfBlockLanczosStep::DefaultMaximum };
        int _maxNumOfBlockLanczosValue{ 0 };

        int _vectorsUsedInPerIter{ 0 };
        int _maxNumberOfIter{ 30 };

        MatrixStorage _matrixStorage{ MatrixStorage::Symmetric };
    };
}



#endif


