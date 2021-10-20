// /feature/material.c		by Shengsan@DS
// #pragma save_binary
#include <dbase.h>
#include <material.h>
#include <weapon.h>

/*
�ק��ɮ�:
	/include/globals.h
	/include/material.h(�s�W)
	/feature/material.c(�s�W)
	/std/equip.c

�C�ӧ���n�������� ���ݩ� �p: �K�� �w�� �@�Ϋ�(�ӷl��) �U�Q�� ����
*/
mapping material_value = ([
	"food1": ([
		"chinese":	"����1",	// ����W��
		"density":	200,		// �K��
		"hardness":	1,		// �w��
		"durable":	1,		// �@�Ϋ�
		"prize":	2,		// ����
		]),
	"food2": ([
		"chinese":	"����2",	// ����W��
		"density":	300,		// �K��
		"hardness":	1,		// �w��
		"durable":	1,		// �@�Ϋ�
		"prize":	5,		// ����
		]),
	"oil": ([
		"chinese":	"�o",		// ����W��
		"density":	300,		// �K��
		"hardness":	1,		// �w��
		"durable":	2,		// �@�Ϋ�
		"prize":	34,		// ����
		]),
	"grass": ([			
		"chinese":	"�C��",		// ����W��
		"density":	300,		// �K��
		"hardness":	3,		// �w��
		"durable":	3,		// �@�Ϋ�
		"prize":	3,		// ����
		]),
	"paper": ([
		"chinese":	"��",		// ����W��
		"density":	300,		// �K��
		"hardness":	3,		// �w��
		"durable":	4,		// �@�Ϋ�
		"prize":	5,		// ����
		]),
	"plant": ([			
		"chinese":	"�Ӫ�",		// ����W��
		"density":	300,		// �K��
		"hardness":	4,		// �w��
		"durable":	5,		// �@�Ϋ�
		"prize":	4,		// ����
		]),
	"peel": ([
		"chinese":	"�G��",		// ����W��
		"density":	300,		// �K��
		"hardness":	4,		// �w��
		"durable":	11,		// �@�Ϋ�
		"prize":	11,		// ����
		]),
	"linen": ([
		"chinese":	"�¥�",		// ����W��
		"density":	350,		// �K��
		"hardness":	4,		// �w��
		"durable":	8,		// �@�Ϋ�
		"prize":	30,		// ����
		]),
	"cloth": ([
		"chinese":	"����",		// ����W��
		"density":	350,		// �K��
		"hardness":	3,		// �w��
		"durable":	8,		// �@�Ϋ�
		"prize":	26,		// ����
		]),
	"silk": ([
		"chinese":	"����",		// ����W��
		"density":	350,		// �K��
		"hardness":	2,		// �w��
		"durable":	10,		// �@�Ϋ�
		"prize":	38,		// ����
		]),
	"wood": ([
		"chinese":	"���Y",		// ����W��
		"density":	350,		// �K��
		"hardness":	7,		// �w��
		"durable":	15,		// �@�Ϋ�
		"prize":	27,		// ����
		]),
	"ice": ([
		"chinese":	"�B",		// ����W��
		"density":	350,		// �K��
		"hardness":	14,		// �w��
		"durable":	7,		// �@�Ϋ�
		"prize":	10,		// ����
		]),
	"water": ([			
		"chinese":	"��",		// ����W��
		"density":	350,		// �K��
		"hardness":	1,		// �w��
		"durable":	1,		// �@�Ϋ�
		"prize":	2,		// ����
		]),
	"skin": ([
		"chinese":	"�֭�",		// ����W��
		"density":	400,		// �K��
		"hardness":	3,		// �w��
		"durable":	7,		// �@�Ϋ�
		"prize":	55,		// ����
		]),
	"fur": ([			
		"chinese":	"���",		// ����W��
		"density":	400,		// �K��
		"hardness":	4,		// �w��
		"durable":	7,		// �@�Ϋ�
		"prize":	68,		// ����
		]),
	"leather": ([
		"chinese":	"�֥�",		// ����W��
		"density":	400,		// �K��
		"hardness":	9,		// �w��
		"durable":	9,		// �@�Ϋ�
		"prize":	72,		// ����
		]),
	"rubber": ([
		"chinese":	"��",		// ����W��
		"density":	450,		// �K��
		"hardness":	8,		// �w��
		"durable":	25,		// �@�Ϋ�
		"prize":	41,		// ����
		]),
	"jade": ([
		"chinese":	"�B�A",		// ����W��
		"density":	550,		// �K��
		"hardness":	20,		// �w��
		"durable":	35,		// �@�Ϋ�
		"prize":	78,		// ����
		]),
	"gem": ([
		"chinese":	"�_��",		// ����W��
		"density":	550,		// �K��
		"hardness":	21,		// �w��
		"durable":	50,		// �@�Ϋ�
		"prize":	82,		// ����
		]),
	"rock": ([
		"chinese":	"����",		// ����W��
		"density":	550,		// �K��
		"hardness":	19,		// �w��
		"durable":	40,		// �@�Ϋ�
		"prize":	35,		// ����
		]),
	"silver": ([
		"chinese":	"��",		// ����W��
		"density":	550,		// �K��
		"hardness":	18,		// �w��
		"durable":	42,		// �@�Ϋ�
		"prize":	85,		// ����
		]),
	"crimsonsteel": ([
		"chinese":	"���K",		// ����W��
		"density":	650,		// �K��
		"hardness":	21,		// �w��
		"durable":	48,		// �@�Ϋ�
		"prize":	62,		// ����
		]),
	"iron": ([
		"chinese":	"�K",		// ����W��
		"density":	650,		// �K��
		"hardness":	20,		// �w��
		"durable":	52,		// �@�Ϋ�
		"prize":	57,		// ����
		]),
	"copper": ([
		"chinese":	"��",		// ����W��
		"density":	650,		// �K��
		"hardness":	20,		// �w��
		"durable":	55,		// �@�Ϋ�
		"prize":	81,		// ����
		]),
	"steel": ([
		"chinese":	"��",		// ����W��
		"density":	700,		// �K��
		"hardness":	23,		// �w��
		"durable":	57,		// �@�Ϋ�
		"prize":	73,		// ����
		]),
	"blacksteel": ([		
		"chinese":	"�¿�",		// ����W��
		"density":	700,		// �K��
		"hardness":	24,		// �w��
		"durable":	59,		// �@�Ϋ�
		"prize":	83,		// ����
		]),
	"gold": ([			
		"chinese":	"����",		// ����W��
		"density":	700,		// �K��
		"hardness":	17,		// �w��
		"durable":	45,		// �@�Ϋ�
		"prize":	100,		// ����
		]),
	"glass": ([
		"chinese":	"����",		// ����W��
		"density":	700,		// �K��
		"hardness":	25,		// �w��
		"durable":	45,		// �@�Ϋ�
		"prize":	42,		// ����
		]),
	"diamond": ([			
		"chinese":	"�����p",	// ����W��
		"density":	850,		// �K��
		"hardness":	28,		// �w��
		"durable":	45,		// �@�Ϋ�
		"prize":	105,		// ����
		]),
]);
// ����W��
string M_chinese(string material)
{
	if(undefinedp(material_value[material])) return "����";
	return material_value[material]["chinese"];
}

