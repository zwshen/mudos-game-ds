inherit NPC;
void create(){
	set_name("守城官兵", ({ "garrison" }) );
	set("class","soldier");
	set("age",25);
	set("level",20);
            set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 50);
            set_skill("dodge", 50);

	set("long",
            "一個守護城門的官兵，看起來精神奕奕，專注地看著過往的人群，不時\n"               	"擦拭滿頭的汗水。\n"  );
	setup();

            carry_object(__DIR__"wp/sword.c")->wield();
            carry_object(__DIR__"eq/armor")->wear();
           carry_object(__DIR__"eq/boots.c")->wear();
}

int accept_fight(object ob)
{
        switch(random(3)) {
                case 0: command("shake" );      break;
                case 1: command("say 走開走開﹗\n");            break;
                case 2: command("hehe" );       break;
        }
        return 0;
}

void init()
{
	::init();
         add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("say 說道﹕咦？造反啦？竟敢亂殺人！！去死吧 ...\n");

        ob=all_inventory(environment());
	for(i=0;i<sizeof(ob);i++)
	{
		ob[i]->soldier_assist(this_object(), me);
	}
	return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
        ||      is_fighting(me) )
                return;

          switch(random(4)) {
        case 0: command("say 說道﹕大膽刁民﹗竟敢公然逞兇﹗\n"); break;
        case 1: command("say 喝道﹕反了反了﹗兄弟們﹐拿下這個匪徒﹗\n"); break;
        case 2: command("say 喂﹗你想幹什麼﹖"); break;
        case 3: command("say 來人哪﹗拿下那個可疑的傢伙﹗"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

