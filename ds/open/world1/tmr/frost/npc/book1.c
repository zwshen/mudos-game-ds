#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$n細讀道德部「老君指歸」一章，苦思不得其解",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "道德部中一行「夫物之所以生，功\之所以成，必生乎無形，形由乎無名」，$n苦思良久仍然無法領會",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n仔細鑽研「物從道生」的涵義，但苦思良久，仍不知其所指",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n細讀「大道隱，世教衰，天下方大亂」的文字，但卻越讀越心煩意燥",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("道德部",({"morality book" ,"book", "_MORALITY_BOOK_"}));
        set("gender", "男性");
        set("long",@LONG
這是道派道藏中最有名「雲笈七籤」中的道德部。裡頭開宗
明義寫著「太上之象，莫高乎道德；其次莫大乎神明；其次莫大
乎太和；其次莫崇乎天地；其次莫著乎陰陽；其次莫明乎大聖。
夫道德，所以可道而不可原也」。
LONG
        );
        set("level",30);
        set("age",300);
        set("title","雲笈七籤");
        set_skill("parry", 100);
        set_skill("block", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("attitude", "aggressive");
          set("attack_merits", "sou");
        set_temp("fly",1);

        setup();
        set_temp("apply/damage",100);
        set_temp("apply/armor",200);
        set_temp("apply/shield",200);
        if(random(10)>=8) carry_object(__DIR__"obj/book1");
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        ob->add("popularity", 1);
        tell_object(ob,HIG "(你的聲望增加一點了。)\n" NOR);

        ::die();

        return;
}

