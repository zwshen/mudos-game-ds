// /feature/material.c		by Shengsan@DS
// #pragma save_binary
#include <dbase.h>
#include <material.h>
#include <weapon.h>

/*
修改檔案:
	/include/globals.h
	/include/material.h(新增)
	/feature/material.c(新增)
	/std/equip.c

每個材質要有對應的 基本屬性 如: 密度 硬度 耐用度(耗損度) 銳利度 價格
*/
mapping material_value = ([
	"food1": ([
		"chinese":	"食物1",	// 中文名稱
		"density":	200,		// 密度
		"hardness":	1,		// 硬度
		"durable":	1,		// 耐用度
		"prize":	2,		// 價格
		]),
	"food2": ([
		"chinese":	"食物2",	// 中文名稱
		"density":	300,		// 密度
		"hardness":	1,		// 硬度
		"durable":	1,		// 耐用度
		"prize":	5,		// 價格
		]),
	"oil": ([
		"chinese":	"油",		// 中文名稱
		"density":	300,		// 密度
		"hardness":	1,		// 硬度
		"durable":	2,		// 耐用度
		"prize":	34,		// 價格
		]),
	"grass": ([			
		"chinese":	"青草",		// 中文名稱
		"density":	300,		// 密度
		"hardness":	3,		// 硬度
		"durable":	3,		// 耐用度
		"prize":	3,		// 價格
		]),
	"paper": ([
		"chinese":	"紙",		// 中文名稱
		"density":	300,		// 密度
		"hardness":	3,		// 硬度
		"durable":	4,		// 耐用度
		"prize":	5,		// 價格
		]),
	"plant": ([			
		"chinese":	"植物",		// 中文名稱
		"density":	300,		// 密度
		"hardness":	4,		// 硬度
		"durable":	5,		// 耐用度
		"prize":	4,		// 價格
		]),
	"peel": ([
		"chinese":	"果皮",		// 中文名稱
		"density":	300,		// 密度
		"hardness":	4,		// 硬度
		"durable":	11,		// 耐用度
		"prize":	11,		// 價格
		]),
	"linen": ([
		"chinese":	"麻布",		// 中文名稱
		"density":	350,		// 密度
		"hardness":	4,		// 硬度
		"durable":	8,		// 耐用度
		"prize":	30,		// 價格
		]),
	"cloth": ([
		"chinese":	"布料",		// 中文名稱
		"density":	350,		// 密度
		"hardness":	3,		// 硬度
		"durable":	8,		// 耐用度
		"prize":	26,		// 價格
		]),
	"silk": ([
		"chinese":	"絲綢",		// 中文名稱
		"density":	350,		// 密度
		"hardness":	2,		// 硬度
		"durable":	10,		// 耐用度
		"prize":	38,		// 價格
		]),
	"wood": ([
		"chinese":	"木頭",		// 中文名稱
		"density":	350,		// 密度
		"hardness":	7,		// 硬度
		"durable":	15,		// 耐用度
		"prize":	27,		// 價格
		]),
	"ice": ([
		"chinese":	"冰",		// 中文名稱
		"density":	350,		// 密度
		"hardness":	14,		// 硬度
		"durable":	7,		// 耐用度
		"prize":	10,		// 價格
		]),
	"water": ([			
		"chinese":	"水",		// 中文名稱
		"density":	350,		// 密度
		"hardness":	1,		// 硬度
		"durable":	1,		// 耐用度
		"prize":	2,		// 價格
		]),
	"skin": ([
		"chinese":	"皮革",		// 中文名稱
		"density":	400,		// 密度
		"hardness":	3,		// 硬度
		"durable":	7,		// 耐用度
		"prize":	55,		// 價格
		]),
	"fur": ([			
		"chinese":	"毛皮",		// 中文名稱
		"density":	400,		// 密度
		"hardness":	4,		// 硬度
		"durable":	7,		// 耐用度
		"prize":	68,		// 價格
		]),
	"leather": ([
		"chinese":	"皮甲",		// 中文名稱
		"density":	400,		// 密度
		"hardness":	9,		// 硬度
		"durable":	9,		// 耐用度
		"prize":	72,		// 價格
		]),
	"rubber": ([
		"chinese":	"橡膠",		// 中文名稱
		"density":	450,		// 密度
		"hardness":	8,		// 硬度
		"durable":	25,		// 耐用度
		"prize":	41,		// 價格
		]),
	"jade": ([
		"chinese":	"翡翠",		// 中文名稱
		"density":	550,		// 密度
		"hardness":	20,		// 硬度
		"durable":	35,		// 耐用度
		"prize":	78,		// 價格
		]),
	"gem": ([
		"chinese":	"寶石",		// 中文名稱
		"density":	550,		// 密度
		"hardness":	21,		// 硬度
		"durable":	50,		// 耐用度
		"prize":	82,		// 價格
		]),
	"rock": ([
		"chinese":	"岩石",		// 中文名稱
		"density":	550,		// 密度
		"hardness":	19,		// 硬度
		"durable":	40,		// 耐用度
		"prize":	35,		// 價格
		]),
	"silver": ([
		"chinese":	"銀",		// 中文名稱
		"density":	550,		// 密度
		"hardness":	18,		// 硬度
		"durable":	42,		// 耐用度
		"prize":	85,		// 價格
		]),
	"crimsonsteel": ([
		"chinese":	"赤鐵",		// 中文名稱
		"density":	650,		// 密度
		"hardness":	21,		// 硬度
		"durable":	48,		// 耐用度
		"prize":	62,		// 價格
		]),
	"iron": ([
		"chinese":	"鐵",		// 中文名稱
		"density":	650,		// 密度
		"hardness":	20,		// 硬度
		"durable":	52,		// 耐用度
		"prize":	57,		// 價格
		]),
	"copper": ([
		"chinese":	"銅",		// 中文名稱
		"density":	650,		// 密度
		"hardness":	20,		// 硬度
		"durable":	55,		// 耐用度
		"prize":	81,		// 價格
		]),
	"steel": ([
		"chinese":	"鋼",		// 中文名稱
		"density":	700,		// 密度
		"hardness":	23,		// 硬度
		"durable":	57,		// 耐用度
		"prize":	73,		// 價格
		]),
	"blacksteel": ([		
		"chinese":	"黑鋼",		// 中文名稱
		"density":	700,		// 密度
		"hardness":	24,		// 硬度
		"durable":	59,		// 耐用度
		"prize":	83,		// 價格
		]),
	"gold": ([			
		"chinese":	"黃金",		// 中文名稱
		"density":	700,		// 密度
		"hardness":	17,		// 硬度
		"durable":	45,		// 耐用度
		"prize":	100,		// 價格
		]),
	"glass": ([
		"chinese":	"玻璃",		// 中文名稱
		"density":	700,		// 密度
		"hardness":	25,		// 硬度
		"durable":	45,		// 耐用度
		"prize":	42,		// 價格
		]),
	"diamond": ([			
		"chinese":	"金剛鑽",	// 中文名稱
		"density":	850,		// 密度
		"hardness":	28,		// 硬度
		"durable":	45,		// 耐用度
		"prize":	105,		// 價格
		]),
]);
// 中文名稱
string M_chinese(string material)
{
	if(undefinedp(material_value[material])) return "未知";
	return material_value[material]["chinese"];
}

