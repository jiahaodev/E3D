/****************************************************
    文件：E3DHeader.h
    作者：JiahaoWu
    邮箱: jiahaodev@163.ccom
    日期：2020/07/18       
    功能：定义引擎用到的自定义结构体。
	      如果编码需要用到上述结构体，
		  直接引用E3DHeader.h头文件，即可。
*****************************************************/

#pragma once

namespace E3D
{
	struct EColor;       //颜色
	struct EVector2D;    //二维向量
	struct EVector3D;    //三维向量
	struct EVector4D;    //四维向量
	struct EMatrix44;    //4X4矩阵
	 
	struct EVertex4D;    //顶点
	struct EPolyon4D;    //基于顶点多边形
	struct EPolyonF4D;   //基于索引多边形
	struct EObject4D;	 //对象
	struct EPlane3D;     //三维平面
	struct ERenderList4D;//渲染列表

	struct EFrustum;     //透视体
}