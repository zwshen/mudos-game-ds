#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":              "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIY+"伏魔訣"+NOR+""+CYN+"】"+NOR+"一道金光閃過$n的$l!",

                "attact_type":  "sou",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+MAG+"天罡\訣"+NOR+""+CYN+"】"+NOR+"一道紫光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIR+"破邪訣"+NOR+""+CYN+"】"+NOR+"一道紅光閃過$n的$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIC+"凍妖訣"+NOR+""+CYN+"】"+NOR+"一道藍光閃過$n的$l!",
                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIM+"詠日訣"+NOR+""+CYN+"】"+NOR+"一道橙光閃過$n 的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+GRN+"劍氣訣"+NOR+""+CYN+"】"+NOR+"一道綠光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIW+"滅殺訣"+NOR+""+CYN+"】"+NOR+"一道白光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+WHT+"四傲訣"+NOR+""+CYN+"】"+NOR+"一道灰光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+YEL+"地土訣"+NOR+""+CYN+"】"+NOR+"一道褐光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
});

void do_clean();

void create()
{
        set_name(WHT"雲遊僧"NOR,({"monk"}) );
        set("long",@LONG
這是一個四處雲遊的雲遊僧, 不過他在這裡幹什麼呢?
LONG
);
        set("title",CYN"「傳遞者」"NOR);
        set("age",1200+random(50));
        set("level",50);
        set("gender","男性");
 set("attitude", "peaceful");
        set("chat_chance", 30);
        set("chat_msg",({ 
        "雲遊僧不信任的看著你....。\n",
        "雲遊僧問你道: 苗家村來的?。\n",
        }));
        set_skill("staff", 100);
      set("Merits/sou",4);
      set("int",175);
          set("addition_armor",100);
    set("Merits/wit",3);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
      carry_object(__DIR__"eq/world_staff")->wield();

        set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",

           HIR"\n【十萬大山】"+MAG"雲遊僧臨死前呼喊道：殞星道友...剩下來的交給你了.....\n\n"+NOR,users());
            ob->add("popularity",5+random(2)); //聲望
        ::die();
        return;
}


int accept_object(object who,object ob)
{
                object obj,me;
                obj=this_object();
                me=this_player();
                if(ob->name()!="青木令")
                {
                 command("? "+who->query("id"));
                 return 0;
                }
                else {
                 if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" 嗯...可以了。");
                 return 0;
                }
                message_vision("$N給了雲遊僧一個"+ob->query("name")+"。\n",who);
                message_vision("雲遊僧對$N說道: 可以了..過去吧。\n",who);   
                message_vision("雲遊僧忽然運起掌力, 將$N掃向山腰下!!\n",who); 
                 destruct(ob);
                 me->move("/open/world1/faceoff/sky/ten39");
                 return 1;
               }

}