// 材質資料庫大小
int MDbase_size()
{
	return sizeof(material_value);
}

// 傳出資料庫
mapping M_mapping()
{
	return material_value;
}
// DS 內的體積單位是 block
// DS 內的重量單位為 dsg
//
// 密度		(dsg/block)
//
int M_density(string material)
{
	if(undefinedp(material_value[material])) return 20;
	return material_value[material]["density"];
}
// 硬度
int M_hardness(string material)
{
	if(undefinedp(material_value[material])) return 20;
	return material_value[material]["hardness"];
}
// 耐用
int M_durable(string material)
{
	if(undefinedp(material_value[material])) return 20;
	return material_value[material]["durable"];
}

// 價格
int M_prize(string material)
{
	if(undefinedp(material_value[material])) return 5;
	return material_value[material]["prize"];
}





// 計算基本體積
int Eq_Volume(string material,int weight)
{
	int volume;
	volume = weight / M_density(material);
	if( volume <= 0 )
		volume = 1;
	return volume;
}

// 計算基本傷害力 (改用weight與volume)
int Eq_Damage(string material,int weight,string weapon_type)
{
	int damage;
	
	damage = STD_WEAPON(weapon_type)->weapon_damage(material,weight);
	
//	damage = (M_hardness(material)*weight/5000)+(Eq_Volume(material,weight)/8);
//	if(damage<1) damage=1;
	return damage;
}
// 計算基本價錢 (改用 weight/100*M_prize)
int Eq_Prize(string material,int weight)
{
	int prize;
	weight=weight/100;
	if(weight<1) weight=1;
	prize = M_prize(material)*weight;
	return prize;
}
// 計算基本耐用度
int Eq_Durable(string material,int volume)
{
	int durable;
	durable = M_durable(material)*volume;
	return durable;
}

// 計算物理防禦力
int Eq_Armor(string material,int volume)
{
	int armor;
	armor = (( M_density(material) + M_hardness(material) ) * volume ) / 100;
	return armor;
}