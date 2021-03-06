#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蕾", ({ "lei","lei" }) );
        set("race","human");
        set("gender", "女性");
        set("level",31);
        set("age",random(100));
        set("evil",-15);
        set("title",HIR"聖炎化使"NOR);
        set("long",@LONG
擅長易容之術的蕾，大家都叫他「無形」之蕾，有時是十七
八歲少女，有時是七八十歲老婆婆，最擅長用易容術配合幻
術來蒙蔽敵人，以達到其目的。
LONG
);
        set_skill("sorgi_sword",60);
        set("chat_chance_combat",26);
        set("chat_msg_combat", ({
                  (: command("exert sorgi_sword") :),
        }) );
        setup(); 
        carry_object(__DIR__"../eq/ws_cloth")->wear();
        carry_object(__DIR__"../wp/th_sword")->wield();
}

void die()
{
	object killer;
	int last;
	if(random(7))
	{
		if(killer=this_object()->query_temp("last_damage_from"))
		{
			last = killer->query("max_hp")/10;
			if(last < killer->query("hp"))
			{
				message_vision(HIW"  $N用盡最後一點力氣使出"HIR"千顏裂"HIW"  $n一時反應不及硬是吃下這招。\n"NOR,this_object(),killer);
				last=killer->query("hp")-last;
			        killer->receive_damage("hp",last,this_object());
			}
		}
	}
	::die();
}
