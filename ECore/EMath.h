/****************************************************
	�ļ���EMath.h
	���ߣ�JiahaoWu
	����: jiahaodev@163.ccom
	���ڣ�2020/07/19
	���ܣ�
*****************************************************/

#pragma once

#include "ECommon.h"

namespace E3D
{
	template<typename T>
	const T &Min(const T &a, const T &b) {
		return (a < b) ? a : b;
	}

	template<typename T>
	const T &Max(const T &a, const T &b) {
		return (b < a) ? a : b;
	}

	//��val�ķ�Χ������min - max ֮��
	template<typename T>
	const T &Clamp(const T &val, const T &minV, const T &maxV)
	{
		return Max(Min(val, maxV), minV);
	}

	//��ȡƽ�Ʊ任����
	void GetTranslateMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//��ȡ���ű任����
	void GetScaleMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//��ȡ��X����ת�任������ת��������λΪ�Ƕȣ�
	void GetRotateMatrix44X(EMatrix44 &mat, EFloat degree);

	//��ȡ��Y����ת�任������ת��������λΪ�Ƕȣ�
	void GetRotateMatrix44Y(EMatrix44 &mat, EFloat degree);

	//��ȡ��Z����ת�任������ת��������λΪ�Ƕȣ�
	void GetRotateMatrix44Z(EMatrix44 &mat, EFloat degree);

	//��ȡ����������ת�任������ת��������λΪ�Ƕȣ�
	void GetRotateMatrix44(EMatrix44 &mat,const EVector4D &n,EFloat degree);

	// 3D����  *44����
	void GetVector3DMulMatrix44(const EVector3D &vec, const EMatrix44 &mat, EVector3D &result);

	// 4D����  *44����
	void GetVector4DMulMatrix44(const EVector4D &vec, const EMatrix44 &mat, EVector4D &result);

	// 4D���� + 4D����
	void GetVertex4DAddVector4D(const EVertex4D &v, const EVector4D &p, EVertex4D &result);

	// 4D����  *44����
	void GetVertex4DMulMatrix44(const EVertex4D &v, const EMatrix44 &mat, EVertex4D &result);

}