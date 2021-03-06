// Room: /d/gumu/woshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"臥室"NOR);
        set("long", @LONG
這里是小龍女居住的臥室，房中空空洞洞。右首是一塊長條青石作
床 (bed)，床上鋪了張草席，一幅白布當作薄被，此外除了一根人高的
繩索橫過室中，室左立著一個粗糙木櫥(cabinet)。
LONG    );
        set("item_desc", ([
                "bed" : "一張由普通青石鋪成的床，床角落處，有一塊突起的石板(stone)，似可扳動(twist)。\n", 
                "cabinet" : "一座普通之極的櫥子，不知道是否可以打開(open)。\n", 
        ]));
        set("exits", ([
                "east" : __DIR__"mudao15",
        ]));
        set("chu", 1);
        setup();
}

void init()
{
        add_action("do_tang", "lie");
        add_action("do_ban", "twist");
        add_action("do_open","open");
        add_action("do_xian","lift");
}

int do_tang(string arg)
{
        object me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著。\n");

        if ( arg == "bed")
        {
                message_vision(CYN "$N俯附身躺在青石制成的石床上面。\n"NOR,me);
                me->set_temp("marks/床", 1);
                return 1;
        }
        return notify_fail("你要躺在地上，小心著涼哦！\n");
}  

int do_ban(string arg)
{  
        object me=this_player();

        if (!me->query_temp("marks/床")) {
                write("你沒躺(lie)床上，恐怕用不上力吧！\n");
                return 1;
        }

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著呢！\n");

        if ( arg == "stone")
        {
                if (me->query("ap") < 200)
                        return notify_fail("你使出吃奶的勁力，但石板卻紋絲不動。\n");

                message_vision(HIY "$N用力扳動突起的石板，只聽得軋軋幾響，石床已落入下層石室。\n"NOR,me);
                me->add("ap",-100);
                me->delete_temp("marks/床");
                me->move(__DIR__"shishi0");
                write(HIY"室頂石壁又慢慢自行推上了。\n"NOR);
                return 1;
        }
    return notify_fail("你要扳什麼？\n");
}

int do_open(string arg)
{
        object ob, me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        if ( arg=="cabinet")
        {
                if ( query("chu") == 1 )
                {
                           if(!objectp(present("gold key", me)))  {
                                write("你沒有鑰匙，無法開。\n");
                                return 1;
                        }
                        message_vision("$N慢慢用金鑰匙打開了櫥門。\n",me);
                        ob=new(__DIR__"obj/box");
                        ob->move(environment(me));
                        write("你發現櫥內放著個長方形的鐵盒子，不知道是否可以掀開(lift)。\n");
                    destruct(present("gold key", me));
                        return 1;
                }
                else
                {
                        write("你來晚了，櫥門現在開著呢。\n");
                        return 1;
                }
        }
        write("你要開什麼？\n");
    return 1;
}

int do_xian(string arg)
{
        object suo, me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        if ( arg =="box")
        {
                 if(!(present("iron box", environment(me)))) 
                           return notify_fail("這里沒有任何鐵盒。\n");
                if(!objectp( present("silver key", me)))        
                            return notify_fail("你沒有鑰匙，無法開啟東西。\n");
                me->delete_temp("marks/鐵盒");
                message_vision("$N用銀鑰匙開了鎖，輕輕掀開了鐵盒。\n",me);
                  suo=new(__DIR__"npc/obj/yinsuo2");
                if(!clonep(suo))
                        return notify_fail("你來晚了，盒子里面空無一物。\n");
                write("掀開鐵盒，你發現里面放著一團冰綃般的物事。\n");
                suo->move(me);          
                 destruct(present("iron box", environment(me)));
                  destruct(present("silver key", me));
                return 1;
        }
    return notify_fail("你要掀開什麼？\n");
}


