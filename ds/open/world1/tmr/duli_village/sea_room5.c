// File: /d/duli_village/sea_room5.c
// Updated by tmr (Tue May  7 20:44:37 2002)

inherit ROOM;

void create()
{
          set("short", "大海洋底下");
          set("long", @LONG
你正潛游在一片水藍藍的海洋底下，你身處在這個寂靜的世界上，慢
慢地已經分不清東南西北了，微微波動的海流正輕拂過你的身軀。正當你
浮游過海底的一片沙地時，似乎注意到一絲絲紅光。
LONG
          );
          set("exits", ([ /* 1 element(s) */
        "up" : __DIR__"sea_room",
]));
        set("detail",([
                  "沙地":"你注意到在海底有一處隆起的沙地，似乎埋著什麼東西？\n",
        ]));

        setup();
}
int quest_ok=0;
void reset()
{
        ::reset();
        quest_ok=0;
}
void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me=this_player(),jawei;
        if(!arg || arg!="沙地")
                return 0;
        if(quest_ok){
                message_vision("$N伸手撥散了沙地，卻沒有發現到什麼。\n",me);
        } else {
                jawei=new(__DIR__"npc/obj/jawei");
                if(!jawei->move(me))
                        jawei->move(environment(me));
                message_vision("$N伸手撥散了沙地，赫然發現一塊紅色的寶石！\n",me);
		quest_ok=1;
        }
	return 1;
}

