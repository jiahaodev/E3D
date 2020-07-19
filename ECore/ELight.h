/****************************************************
	�ļ���ELight.h
	���ߣ�JiahaoWu
	����: jiahaodev@163.ccom
	���ڣ�2020/07/19
	���ܣ��ƹ���
		  ��Ҫ��Ϊ ������(ambient)��ƽ�й�(direction)�����Դ(point)
		  �����������Ҫ��������Ӽ���
*****************************************************/

#pragma once

#include "ECommon.h"
#include "EVector.h"

namespace E3D
{
	enum LIGHT_TYPE
	{
		LIGHT_AMBIENT = 0,   //������
		LIGHT_DIRECTION = 1, //ƽ�й�
		LIGHT_POINT = 2,     //���Դ
	};

	struct ELight
	{
		EInt id;				//�ƹصķ���ID��ȫ��Ψһ
		EBool lightOn;			//�ƹ��Ƿ�����

		LIGHT_TYPE lightType;	//�ƹ�����

		EFloat power;			//�ƹ�ǿ�ȣ�Ĭ��Ϊ1.0f
		EFloat shadowFactor;	//�ƹر���ǿ�ȣ�Ĭ��Ϊ0.05f
		EColor ambient;			//�ƹصĻ���ɫ��������ʹ�ã�
		EColor diffuse;			//�ƹص���������ɫ
		EColor specular;		//�ƹصĸ߹���ɫ

		EVector4D position;		//�ƹ���������λ��
		EVector4D direction;	//��Դ���򣨵��Դ��Ч��

		EVector4D transPosition;//�ƹ����������λ��
		EVector4D transDirection;//����������Դ���򣬵��Դ��Ч

		EFloat kc, kl, kq;		//˥������

		EFloat spot_inner;		//�۹����׶��
		EFloat spot_outer;		//�۹����׶��
		EFloat pf;				//�۹��ָ������

		ELight(EInt lightId, LIGHT_TYPE type);
	};

	//���ƹ���
#define MAX_LIGHTS 8
	//ȫ�ֵƹع���
	extern std::vector<ELight*> *GLights;
	
	typedef std::vector<ELight*>::iterator LightItr;
	
	//����һ���µĵƹأ������ɹ����صƹ�ID��ȫ��Ψһ��������ʧ�ܷ���-1
	extern EInt CreateLight(LIGHT_TYPE lightType);
	//��ȡһ���ƹأ�����ƹز����ڣ��򷵻�NULL
	extern ELight *GetLight(EInt id);
	//��ȡ�ƹ�����
	extern EInt GetLightSize();
	//����ȫ����Դ
	extern void DestoryAllLights();
}