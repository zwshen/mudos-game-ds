#include <ansi.h>
inherit NPC;
void create()
{
        set_name("分闐" , ({ "fanten" }) );
        create_family( HIW "『 ILLUSION RISER 』" NOR ,2,"主教");
        set("level",50);
        set("race","人類");
        set("age",80);
         set("adv_class",1);
         set("class1",HIW"『 ILLUSION RISER 』"NOR);
        set("gender","男性");
        set("int",100);
	// 設定屬性分配表, 每一項的值在負9至正10之間
	// 而且四項的總和要剛好等於 20			by shengsan
	set("guild_gifts",({2,3,10,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
             "sword" : ({160,2,60}),
           "godsword" : ({140,2,70}),
           "meditate" : ({160,2,20}),
           "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-fire" : ({170,2,60}),
                "god-benison" :({180,2,30}),
          ]) );
        set_skill("force", 100);
        set_spell("god-fire",90);
        set_spell("god-benison",90);
        set_skill("sword", 100);
        set_skill("parry", 100);
           set_skill("dodge",100);
          set_skill("godsword",100);
        set("long",@long
他是[1;37m『 ILLUSION RISER 』[2;37;0m的主教，提供基本的技巧訓練。你可
以使用 list來看看有什麼技巧可以提供學習(train)。也可以用
advance <level或屬性> 來升級, 升級前建議先使用 level指令
來查閱所需要的經驗值。
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
          (:command("cast god-fire"):),
          (:command("exert mirage-steps"):),
		(:command("cast god-benison"):),
        }) );
        setup();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);	//暫時
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//	GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")==HIW"『 ILLUSION RISER 』"NOR) return notify_fail("你已是『 ILLUSION RISER 』的法師了。\n");
	 if(arg!="『 ILLUSION RISER 』") return notify_fail("你要拜入那一個門派?\n");
            message_vision("分闐說道： 嗯！不錯, 看來你是一個值得栽培的料子！\n",me);
            message_vision("分闐說道： 好吧！我這就收你為徒, 切記本會要旨："HIY"『 擊潰邪暗力量  重振光明世紀 』"NOR"\n\n",me);
	call_out("domessage",3,me,2);
	return 1;   
}


int domessage(object me,int b)
{
	me=this_player();
  if(b==2)
        message_vision(HIW"分闐將雙手舉起, $N的身旁漸漸泛起一陣白霧........\n\n"NOR,me);	
        else
  if(b==1) 
        message_vision(HIW "只見白霧中的若有若無的幻影漸漸漫入$N的身體, $N感到無限舒暢。\n\n" NOR,me);
        else 
  if(b==0)
                  {
        me->set("adv_class",1);
        me->set("class1",HIW"『 ILLUSION RISER 』"NOR);
        me->create_family(HIW"『 ILLUSION RISER 』"NOR,3,"法師");
        message_vision("$N正式成為"HIW"『 ILLUSION RISER 』"NOR"的第三代法師！\n",me);
	return 1;
	}
b--;
call_out("domessage",3,me,b);
} 

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")==HIW"『 ILLUSION RISER 』"NOR) return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是"HIW"『 ILLUSION RISER 』"NOR"的法師。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}
