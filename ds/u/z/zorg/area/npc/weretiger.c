#include <ansi.h>
inherit NPC;

void create()
{
        set_name("皮洛", ({"Were Tiger", "tiger","WT"}) );
        set("long", "力大無窮身手靈敏,而且具有人類的智慧,在滿月時更能發揮神秘的力量！\n
聽說只有銀製的武器才能殺的了他!\n");
        set("race", "妖魔");
        set("gender", "男性"); 
        set("age", 83);
        set("attitude", "heroson");
        set("level", 5);
        set("evil", 99);
        set("combat_exp",500);
        set("chat_chance", 1 );    
        set("chat_msg", ({   
        (:command("say 我叫皮洛!!!"):),
        "皮洛看著月亮大笑...... 口圭 口合 口合 口合 ∼∼∼\n",
        (:command("say 月圓!!月圓!!"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("hehe"):),
        (:command("cac"):),
        }) );
        setup();
}

