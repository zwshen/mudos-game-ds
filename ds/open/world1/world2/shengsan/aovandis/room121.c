// 奧凡迪斯

// LV 1~50
#include <ansi.h>
#include <path.h>
inherit ROOM;

string l_cabinet();
string l_rack();

void create()
{
	set("short", HIC"市立圖書館閱\覽室"NOR);
	set("long", @LONG
這間閱覽室裡的雜誌文獻很豐富，從當代最流行的時尚雜誌到專業的
技術性雜誌都有，每本雜誌皆整齊的擺放在大型展示櫃(cabinet)中。另
外還有各家報社的報紙掛在架子(rack)上。在牆角有台影印機(photostat)
供人複製影印。牆上有個告示牌(note)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room122",
	    "down" : __DIR__"room073",
            ]));

	set("objects", ([
		__DIR__"npc/obj/photostat":1,
	]));

	set("item_desc", (["note":@NOTE
佈告牌上寫著:

	這裡的報章雜誌並不能外借，如果需要裡面的資料，
	請多多利用影印機(photostat)。
	如果要拿架上的雜誌請用 getmagazine
NOTE
        ,"photostat":@NOTE
這台影印機看起來非常的高級，如果需要影印資料，用它就沒錯了。
NOTE
        ,"cabinet": (: l_cabinet :)
        ,"rack": (: l_rack :)
	]) );

	set("no_clean_up", 0);
	set("no_recall",1);
	set("light", 1);

	set("magzroom",SHENGSAN2"aovandis/magzroom");

	setup();
}

void init() 
{
//	::init();
	add_action("do_getmagazine","getmagazine");
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int do_getmagazine(string arg)
{
	object magzroom,me,ob;

	if(!arg) return notify_fail("getmagazine 雜誌\n");
	if(!magzroom=load_object(this_object()->query("magzroom"))) return 0;
	me = this_player();

	if(ob=present(arg,magzroom))
	{
		if(!me) return 0;
		if(!ob->is_magzine())
			write("「"+ob->query("name")+"」並不是一本雜誌喔。\n");
		else
		{
	 		ob->move(me);
	 		magzroom->save();
			me->save();
			message_vision("$N從大型展示櫃中取出一本「"+ob->query("name")+"」。\n",me);
		}
	}
	else
		write("啊？你確定有「"+arg+"」嗎？。\n");

	return 1;
}

string l_cabinet()
{
	object *magzs,magzroom;
	int i,j,gotit;
	string line;

	if(!magzroom=load_object(this_object()->query("magzroom"))) return "?_?\n";
	if(!magzroom) return "?_?\n";
	magzs = all_inventory(magzroom);
	magzs = sort_array(magzs, "sort_item", this_object());

	line = sprintf(	"============================================================\n"
			"=    雜                                      誌    = 數 量 =\n"
			"============================================================\n",);
	for(i=0;i<sizeof(magzs);i++)
	{
		if(!magzs[i]->is_magzine())
			continue;
		line += sprintf(
			"= %-26s%-22s = %5d =\n",
			magzs[i]->query("name"),
			"("+magzs[i]->query("id")+")",
			1);
		gotit++;
	}
	if(gotit)
		line += sprintf("============================================================\n");
	line += sprintf("共搜尋到 %d 筆符合條件的資料...\n",gotit);

	this_player()->start_more(line);

	return "";
}

string l_rack()
{
	return "這個架子上放著今天最新的報紙。\n";
}