// �����Ʈw�j�p
int MDbase_size()
{
	return sizeof(material_value);
}

// �ǥX��Ʈw
mapping M_mapping()
{
	return material_value;
}
// DS ������n���O block
// DS �������q��쬰 dsg
//
// �K��		(dsg/block)
//
int M_density(string material)
{
	if(undefinedp(material_value[material])) return 20;
	return material_value[material]["density"];
}
// �w��
int M_hardness(string material)
{
	if(undefinedp(material_value[material])) return 20;
	return material_value[material]["hardness"];
}
// �@��
int M_durable(string material)
{
	if(undefinedp(material_value[material])) return 20;
	return material_value[material]["durable"];
}

// ����
int M_prize(string material)
{
	if(undefinedp(material_value[material])) return 5;
	return material_value[material]["prize"];
}





// �p�����n
int Eq_Volume(string material,int weight)
{
	int volume;
	volume = weight / M_density(material);
	if( volume <= 0 )
		volume = 1;
	return volume;
}

// �p��򥻶ˮ`�O (���weight�Pvolume)
int Eq_Damage(string material,int weight,string weapon_type)
{
	int damage;
	
	damage = STD_WEAPON(weapon_type)->weapon_damage(material,weight);
	
//	damage = (M_hardness(material)*weight/5000)+(Eq_Volume(material,weight)/8);
//	if(damage<1) damage=1;
	return damage;
}
// �p��򥻻��� (��� weight/100*M_prize)
int Eq_Prize(string material,int weight)
{
	int prize;
	weight=weight/100;
	if(weight<1) weight=1;
	prize = M_prize(material)*weight;
	return prize;
}
// �p��򥻭@�Ϋ�
int Eq_Durable(string material,int volume)
{
	int durable;
	durable = M_durable(material)*volume;
	return durable;
}

// �p�⪫�z���m�O
int Eq_Armor(string material,int volume)
{
	int armor;
	armor = (( M_density(material) + M_hardness(material) ) * volume ) / 100;
	return armor;
}