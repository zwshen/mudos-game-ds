inherit NPC;
void create()
{
	set_name("破壞人", ({ "revage man", "man" }));
	set("long","一個專門在各地破壞物品的人。\n");
	set("level",  13);
	set("age", 30);
	set("chat_chance", 5);
	set("chat_msg", ({
  this_object()->name()+"不停的在室內亂敲亂打！\n",
  (: command,"pk" :),
}));
	setup();
}

void init()
{
	add_action("do_kill","kill");
}

int do_kill(string arg)
{
    if( arg != "man" || arg != "revage man" ) return 0;
	else
	{
		command("snort");
		return 0;
	}
	return 0;
}
