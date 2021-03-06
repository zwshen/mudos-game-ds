// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "職業技能討論廳");
 set("long", @LONG

  這裡是巫師討論職業技能寫法和發表新技能的地方﹐往上是魔神會議室﹐
往下是任務討論廳。往東走有導師的範例﹐要觀看技能注意事項請輸入
[1;32m about skill[m。這個房間內的導師的技能可以讓任何職業的人學習﹐要
知道寫法請鍵入[1;33m about master[m。
LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "east"   : __DIR__"masterroom",
    "down"   : __DIR__"hall4",
    "up"     : __DIR__"hall6",
 ]));
 set("objects", ([ /* sizeof() == 1 */
	"/u/s/shengsan/npc/swimmaster": 1,
	]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/skill_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
	if(arg=="skill")
	{
		if( file_size("/doc/wiz/skill.txt")>0 )
		{
			this_player()->start_more( read_file("/doc/wiz/skill.txt") );
			write("\n");
		}
		else write(" SORRY. 說明檔尚未建立. \n");
   		return 1;
	}
	else if(arg=="master")
	{
		if( file_size("/u/s/shengsan/npc/swimmaster.c")>0 )
		{
			this_player()->start_more( read_file("/u/s/shengsan/npc/swimmaster.c") );
			write("\n");
		}
		else write(" SORRY. 說明檔尚未建立. \n");
		return 1;
	}
	return 0;
}
