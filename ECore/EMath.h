/****************************************************
	文件：EMath.h
	作者：JiahaoWu
	邮箱: jiahaodev@163.ccom
	日期：2020/07/19
	功能：
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

	//将val的范围限制在min - max 之间
	template<typename T>
	const T &Clamp(const T &val, const T &minV, const T &maxV)
	{
		return Max(Min(val, maxV), minV);
	}

	//获取平移变换矩阵
	void GetTranslateMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//获取缩放变换矩阵
	void GetScaleMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//获取沿X轴旋转变换矩阵（旋转参数，单位为角度）
	void GetRotateMatrix44X(EMatrix44 &mat, EFloat degree);

	//获取沿Y轴旋转变换矩阵（旋转参数，单位为角度）
	void GetRotateMatrix44Y(EMatrix44 &mat, EFloat degree);

	//获取沿Z轴旋转变换矩阵（旋转参数，单位为角度）
	void GetRotateMatrix44Z(EMatrix44 &mat, EFloat degree);

	//获取沿任意轴旋转变换矩阵（旋转参数，单位为角度）
	void GetRotateMatrix44(EMatrix44 &mat,const EVector4D &n,EFloat degree);

	// 3D向量  *44矩阵
	void GetVector3DMulMatrix44(const EVector3D &vec, const EMatrix44 &mat, EVector3D &result);

	// 4D向量  *44矩阵
	void GetVector4DMulMatrix44(const EVector4D &vec, const EMatrix44 &mat, EVector4D &result);

	// 4D顶点 + 4D向量
	void GetVertex4DAddVector4D(const EVertex4D &v, const EVector4D &p, EVertex4D &result);

	// 4D顶点  *44矩阵
	void GetVertex4DMulMatrix44(const EVertex4D &v, const EMatrix44 &mat, EVertex4D &result);

}