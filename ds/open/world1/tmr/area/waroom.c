// Room: /u/t/tmr/area/waroom.c

inherit ROOM;

void create()
{
        set("short", "湖心小屋");
        set("long", @LONG
一間用竹子編織而成小屋，房舍小巧玲瓏，頗為精雅。小舍匾額上寫
著「淡泊」二字，筆致極為瀟洒。屋內除了幾張竹檯、竹椅，並沒有什麼
特殊之處。屋外只有一張梯子，你剛搭乘而來的小舟卻已不知去向，看樣
子，要離開這裡，也只有游泳回去了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wa1",
]));
        set("light",1);
set("item_desc",([
"匾額":"一塊已頗破舊的匾額，不知是否錯覺，你覺得匾額後頭發出些黃色光芒！？\n",
]) );

        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_search","search");
}

void clear() {
        delete_temp("search");
}

int do_search(string arg)
{
        object me,fist;
        if( !arg || arg!="匾額" ) return 0;
         me=this_player();
        if( me->query("level") > 14 && !query_temp("search") )
        {
          message_vision("$N搜了搜上頭的匾額，忽然掉了一件金黃色的物事。\n",me);
          fist=new(__DIR__"npc/wp/sun-snow-fist");      
          fist->move(environment(me) );
          set_temp("search",1);
        call_out("clear", 900); // 15min
        }
        else
        {
                message_vision("$N搜了搜上頭的匾額，結果什麼也沒有發現。\n",me);
        }               
        return 1;
}

