inherit ITEM;
inherit F_FOOD;
int fresh;
void create()
{
	set_name("馬肉",({ "horse meat","meat" }) );
	set_weight(900);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
這是一塊由馬身上取下的肉。
LONG);
	set("unit", "塊");
	set("material","food2");
	}
	set("value",70);
	set("food_remaining",3);
	set("heal_hp",10);
	setup();
	fresh=1;
}

void init()
{
	object env;
	::init();
	if(env=environment(this_object()))
	{
		if(!userp(env) || !fresh) return;
		call_out("decay",500);
	}
}

int is_meat() { return fresh; }

void decay()
{
	function f;
	object env;
	if(!this_object()) return;
	if(!fresh) return;
	set("name","腐肉");
	set("long",query("long")+"這塊肉已經腐爛掉了，發出陣陣腐臭。\n");
	if(env=environment(this_object())) tell_room(env,"馬肉腐爛了，發出陣陣腐臭。\n");
	set("value",0);
	set("heal_hp",5);
	f = (: call_other, __FILE__, "eat_bad_pork" :);
	//set("food/function", bind(f, ob));
	set("food/function", bind(f,this_object()));
	fresh=0;
	return;
}

int eat_bad_pork(object ob)
{
	if(!ob) return 0;
	this_player()->receive_damage("hp",20);
	this_player()->apply_condition("eat_bad", this_player()->query_condition("eat_bad")+3);
	message_vision("$N因為吃了不乾淨的東西而食物中毒了。\n",this_player());
	return 1;
}