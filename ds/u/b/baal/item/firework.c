#include <ansi.h>
inherit ITEM;

void delay();

void create()
{
        set_name(HIR"煙火"NOR,({"firework","firework"}) );
        set("long","
煙火─索思專用...^^\n"
        );
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        setup();                
}

void init()
{
       add_action("typefire","fire");
}

int typefire(string arg)
{
        object me;
        me=this_player();
        if( arg != "煙火" && arg != "firework" && arg != "work" ) return 0;
        message("world:world1:vision",
MAG"\n  索思陰沉的聲音從罪惡的深處中傳來:\n\n\t"RED"擁有血肉的人類們呀！盡情的迎接新世紀的到來吧！但是別忘了，"MAG"死靈們"RED"將長伴與你！！\n\n"+NOR
        ,users());
        return 1;
}


