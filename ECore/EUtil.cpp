#include "EUtil.h"


namespace E3D
{
	std::ofstream *GLogStream = NULL;

	bool InitLog(const EString& fileName) {
		if (GLogStream == NULL)
		{
			GLogStream = new std::ofstream();
			GLogStream->open(fileName.c_str());
			if (GLogStream->good())
				return true;
			return false;
		}
		return true;
	}

	void Log(const EChar* string, ...)
	{
		if (GLogStream == NULL)
			return;
		EChar buffer[256];

		//��֤���߶���Ϊ��
		if (!string || !GLogStream)
			return;

		va_list arglist;//�ɱ�����б�
		//������ջ�ϵĿɱ������ӡ����ַ���
		va_start(arglist, string);
		vsprintf_s(buffer, string, arglist);
		va_end(arglist);

		EString info(buffer);
		//�������Ϣ
		*GLogStream << info << std::endl;
		GLogStream->flush();
	}

	void CloseLog()
	{
		if (GLogStream == NULL)
			return;
		GLogStream->close();
		SafeDelete(GLogStream);
	}

}