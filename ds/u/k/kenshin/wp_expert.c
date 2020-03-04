#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"Dontpkme武器專家"NOR, ({ "weapons expert","expert","w","e" }) );
        set("chat_chance", 15);
           set("long",@STORY
你可以請他幫你替你的武器註名，或冠上你所喜歡的稱號
使用方法: sign <wp>
STORY);  

        set("combat_exp",5);
        set("score",20);
        set("age",80);
        set("no_kill", 1);
        set("kind", "不明種族");
        set("kill_msg", "別亂殺他,會被巫師罵!\n");
        setup();
}
void init()
{
        add_action("do_wish", "sign");
}

int do_wish(string arg)
{
object me,wp;
me=this_player();

        if(!arg)
                return notify_fail("你想替什麼東西冠名號?\n");
        if( !(wp = present(arg, me)))
                return notify_fail("你身上沒有這種武器。\n");
        if( !wp->query("skill_type"))
                return notify_fail("這不是武器，武器專家只幫你冠武器的稱號。\n");

        write("武器專家從你手上接過"+wp->name()+"問道：你想要冠什麼樣的稱號？\n請輸入：");
          input_to ("test1",me,wp);

                return 1;    
}

int test1 (string rep,object me,object wp)
{
        wp->set("name",rep+wp->query("name"));
        write("\n武器專家說道：依照你的吩咐，完成了！\n");
          return 1;
}

