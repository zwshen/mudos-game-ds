#include <ansi.h>
inherit NPC;
void create()
{
        set("title", WHT"笑紅塵親衛隊隊長"NOR );
        set_name( HIG"曼陀羅"NOR , ({ "showro" }) );
        set("level",100);
        set("race","人類");
        set("gender","男性");
        set("age",17);
        set("nickname", RED"盡忠職守的強人"NOR);
        set("long","不知那來的怪物。\n");
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        setup();
        carry_object("/u/f/fanny/wp/ssword.c")->wield();
add_money("coin", 99999);
}
void init()
{
         add_action("do_force","force");
}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="fanny")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕force <某鬼魂> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}
