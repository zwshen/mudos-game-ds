#include <ansi.h>
inherit NPC;
void combat_ai();

void create()
{
        set_name("黃飛虎" , ({ "huang fei-hu", "huang", "hu" }) );
        set("long",@long
黃飛虎是寒澈派近一代的傑出弟子，長得雄壯威武，一雙大眼非常有神。
long
);
        create_family( "寒澈派", 3, "以心契道");
        set("level", 25);
        set("race","human");
        set("age",40);
        set("class1","寒澈派");
        set("gender","男性");
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("fall-thunder",100);

          set("chat_chance", 5);
        set("chat_msg",({
                (: command("bow") :),

        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        setup();
        carry_object(__DIR__"wp/tiger-claw")->wield();
        carry_object(__DIR__"eq/green-pants")->wear();
        add_money("gold",1);
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");

}

void combat_ai()
{
        int i;
        object *target;
        object liu=this_object();

        target = all_inventory(environment(liu));

        /* 武器被打掉，則裝回去 */
        if( !liu->query_temp("weapon") ) 
                command("wield fist");

        i = sizeof(target);
        while( i-- )
        {
                if( liu->is_killing(target[i]) || liu->is_fighting(target[i]) )
                {
                        if( !target[i]->is_busy() ) continue;
                        if( userp(target[i]) )
                                 command("cast fall-thunder on " + getuid(target[i]) );
                        else
                                command("cast fall-thunder on " + target[i]->query("id") );
                            return;
                }
        }
        // 找不到busy的敵人，就發封寒球
        command("cast freeze-ball");
        return;
}

