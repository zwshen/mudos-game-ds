#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N猛然喝到『動！』，$n的全身像是被拆散了一樣",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "怪傷",
        ]),
        ([      "action":               "$N一招『霸氣凌雲』往$n的地方掃去！",
                "attact_type":  "bar",
                "damage_type":  "掃傷",
        ]),
     ([      "action":               "$N突然向$n用手發出一道念力",
                "attact_type":  "bio",
                "damage_type":  "內傷",
        ]),
        ([      "action":               "$N運用念力使$n向後撞去",
                "attact_type":  "bar",
                "damage_type":  "撞傷",
        ]),
});

void do_clean();

void create()
{
     set_name(HIC"金•狂"NOR,({"gin kin","kin"}) );
        set("long",@LONG
他，傳說中的念力高手，行事亦正亦邪，雖然手上有槍，但是從他身
上的無形散發出氣息看來，他的念力比手中的槍還來的厲害？！
LONG
);
        set("title","『狂人』");
         set("age",80);
     set("level",60);
        set("gender","男性");
       set("race","human");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "金•狂的四周響起了爆破的聲音？\n",
        "金•狂嘆了一口氣。\n",
        "金•狂緩緩的舉起手，像桌子揮了一揮。\n",
        "金•狂身上的念力慢慢的散發出來。\n",
        }));
          set("addition_armor",100);
    set("Merits/wit",3);
        set("addition_damage",50);
        add("apply/hit",50);

        setup();
       carry_object(__DIR__"obj/g_plate.c");
        set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void init()
{
      ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{
        if( (arg!= "back") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "突然感到一股勁氣讓你走不過去！\n");
         command("smile");
           say("金•狂說道："HIB"閣下為何入寶庫，而空手而回呢？\n"NOR);
       return 1;
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
     message("world:world3:vision",
HIG"\n【獵人特報】"+HIW"獵人之傳說神話-"HIC"金•狂"HIW"敗在"+ob->name(1)+"的手下！！\n\n"+NOR,users());
           ob->add("popularity",4);
        ::die();
        return;
}

