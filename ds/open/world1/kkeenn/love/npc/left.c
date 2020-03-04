#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"彩衣"NOR,({"color ea","ea"}));
        set("long" ,
"情城池的第三代傳人，已經練成震城絕技[滅神鞭法]，實力絕不容小看\n"
"是位可畏的女鞭手。\n");
        set("nickname", HIW"情意左護法"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","女性");
	set("level", 25);
        set("class1","情城池");
        set("title",HIC"情城池第三代傳人"NOR);
        set_temp("apply/armor",15);
	set_skill("run_cloud", 75);
	set_skill("masen_whip", 80);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        setup();
        carry_object(__DIR__"obj/whip7")->wield();
        add_money("coin",2500);
        }
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if( me->query("level") < 6  &&  !me->query("quest/love1") )
        {
  tell_object(me,ob->name()+HIG"說：小朋友，幫姊姊去買把軟鞭好嗎？\n"NOR); 
  tell_object(me,ob->name()+HIG"說：姊姊會重金酬謝你的。\n"NOR);
  tell_object(me,ob->name()+HIG"說：去吧！我等你。\n"NOR);                        return;
        }
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
}
int accept_object(object me, object ob)
{
        object tob, herb,a;
        tob = this_object();
        if( ob->query("id")!="soft whip" ) return 0;
	if( me->query("quest/love1") ) 
	{
		command("?");
		return 1;
	}
        else {
                command("thank "+me->query("id"));
tell_object(me,NOR"("HIG"彩衣"NOR"在你的古代戶頭裡存下了3000元當獎勵。)\n"NOR);
                me->add("bank/past",3000);
                me->set("quest/love1",1);
                destruct(ob);
        }
        return 1;
}

