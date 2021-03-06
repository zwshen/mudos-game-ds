#include <ansi.h>

inherit NPC;
int ghost_kill(object ob)
{
    object target;

	target = ob->select_opponent();
    if( !target) return 1;
	if(ob->is_busy() ) return 1;
	switch(random(3) ) {
	case 0:
         message_vision(HIM "$N怒吼連連，手上的攻勢絲毫沒有慢下來...\n" NOR,ob);
		ob->attack();
		ob->attack();
		ob->attack();
	break;
	case 1:
		message_vision(RED "$N張嘴露出利牙，硬生生咬下$n肩上一的塊肉下來....\n" NOR,ob, target);
		ob->receive_heal("hp", ob->query("hp")/10 );
        target->receive_damage("hp", 50 + random(50), ob);
	break;
	default:
		message_vision(HIY "$N張大口發出一聲恐怖的叫聲，$n登時嚇的腿軟無力......\n" NOR,ob, target);
		target->add_busy(1);
	break;
	}
	return 1;
}


void create()
{
        set_name("獸王之王" ,({"animal king","king"}) );
        set("long",@LONG
獸王之王是百年前就在在紫陽山頂做惡多端的一個獸人族，
老一輩的人都稱呼他為邪惡領主。獸王之王統治一群殘酷的狂
獸，殺生無數，生靈塗炭。幸而得紫陽四隱合力之助，才將獸
王之王封印在神祕的地方。
LONG
);
        set("age",200);
        set("race","ogre");
        set("title",HIR"邪惡領主"NOR);
        set("level",45);
        set("attitude", "aggressive");
        set("gender", "男性" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("blade",100);
      set("chat_chance_combat",30);
	set("chat_msg_combat",({
		(: ghost_kill,this_object() :),
	}) );

        setup();
        set_living_name("animal-war-object");
		if(random(100)<30)
			carry_object(__DIR__"wp/king-blade")->wield();
		else carry_object(__DIR__"wp/king-blade2")->wield();
		carry_object(__DIR__"eq/copper-armor")->wear();
           carry_object(__DIR__"obj/organ");
           carry_object(__DIR__"obj/stomach-bag");
             carry_object(__DIR__"obj/king-head");
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
 
                message("world:world1:vision",
        HIM "\n\t獸王之王臨死之際對著"+ob->name(1)+HIM"發生低沉的嗚叫，充滿無盡的仇恨。\n\n"+NOR
        ,users());
            ob->add("popularity",3); //聲望
         tell_object(ob,HIG"你得到三點聲望了。"NOR);
        ::die();
        return;
}
