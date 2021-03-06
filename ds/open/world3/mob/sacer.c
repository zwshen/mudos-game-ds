#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N張大嘴巴往$n的$l猛咬",
		"attact_type":  "bar",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"咬傷",
	]),
	([	"action":		"$N奮力往$n的$l撞了過去",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	([	"action":		"$N吐出橘黃色胃酸對準$n的$l噴了過去",
		"attact_type":  "bio",
		"damage_type":	"腐蝕",
	]),
	([	"action":		"$N張開大嘴對準$n的$l吐出一堆垃圾",
		"attact_type":  "bar",
		"damage_type":	"撞傷",
	]),
});

void do_clean();

void create()
{
        set_name("野槌",({"yeah chuay", "yeah","chuay" }) );
	set("long",@LONG

  牠就是傳說中的魔獸野槌, 外表看起來像是一隻巨大的蛆, 巨大的
嘴巴周圍露了好幾層的牙齒。牠的性情十分溫和, 但肚子卻永遠填不
飽。偶而會出現在有許多垃圾的地方, 曾經有人看過牠在一天之內把
一整座山的垃圾吃得乾乾淨淨, 所以人們又稱他為『食圾蟲』。

LONG
);
        set("title","魔獸");
        set("limbs", ({
		"頭部",	"頸部",	"胸口",	"後心",	"腰間",	"腹部",	"大嘴","尾巴",
	}) );
        set("age",500+random(99));
        set("level",40);
        set("gender","雄性");
        set("race","妖魔");
        set("chat_chance", 40);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"野槌舔了舔嘴唇, 緩緩的四處蠕動。\n",
  	"野槌的身體似乎越來越大了。\n",
}));
	set_skill("mob_bite", 60);
	set("addition_armor",60);
	set("addition_damage",60);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
       	 }) );
	set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
	carry_object(__DIR__"eq/sacer_armor.c")->wear();
}

void do_clean()
{
        object ob,env,*item,obj;
        int i,k=0;

	ob=this_object();
	if(!ob) return;
	if( ob->is_fighting() ) return;
	if( ob->is_busy() ) return;
	env=environment(ob);
	if(!env) return;
	item=all_inventory(env);
	if(sizeof(item)>1)
	{
	 for(i=0;i<sizeof(item);i++)
	 {
	  if(item[i]->is_character()) continue;
	  if(item[i]->query("no_get")) continue;
	  k++;
	 }
	 if(k>1)
	 {
	  obj=item[random(sizeof(item))];
	  if(obj->is_character()) return;
	  else if(obj->query("no_get")) return;
	  message_vision("$N張開大嘴把$n吞進了嘴裡。\n",ob,obj);
	  ob->start_busy(2);
	  destruct(obj);
	 } else 
	 {
	  	message_vision("$N突然伸直身體, 緩緩的鑽進了地底。\n",ob);
	  	destruct(this_object());
	 }
	}
	return;
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
