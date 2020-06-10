#pragma once
#include "ICompressBy.h"

/// ������ ����� ��������� ������ ���������� ������, ��� ������� ������. 
/** 
	�������� �������� ������ ����������� � �������� ������ @ref ICompressBy.\n
	### ����������� ������ ����������
	- ��� ������ ���������� ������.
	- ������ @ref AddData � @ref AddText �������� �������� ������ � ������ ������. ������ �� ������������.
	- �������������� ��� ������ ��� �������������. @ref GetCompressedTreeCount ���������� 0, �
	@ref GetCompressedTree ������ ���� ������.
*/

class CCompressByStore : public CBaseCompressor
{
public:
	/// ��������� ��������� ������ ����� �������.
	/** ********************************************************************
	* @param aDataPtr - ��������� �� ����� � �������
	* @param aDataSize - ���������� ���� ������ � ������, ������� ���������� 
	*					���������.
	* @param aDataType - ��� ������ ������� ����������� (����� �����).
	*
	* @return ��� ������
	************************************************************************/
	int AddText(const UInt16 *aDataPtr, UInt32 aDataSize, UInt32 aDataType) override;
	
	/// ��������� ������ �������, ���� �� �������� ����� ������ ��� aTotalCount.
	/***********************************************************************
	* ��� �����, ����� ���������� �������� ��������������� ���������� ������,
	* ���� �� ����������, ���� ��������� ����� � ������� �� �������� ������
	*
	* @param aTotalCount	- ����� ���������� ��������, ������� ������ ����
	*
	* @return ��� ������
	************************************************************************/
	int AddEmptyTrees(UInt32 aTotalCount) override;

	/// ���������� ���������� �������� ������������ ��� ������
	/** ********************************************************************
	* @return ���������� ��������
	************************************************************************/
	UInt32 GetCompressedTreeCount() const override;

protected:
	/// ���������� ��������� �������� ��� ������������ ������
	int BuildTrees() override;

	/// ���������� ������ ���������� ������.
	MemoryRef GetCompressedTree(UInt32 aIndex) override;
};
