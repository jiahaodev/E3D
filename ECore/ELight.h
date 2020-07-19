/****************************************************
	文件：ELight.h
	作者：JiahaoWu
	邮箱: jiahaodev@163.ccom
	日期：2020/07/19
	功能：灯关类
		  主要分为 环境光(ambient)、平行光(direction)、点光源(point)
		  后期如果有需要，继续添加即可
*****************************************************/

#pragma once

#include "ECommon.h"
#include "EVector.h"

namespace E3D
{
	enum LIGHT_TYPE
	{
		LIGHT_AMBIENT = 0,   //环境光
		LIGHT_DIRECTION = 1, //平行光
		LIGHT_POINT = 2,     //点光源
	};

	struct ELight
	{
		EInt id;				//灯关的分配ID，全局唯一
		EBool lightOn;			//灯光是否启用

		LIGHT_TYPE lightType;	//灯关类型

		EFloat power;			//灯关强度，默认为1.0f
		EFloat shadowFactor;	//灯关背面强度，默认为0.05f
		EColor ambient;			//灯关的环境色（环境光使用）
		EColor diffuse;			//灯关的漫反射颜色
		EColor specular;		//灯关的高光颜色

		EVector4D position;		//灯关世界坐标位置
		EVector4D direction;	//光源朝向（点光源无效）

		EVector4D transPosition;//灯关摄像机坐标位置
		EVector4D transDirection;//摄像机坐标光源朝向，点光源无效

		EFloat kc, kl, kq;		//衰减因子

		EFloat spot_inner;		//聚光灯内锥角
		EFloat spot_outer;		//聚光灯外锥角
		EFloat pf;				//聚光灯指数因子

		ELight(EInt lightId, LIGHT_TYPE type);
	};

	//最大灯光数
#define MAX_LIGHTS 8
	//全局灯关管理
	extern std::vector<ELight*> *GLights;
	
	typedef std::vector<ELight*>::iterator LightItr;
	
	//创建一个新的灯关，创建成功返回灯关ID（全局唯一）；创建失败返回-1
	extern EInt CreateLight(LIGHT_TYPE lightType);
	//获取一个灯关，如果灯关不存在，则返回NULL
	extern ELight *GetLight(EInt id);
	//获取灯关数量
	extern EInt GetLightSize();
	//销毁全部光源
	extern void DestoryAllLights();
}