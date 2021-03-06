inherit NPC;
void create(){
	set_name("警察", ({ "police" }) );
	set("class","soldier");
	set("age",25);
	set("level",15);
            set_skill("gun", 30);
	set_skill("parry", 45);
	set_skill("unarmed", 30);
            set_skill("dodge", 36);
	set("chat_chance_combat", 50);
            set("chat_msg_combat", ({
	(:command("shoot"):),
	(:command("reload clip"):),
	            }) );
	
	set("long",
            "一個負責巡邏新彼得城的警察，他全神貫注地檢視每一個人，不時\n"               	"擦拭滿頭的汗水。\n"  );
	setup();

            carry_object(__DIR__"wp/lasergun")->wield();
	carry_object(__DIR__"wp/laserclip");
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
        case 0: command("say 說道﹕警察﹗別逃了！\n"); break;
        case 1: command("say 喝道﹕兄弟們﹐拿下這個匪徒﹗\n"); break;
        case 2: command("say 喂﹗你想幹什麼﹖"); break;
        case 3: command("say 別反抗了﹗自首吧！"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

