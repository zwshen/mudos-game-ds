// marryd.c
#include <marry.h>
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;

mapping	marry_house;
mapping	marry_baby;

string *do_sort_record(string type,string *keys);
void resort_record();

void create()
{
        seteuid(getuid());
        if( !restore() )
        {
		marry_house =
		([
       			"h0" : 	([
       				"created":	1,
				"bought":	0,
				"ppl1" :	"none1",
				"ppl2" :	"none2",
				"locate" :	"/open/world2/shengsan/marryhome/data/housedata/samplehouse",
				"childnum" :	0,
				"short" :	"愛的小窩",
				"long" :	"能有一間屬於自己的房子一直以來都是大部分人所努力的目標，而這\n間房屋正好可以滿足已婚男女的需求。如果您買下了這間『愛的小窩』，\n您就會發現這處人生的避風港為您的家庭所帶來的種種好處，不要猶豫了\n，這麼好的房子不好找嚕。一張廣告單就貼在佈告欄(notice)上。",
				]),
		]);
        	marry_baby =
        	([
        		"h0" :	([
				"child1" :	([
						"babyroom" : "/open/world2/shengsan/marryhome/data/housedata/samplebabyhouse",
						"id" : "child1",
						"level" : 1,
						"title" : "BABY",
						"name" : "小孩一",
						"sk1" : "babysk1",
						"sk1lv" : 1,
						]),
        			]),
        	]);
        }
        else
        {
        	if( !mapp(marry_house) ) marry_house = ([]);
        	if( !mapp(marry_baby) ) marry_baby = ([]);
        }
        //save();
}

string query_save_file() { return DATA_DIR + "marry"; }

int creat_basehouse(string houseid)
{
	marry_house[houseid] = ([]);
	marry_house[houseid]["created"] = 1;
	marry_house[houseid]["bought"] = 0;
	marry_house[houseid]["ppl1"] = "";
	marry_house[houseid]["ppl2"] = "";
	marry_house[houseid]["locate"] = "";
	marry_house[houseid]["childnum"] = 0;
	marry_house[houseid]["short"] = "愛的小窩";
	marry_house[houseid]["long"] = "能有一間屬於自己的房子一直以來都是大部分人所努力的目標，而這\n間房屋正好可以滿足已婚男女的需求。如果您買下了這間『愛的小窩』，\n您就會發現這處人生的避風港為您的家庭所帶來的種種好處，不要猶豫了\n，這麼好的房子不好找嚕。一張廣告單就貼在佈告欄(notice)上。";
	return 1;
}

int set_house_ppl1(string houseid,string str)
{
	marry_house[houseid]["ppl1"] = str;
	save();
	return 1;
}

int set_house_ppl2(string houseid,string str)
{
	marry_house[houseid]["ppl2"] = str;
	save();
	return 1;
}

int set_house_locate(string houseid,string str)
{
	marry_house[houseid]["locate"] = str;
	save();
	return 1;
}

int set_house_childnum(string houseid,int num)
{
	marry_house[houseid]["childnum"] = num;
	save();
	return 1;
}

int add_house_childnum(string houseid,int num)
{
	if(undefinedp(marry_house[houseid]["childnum"]))
		return 0;
	marry_house[houseid]["childnum"] += num;
	save();
	return 1;
}

int set_house_short(string houseid,string str)
{
	marry_house[houseid]["short"] = str;
	save();
	return 1;
}

int set_house_long(string houseid,string str)
{
	marry_house[houseid]["long"] = str;
	save();
	return 1;
}

int query_house_created(string houseid)
{
	if(undefinedp(marry_house[houseid]))
		return 0;
	else
		return 1;
}

string query_house_short(string houseid)
{
	string str = "";
	if(!undefinedp(marry_house[houseid]["short"]))
		str = marry_house[houseid]["short"];
	return str;
}

int query_house_bought(string houseid)
{
	int i = 0;
	if(!undefinedp(marry_house[houseid]["bought"]))
		i = marry_house[houseid]["bought"];
	return i;
}

string query_house_long(string houseid)
{
	string str = "";
	if(!undefinedp(marry_house[houseid]["long"]))
		str = marry_house[houseid]["long"];
	return str;
}

