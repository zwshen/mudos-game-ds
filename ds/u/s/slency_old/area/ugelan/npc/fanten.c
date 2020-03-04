#include <ansi.h>
inherit NPC;
void create()
{
        set_name("¤ÀÂõ" , ({ "fanten" }) );
        create_family( HIW "¡y ILLUSION RISER ¡z" NOR ,2,"¥D±Ð");
        set("level",50);
        set("race","¤HÃþ");
        set("age",80);
         set("adv_class",1);
         set("class1",HIW"¡y ILLUSION RISER ¡z"NOR);
        set("gender","¨k©Ê");
        set("int",100);
	// ³]©wÄÝ©Ê¤À°tªí, ¨C¤@¶µªº­È¦b­t9¦Ü¥¿10¤§¶¡
	// ¦Ó¥B¥|¶µªºÁ`©M­n­è¦nµ¥©ó 20			by shengsan
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
¥L¬O[1;37m¡y ILLUSION RISER ¡z[2;37;0mªº¥D±Ð¡A´£¨Ñ°ò¥»ªº§Þ¥©°V½m¡C§A¥i
¥H¨Ï¥Î list¨Ó¬Ý¬Ý¦³¤°»ò§Þ¥©¥i¥H´£¨Ñ¾Ç²ß(train)¡C¤]¥i¥H¥Î
advance <level©ÎÄÝ©Ê> ¨Ó¤É¯Å, ¤É¯Å«e«ØÄ³¥ý¨Ï¥Î level«ü¥O
¨Ó¬d¾\©Ò»Ý­nªº¸gÅç­È¡C
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
        me->set("no_check_class",1);	//¼È®É
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

if(me->query("class1")==HIW"¡y ILLUSION RISER ¡z"NOR) return notify_fail("§A¤w¬O¡y ILLUSION RISER ¡zªºªk®v¤F¡C\n");
	 if(arg!="¡y ILLUSION RISER ¡z") return notify_fail("§A­n«ô¤J¨º¤@­Óªù¬£?\n");
            message_vision("¤ÀÂõ»¡¹D¡G ¶â¡I¤£¿ù, ¬Ý¨Ó§A¬O¤@­Ó­È±o®â°öªº®Æ¤l¡I\n",me);
            message_vision("¤ÀÂõ»¡¹D¡G ¦n§a¡I§Ú³o´N¦¬§A¬°®{, ¤Á°O¥»·|­n¦®¡G"HIY"¡y À»¼ì¨¸·t¤O¶q  ­«®¶¥ú©ú¥@¬ö ¡z"NOR"\n\n",me);
	call_out("domessage",3,me,2);
	return 1;   
}


int domessage(object me,int b)
{
	me=this_player();
  if(b==2)
        message_vision(HIW"¤ÀÂõ±NÂù¤âÁ|°_, $Nªº¨­®Çº¥º¥ªx°_¤@°}¥ÕÃú........\n\n"NOR,me);	
        else
  if(b==1) 
        message_vision(HIW "¥u¨£¥ÕÃú¤¤ªº­Y¦³­YµLªº¤Û¼vº¥º¥º©¤J$Nªº¨­Åé, $N·P¨ìµL­­µÎºZ¡C\n\n" NOR,me);
        else 
  if(b==0)
                  {
        me->set("adv_class",1);
        me->set("class1",HIW"¡y ILLUSION RISER ¡z"NOR);
        me->create_family(HIW"¡y ILLUSION RISER ¡z"NOR,3,"ªk®v");
        message_vision("$N¥¿¦¡¦¨¬°"HIW"¡y ILLUSION RISER ¡z"NOR"ªº²Ä¤T¥Nªk®v¡I\n",me);
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
        if (me->query("family/family_name")==HIW"¡y ILLUSION RISER ¡z"NOR) return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("§A¤£¬O"HIW"¡y ILLUSION RISER ¡z"NOR"ªºªk®v¡C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}
