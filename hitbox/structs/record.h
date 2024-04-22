#pragma once
struct RecordFrame
{
	unsigned int body : 1;			//��λ��
	unsigned int norhit : 1;		//�ܻ�
	unsigned int cast : 1;			//��Ͷ
	unsigned int guard : 1;			//����
	unsigned int down : 1;			//����
	unsigned int ofo : 1;			//�������е���
	unsigned int rfo : 1;			//�������е���
	unsigned int guardpoint : 1;	//����
	unsigned int flyobjpoint : 1;	//�Է��е��ߵ���
	unsigned int throwpoint : 1;	//��Ͷ����
	unsigned int noratk : 1;		//��ͨ����
	unsigned int flyobj : 1;		//���е���
	unsigned int throwatk : 1;		//Ͷ��
	unsigned int force : 1;			//ǿ������
	unsigned int causeguard : 1;	//��������
	unsigned int crawl : 1;			//ץȡ
	unsigned int cancel : 1;		//��ȡ��
	unsigned int timepause : 1;		//ʱ����ͣ
	unsigned int summonobj : 1;		//���ɷ��е���
};