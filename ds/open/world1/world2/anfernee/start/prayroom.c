#include <path.h>

inherit ROOM;
//string look_sign(object me);
void greeting(object me);
void create()
{
	set("short", "時空神殿");
	set("long", @LONG
這裡是旅館附設的神殿。許多虔誠的信奉者都喜歡在這裡靜思修身，
這裡的靈氣很強，所以常常吸引許多孤魂野鬼聚集在此接受神賜的恩典。
這裡有兩座神像，分別是掌管生命之神[Shengsan]和掌管死亡之神[Luky]
的雕像(statues)。

                      ╳  
                        ╲  
                     _Ω_.O.           k
                    /\__.\/ ╲      O  |
                    \/__\         ()Y==o
                     | :|          /_\ |   
                     | :|          _W_ |   
                   ▆██▆      ▆██▆
                   ████      ████
 ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hall",
	]) );
	set("item_desc", ([
		"statues": "  兩座純銅打造的雕像(statue of luky)(statue of shengsan), 你看\n"+
		           "到有些半透明靈體正圍繞著其中一個雕像膜拜(pray)著。\n\n",
	]) );
	set("hide_item_desc", ([
		"statue of luky": @STATUE_L
  一尊十分嚴肅的雕像，一手持盾一手持矛，就像是傳說中主宰死界的魔神
  的形貌。
STATUE_L,
		"statue of shengsan": @STATUE_S
  你很好奇為什麼這兩個神像會放在一起，和旁邊嚴肅的雕像比起來，這尊
雕像似乎慈祥許多，給人一種安全舒服的感覺。
STATUE_S,
		"luky": @STATUE_L2
  一尊十分嚴肅的雕像，一手持盾一手持矛，就像是傳說中主宰死界的魔神
的形貌。
STATUE_L2,
		"shengsan": @STATUE_S2
  你很好奇為什麼這兩個神像會放在一起，和旁邊嚴肅的雕像比起來，這尊
雕像似乎慈祥許多，給人一種安全舒服的感覺。
STATUE_S2,
		
	]) );
	set("light",1);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}

void init()
{
 add_action("do_pray","pray");
 if(this_player()->is_ghost()) call_out("greeting",20,this_player());
}

void greeting(object me)
{
        if( !me ) return;
	if(environment(me)==this_object() && me->is_ghost())
		write("�[1m[提示] 你已經失去了軀體，下 pray luky 指令可以讓你復活。�[0m\n");
	return;
}

int do_pray(string arg)
{
	object me;
	me=this_player();
 
 if(!arg) return notify_fail("你想對哪一個雕像祈禱呢?\n");
 if(arg=="luky")
 {
	if(me->is_ghost())
 	{
 	 me->reincarnate();
        me->delete_temp("kill_love");
	 message_vision("�[1m$N虔誠的向死亡之神祈禱，突然一陣光芒照射在$N身上，$N復活了。�[0m\n", me);
	 return 1;
	} else return notify_fail("你虔誠的像雕像祈禱，覺得心情平靜了許\多。\n");
 }
 
 if(arg=="shengsan")
 {
 	if(me->is_ghost()) return notify_fail("�[1m天上傳來冰冷的聲音: �[33m我只能幫助有生命的人，你還是找其他神幫你吧。�[0m\n");
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
 	 me->reincarnate();
	 message_vision("�[1;32m$N虔誠的向生命之神祈禱，突然一陣光芒照射在$N身上。�[0m\n", me);
	 tell_object(me,"你的身體狀況完全回復了。\n");
	 return 1;
	} else return notify_fail("你虔誠的像雕像祈禱，覺得心情平靜了許\多。\n");
 }
 if(arg=="statues" || arg=="statue") return notify_fail("你想對哪一個雕像祈禱呢(shengsan),(luky)?\n");
 return 0;
}

int valid_leave(object me, string dir)
{
        if( dir=="down" && me->is_ghost() )
                return notify_fail("你還是鬼魂。(pray luky可以復活)\n");
        return ::valid_leave(me, dir);
}
