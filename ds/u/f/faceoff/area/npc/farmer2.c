#include <ansi.h>
inherit NPC;
void create()
{
 set_name("貧農",({"farmer",}));
 set("long",@LONG
一個十萬大山中常見的農夫.
LONG
    );
 set("attitude", "peaceful");
 set("age",40);
 set("gender","男性");
 set("level",15);
 set("chat_chance",10);
set("chat_msg", ({"貧農唱道:三餐苦菜難下嚥, 那個地家憐窮郎! \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
