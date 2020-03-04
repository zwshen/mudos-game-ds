// Room: /open/world1/acme/bonze/b17.c

inherit ROOM;

void create()
{
	set("short", "禪房");
	set("long", @LONG
這裡是得道高僧所居住的地方，此地十分的安靜，一根細針掉在
地上，就有如電擊雷鳴般的響亮。在牆上貼著一幅字畫，上頭畫著一
個和尚，和一字『慈』，在另一面牆供奉著一尊金身佛，卻道不出此
為啥佛尊。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"b14",
]));
set("objects",([
    __DIR__"npc/bonze3.c" : 1,
]) );

        set("light",1);
   set("item_desc",([
    "金身佛" : "一尊純金打造的金佛，你竟聽到陣陣嬰啼聲從佛像背後傳出？\n",
    ]) );

	setup();
}
int i = 0;
void init()
{
        add_action("do_tune","turn");
}


int do_tune(string arg)
{
        object me,staff;
        staff=new(__DIR__"npc/wp/seven-staff.c");
        me=this_player();
        if(!arg || arg!="金身佛") return 0;
            if(i == 1 || me->query("level")<10 || me->query("class1") != "凌雲寺" ) 
                message_vision("$N雙手抱住了金身佛，用力地轉過身來，結果沒有什麼發現。\n",me);
        else
        {
                message_vision("$N雙手抱住了金身佛，用力地轉過身來，似乎發現了什麼？！\n",me);
                staff->move(me);
                i=1;
        }
        return 1;
}
