// Room: /future/area/digging_road10.c

inherit ROOM;

void create()
{
	set("short", "礦洞裡");
	set("long", @LONG
你正在一處礦洞裡，礦洞東西寬約五、六十公尺，洞壁上每隔五公尺
就設一「Ｈ２Ｏ離合發光燈」，照得礦洞裡白亮如晝，四周圍除了採礦的
礦工之外，還有幾台輔助採礦作業的半人型運礦車。你不經意地看到腳旁
的礦壁似乎發出些金黃色光芒。
LONG
	);
	set("world", "future");
	set("light",1);
	set("item_desc",([
	"H2O離合發光燈":
"H2O離合發光燈為二十世紀未所發明出來的，發光原理為離合\n"
"水(H2O)中的氫、氧來發光，其所需能源就只需清水。\n",
	"半人型運礦車":
"半人型運礦車為運礦車為底，車頭有二隻夾礦用機器手臂，中\n"
"有一小型半AI的電子腦，為舊世界採礦時熱門的輔助機器人，現今已\n"
"少有人用。\n",
               "礦石":
"一種新發現的原料，現時人們都不太普遍採用，但現在有商人\n"
"在大量收購這些礦石，看來將它掘(excavate)出來賣掉會有可觀的收入。\n",
	]) );
              set("mineral",100); //礦石數量
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "northeast" : __DIR__"digging_road7",
	]));

	setup();
}
void init()
{
               add_action("do_excavate","excavate");
}
int do_excavate(string arg)
{

        object me,silvery;
        me = this_player();
        if(!arg || arg!="礦石")
                return notify_fail("你要挖什麼呢?\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒空進行採礦工作。\n");
        if(me->query("hp") < 10)
                return notify_fail("你的身體狀況不好，無法進行挖礦工作。\n");
        
        message_vision("$N細心地推毃各面的礦壁...\n",me);
        me->receive_damage("hp",5);
        me->start_busy(3);

        if( query("mineral") && random(80) > 50 )
        {
        message_vision("$N驚呼一聲，似乎挖掘到了一塊暗紅色的礦物。\n",me);
        silvery = new(__DIR__"npc/obj/mineral.c");
        silvery->move(me);
        set("mineral",-( 1+random(2) ) );
        }
        else 
        {
        message_vision("$N擦了擦額頭上的汗，似乎沒什麼發現。\n",me);
        }
        return 1;
}