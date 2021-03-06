inherit ROOM;

void create()
{
        set("short","破陋小廟");
        set("long",@LONG
你正站在一間破陋小廟裡，你環顧了一下四周，發現廟裡前後左
右雖殘而不破，整座小廟宇還給你一種份外詳和的感氣，彷彿塵俗間
一切的貪婪、殺戮都不會在此發生。
LONG
        );
        set("world","past");
        set("exits",([/*sizeof()==3*/
                "southeast":__DIR__"hill4.c",
        ]));
//      set("outdoors","forest");
        set("no_clean_up",0);

set("item_desc",([ 
"山縫":"剛好是一個人可以過去(climb)的縫隙，剛好夾在凌雲頂峰下。\n",
"般若心經經文":@LONG
觀自在菩薩，行深般若波羅密多時，照見五蘊皆空，
渡一切苦厄。舍利子，色不異空，空不異色，色即是空，
空即是色，受想行識，亦復如是。舍利子，是諸法空相，
不生不滅，不垢不淨，不增不減，是故空中無色，無受想
行識，無眼耳鼻舌身意，無色聲香味觸法，無眼界，乃至
無意識界，無無明，亦無無明盡，乃至無老死，亦無老死
盡，無苦集滅道，無智亦無得，以無所得故，菩提薩埵，
依般若波羅密多故，心無罣礙，無罣礙故，無有恐怖，遠
離顛倒夢想，究竟涅槃，三世諸佛，依般若波羅密多故，
得亞耨多羅三藐三菩提，故知般若波羅多，是大神咒，是
大明咒，是無上咒，是無等等咒，能除一切苦，真實不虛
。故說般若波羅密多咒，即說咒曰：揭諦揭諦，波羅揭諦
，波羅僧揭諦，菩提薩婆訶。
LONG 
]));
        set("objects", ([
                __DIR__"npc/bonze_adv_master.c" : 1,
                ]));

        setup();
}
void init()
{
}
int do_climb(string arg)
{ 
    object me=this_player();
    if(!arg || arg !="山縫") return notify_fail("你要爬(climb)什麼?\n"); 
    {
    message_vision(""+me->name(1)+"手腳並用的，慢慢的爬進山縫裡••\n",me); 
    tell_room(environment(me),me->query("name")+"擠了過來。\n",me );
    me->start_busy(5);
    call_out("CLIMB_ON",5,me);
    }
    return 1;
}
void CLIMB_ON()
{ 
     object me=this_player();
     message_vision(""+me->name(1)+"小心翼翼的爬上山壁••到了！到了山頂了。\n",me);  
     {
     me->move("/open/world1/jangshow/fox_area/taroom");
     me->start_busy(2);  
     }
     return;
}
