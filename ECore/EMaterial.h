/****************************************************
    �ļ���EMaterial.h
    ���ߣ�JiahaoWu
    ����: jiahaodev@163.ccom
    ���ڣ�2020/07/19       
    ���ܣ��������ʡ���ȡ���ʡ����ò��� �� ɾ������
*****************************************************/

#pragma once

#include <map>

#include "ECommon.h"
#include "EGraphics.h"

/*
�����ļ�ʾ����

//��������
material BallBullet
{
	technique
	{
		pass
		{
			//�ƹ�����
			ambient 0.7 0.7 0.71
			diffuse 0.7 0.7 0.71
			specular 0.1 0.1 0.1 10 0

			texture_unit
			{
				//��������
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

	//�������ʽű�����ȡ�������ʺ���ͼ
	//���ʽű������ģ��������ͬ���� ogreHead.mesh  ogreHead.material
	extern void ParseMaterialScript(const EString &scriptName);

}