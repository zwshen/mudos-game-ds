inherit NPC;
void create()
{
	set_name("婦人",({ "woman","婦人" }));
	set("long","一個在街上採購日用品的婦人。\n");
	set("level", 1);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: command,"sing" :),
}) );
	setup();
	add_money("coin",10);
}