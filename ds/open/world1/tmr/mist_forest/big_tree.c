// File: /d/mist_forest/big_tree.c
// Updated by tmr (Sat May 18 12:20:14 2002)

inherit ROOM;

void create()
{
          set("short", "不知名的大樹");
          set("long", @LONG
你正站在一棵不知名的大樹前，四周正佈滿著一層層濃厚的白霧，陣
陣的涼意直衝心頭，在溼冷的空氣中，似乎有一絲絲酒味和鼾聲傳來，不
知還有誰待在這邊。
LONG
          );
          set("exits", ([ /* 1 element(s) */
                "south" : __DIR__"map_1_1",
        ]));
	set("detail",([
                "大樹":"你抬頭望了大樹上的一根橫枝，似乎正有人在上面打旽。\n",
                "人" : "遠遠望去看不清楚長啥樣兒，你不禁心生歹念「把他從大樹上搖下來瞧個清楚」。\n", // add by -Acme-
        ]));
          set("outdoors", "forest");

        setup();
}

int quest_ok=1;

void reset()
{
        ::reset();
        quest_ok=1; //又能解迷了
}

void init()
{
        ::init();
        add_action("do_shake","shake");
}
int do_shake(string arg)
{
        object me=this_player();
        object ob;
        if(!arg || arg!="大樹") return 0;
        if( !quest_ok
        || objectp(ob=present("drunk evil monster" ) ) ) {
                message_vision("$N使力地搖了搖樹幹，但是除了幾片落葉落下，就什麼事也沒有了。\n",me);
        
        } else {
                ob=new(__DIR__"npc/drunk-evil-monster");        
                message_vision("$N使力地搖了搖樹幹，結果上頭竟有人噗咚一聲摔了下來。\n",me);
                quest_ok=0;
		ob->move(this_object());
                ob->do_chat("喝醉的魔獸唉呀一聲，似乎是摔疼了。\n");
        }
        return 1;
}
