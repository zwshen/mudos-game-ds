inherit NPC;
void create()
{
	set_name("婦人",({ "woman","婦人" }));
    set("long","天梟弟子的家眷。\n");
	set("level", 1);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: command,"sing" :),
}) );
	setup();
	add_money("coin",10);
}
