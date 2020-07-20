/****************************************************
    文件：EMaterial.h
    作者：JiahaoWu
    邮箱: jiahaodev@163.ccom
    日期：2020/07/19       
    功能：解析材质、获取材质、设置材质 及 删除材质
*****************************************************/

#pragma once

#include <map>

#include "ECommon.h"
#include "EGraphics.h"

/*
材质文件示例：

//材质名字
material BallBullet
{
	technique
	{
		pass
		{
			//灯关设置
			ambient 0.7 0.7 0.71
			diffuse 0.7 0.7 0.71
			specular 0.1 0.1 0.1 10 0

			texture_unit
			{
				//材质名字
				texture spheremap.BMP
			}
		}
	}
}
*/

namespace E3D
{
	struct EMaterial
	{
		EString name;
		EColor ambient;
		EColor diffuse;
		EColor specular;

		EBitmap *bitmap;

		EMaterial();
		~EMaterial();

		inline bool useTexture() { return bitmap && bitmap->isValid(); }

		EColor getPixel(EFloat u,EFloat v);

	};

	typedef std::map<EString, EMaterial*>::iterator MaterialIter;
	extern std::map<EString, EMaterial*> *GMaterials;

	extern EMaterial *GetMaterial(const EString &name);
	extern bool SetMaterial(const EString &name, EMaterial *material);
	extern bool DestoryMaterial(const EString &name);
	extern void DestoryAllMaterials();

	//解析材质脚本，读取基本材质和贴图
	//材质脚本必须和模型名称相同，如 ogreHead.mesh  ogreHead.material
	extern void ParseMaterialScript(const EString &scriptName);

}