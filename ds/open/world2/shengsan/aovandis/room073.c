// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"市立圖書館"NOR);
	set("long", @LONG
圖書館可說是知識的寶庫，這座市立圖書館已經有好幾千年的歷史了
，歷代的市長都曾經做過規模不一的修整建設，裡面的藏書可說是相當的
豐富。清爽乾淨的環境，古色宏偉的建築加上現代化的設備，這座圖書館
已經成為奧凡迪斯的地標之一了。牆上有個告示牌(sign)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room019",
	    "up"   : __DIR__"room121",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/lib_mem0.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE

佈告牌上寫著:

	請自行到樓上拿欲借的書本到這裡像服務人員辦理借閱手續，
	如果私自帶出館外將會受到法律制裁。

		borrow    借書
		return    還書

NOTE
        ]) );
	set("no_clean_up", 0);
	set("light", 1);
	set("no_recall",1);
	set("valid_startroom",1);

	setup();
//	replace_program(ROOM);
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i,j,bookno,bookdate,coun;
	string *item,*ids,markid;
        if( dir=="north" )
	{
		ob = all_inventory(me);
		ob = sort_array(ob, "sort_item", this_object());
		item = me->query("aovandis/library");
		for(i=0;i<sizeof(ob);i++)
		{
			coun = 0;
			if(ob[i]->is_book())
			{
				for(j=0;j<sizeof(item);j++)
				{
					if(sscanf(item[j],"book%d_%d",bookno,bookdate)!=2)
						continue;
					if(ob[i]->query("id") == "book"+(string)bookno)
					{
						coun = 1;
						if(markid == ob[i]->query("id"))
							coun++;
						else
							markid = ob[i]->query("id");
					}
				}
				if(coun>=2)
					return notify_fail("請不要帶走兩本以上的『"+ob[i]->query("name")+"』。\n");
				else if(coun<=0)
					return notify_fail("『"+ob[i]->query("name")+"』是圖書館的圖書，請辦好借書手續再行離開。\n");
			}
			else if(ob[i]->is_magzine() && !ob[i]->is_copy())
				return notify_fail("本圖書館並不外借「"+ob[i]->query("name")+"」(雜誌)喔。\n");
		}
	}
        return ::valid_leave(me, dir);
}
