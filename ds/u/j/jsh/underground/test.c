#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N張大嘴巴朝著$n的$l一陣猛咬",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "咬傷",
        ]),
        ([      "action":               "$N突然往$n的方向撞了過去",
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N對準$n的$l猛然吐出一道寒氣",
                "attact_type":  "bio",
                "damage_type":  "腐蝕",
        ]),
    ([  "action":       "$N憤怒的舞動利爪狂掃$n的$l",
                "attact_type":  "bar",
                "damage_type":  "抓傷",
        ]),
});

void do_clean();

void create()
{
        set_name(HIR"螞蟻王"NOR, ({ "ant king","king" }) );
        set("long",@LONG
本來是一隻小螞蟻, 幾千年前可能是受到某些因素. 身體不知不覺的變大
, 還會說話, 自稱螞蟻王,  但是被古代之勇士所擒, 關在一巨形拱門內, 
不知道有多少年沒出來, 各性也變的兇殘無比。LONG
);
        set("limbs", ({
                "頭部", "頸部", "胸口", "背後","腹部","前腳","後腳","尾巴",
        }) );
        set("title",HIG"蟻中之王"NOR);
        set("age",500+random(140));
        set("level",60);
        set("gender","雄性");
        set("race","monster");
        set("attitude", "aggressive");
        set_skill("mob_bite", 100);
        set("addition_armor",92);
        set("Merits/wit",5);
        add("apply/hit",60);
        set("addition_damage",600); 
        set("addition_armor",600);
        set("chat_chance_combat", 24);
        set("chat_msg_combat", ({
                (:command("say 哈哈哈哈哈.."):),
                         }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object(__DIR__"redarmor")->wield(); 
        carry_object(__DIR__"redtooth");}
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
        HIG"\n  [快      報] "+HIR "兇殘的「 螞 蟻 王 」被+ob->name(1)+"殺死了。\n\n"+NOR,users());
        ob->add("popularity",2+random(4)); //聲望
        ::die();
        //destruct(this_object());
        return;
}

