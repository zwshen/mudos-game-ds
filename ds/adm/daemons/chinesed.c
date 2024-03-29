// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95
// #pragma save_binary
#include <localtime.h>

#define DICTIONARY DATA_DIR + "chinese"

inherit F_SAVE;

nosave string *c_digit = ({ "零","十","百","千","萬","億","兆" });
nosave string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
nosave string *sym_tien = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
nosave string *sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
nosave string *month_name = ( {
			"冰神", "光明", "海嘯", "戰神", "聖靈",
			"雷神", "花語", "愛神", "七星", "炎龍",
			"黑暗", "邪靈"
			} );

mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
	seteuid(getuid());
	restore();
}

void remove() { save(); }

string chinese_number(int i)
{
	if( i<0 ) return "負" + chinese_number(-i);
	if( i<11 ) return c_num[i];
	if( i<20 ) return c_num[10] + c_num[i-10];
	if( i<100 ) {
		if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
		else return c_num[i/10] + c_digit[1];
	}
	if( i<1000 ) {
		if( i%100==0 )
			return c_num[i/100] + c_digit[2];
		else if( i%100 < 10 )
			return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
		else if( i%100 < 20 )
			return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
		else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
	}
	if( i<10000 ) {
		if( i%1000==0 )
			return c_num[i/1000] + c_digit[3];
		else if( i%1000 < 100 )
			return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
		else
			return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
	}
	if( i<100000000 ) {
		if( i%10000==0 )
			return chinese_number(i/10000) + c_digit[4];
		else if( i%10000 < 1000 )
			return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
		else
			return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
	}
	if( i<1000000000000 ) {
		if( i%100000000==0 )
			return chinese_number(i/100000000) + c_digit[5];
		else if( i%100000000 < 10000000 )
			return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
		else
			return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
	}
		if( i%1000000000000==0 )
			return chinese_number(i/1000000000000) + c_digit[6];
		else if( i%1000000000000 < 100000000000 )
			return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
		else
			return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
}

string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun
string chinese(string str)
{
	if( !undefinedp( dict[str] ) ) return dict[str];
	else return str;
}

mapping query_dict()
{
	return dict;
}

void remove_translate( string key )
{
	map_delete( dict, key );
	save();
}

void add_translate( string key, string chinz )
{
	dict[key] = chinz;
	save();
}

varargs string dump_translate(int flag)
{
	string *k, str;
	int i;

	str = "";
	k = keys(dict);
	for(i=0; i<sizeof(k); i++)
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	if(flag) write_file("/CHINESE_DUMP", str);
	return str;
}

string chinese_date(int date)
{
	mixed *local;

	local = localtime(date);

	return sprintf("%s%s年%s月%s日%s時%s刻",
		sym_tien[local[LT_YEAR]%10], sym_dee[local[LT_YEAR]%12],
		chinese_number(local[LT_MON]+1),
		chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
		sym_dee[((local[LT_HOUR]+1)%24)/2],
		chinese_number((local[LT_MIN]+1)%2 * 2 + local[LT_MIN]/30 + 1) );
}

string ds_date(int date,int a)
{
	mixed *local;
	int i;

	local = localtime(date);

	switch(a)
	{
		case 3: i = 3333;break;	// 未來
		case 2:	i = -22; break;	// 現代
		case 1:			// 古代
		default:i = -2000;
	}
	return sprintf("[1;35m☆夢幻時刻：[1;31m夢幻%s年[1;32m%s之月[1;33m第%s日[1;37m%d[5m:[0;1;37m%2d[1;35m☆[m",
			replace_string(chinese_number(local[5]+i),"負","[36m前[31m"),
			month_name[local[4]%12],
			chinese_number(local[3]),
			local[2],local[1]);	

}

//add by tmr 2006/11/16
string chinese_month(int date)
{
        mixed *local;
        
        local = localtime(date);
        
        return sprintf("%s", chinese_number(local[LT_MON]+1) );
}
