#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_BANDIT;

void create()
{
        set_name("宋天王", ({ "song tian wang" ,"song","wang" }) );
        set("long",@long
　　宋天王長的非常魁梧有力，擁有一付優於常人的身材，銳利的雙眼射
出壓迫人的壓力。傳聞他的武功「蒼龍四型訣」攻勢驚人，可被列為奇功
絕藝榜上有名的絕技。但是瞧他兩眼無神，似乎正在為什麼事情煩腦。
long
);
        set_race("operation");
        set("age", 45);
                 set_attr("operation",50);
                  set("force_ratio",10);
                set_skill("twohanded blade",80);
                set_skill("dragon four feat",100);
                set_skill("parry",80);
                set_skill("psychical",50);
                set_skill("dodge",80);
                map_skill("twohanded blade","dragon four feat");
//        set("attitude", "aggressive");
        set("title","硬幫幫首領");
        setup();
           set_level(40);
                carry_object(__DIR__"obj/yellow-cap")->wear();
                  carry_object(__DIR__"obj/gold-snow-armor")->wear();
                   carry_object(__DIR__"obj/feather-boots")->wear();
           carry_object(__DIR__"obj/sacrifice-blade")->wield();
}

private void exchange(string food_name, object player)
{
        if( !player || environment(player) != environment() ) return;
                if( player->query_stat_maximum("nina") >= 100
                          && player->query("skills_point")+3<SKILL_MAX_POINT
                         && !player->query_learn("dragon four feat") ) 
                {
                        command("say 我瞧你的念技也到了一定功夫，不知你是那兒學來的？");
                player->set_temp("duli_forest/song-tian-wang",1);
                } else {
                        command("say 真是謝謝你了，以後有什麼問題，我會盡量幫你忙的。");
                }
}
 
int accept_object(object me, object ob)
{
       if( !ob->id("_OBJ_ID_WOLF_BELT_")
                   || me->query_learn("dragon four feat")
           || me->query_temp("duli_forest/song-tian-wang")  )
           {
              return 0;
       }
       command("smile");
       command("say 哈哈哈....想不到你幫我殺了這個混帳了。");
       do_chat(({ (: exchange, ob->query("id"), me :) }) );
       return 1;
}
 
void relay_say(object ob,string arg)
{
        if( ob->query_learn("dragon four feat") ) return;
        if( strsrch(arg,"煩腦")!=-1 ) {
                message_vision(CYN"宋天王望了你說道：「嗯..幫內近幾年內出了不少大問題，似乎是有內奸作崇。」\n"NOR,ob);
                        return ;
                }
        if( strsrch(arg,"內奸")!=-1 ) {
                message_vision(CYN"宋天王冷哼道：「要不是顧及兄弟道義，我早就把他給殺了。」\n"NOR,ob);
                tell_object(ob,CYN"(你暗忖自已不知是否有能力幫他解決這問題　)\n"NOR);
                        return ;
                }


 
        if( ob->query_temp("duli_forest/song-tian-wang")==1  ) {
          if( arg=="卡特" )
          {
                message_vision(CYN"宋天王一楞道：「原來是他，難怪你的基礎功夫這麼紮實。」\n"NOR,ob);
                message_vision(CYN"宋天王頓了口氣，又說道：「我和他也頗有緣源的，你有什麼請求，盡管說吧，我會盡力幫你的吧。」\n"NOR,ob);
                tell_object(ob,CYN"(你想到宋天王的成名絕技，要是能向他學到，一定可以揚名中外。)\n"NOR);
                                ob->set_temp("duli_forest/song-tian-wang",2);
                        return ;
                }
             }
        if( ob->query_temp("duli_forest/song-tian-wang")==2  ) {
        if( arg=="蒼龍四型訣") {
                        /* 學習技能點數不夠 */
			if(ob->query("skills_point")+3>=SKILL_MAX_POINT )
                        {
                                message_vision(CYN"宋天王冷笑道：「你雜學甚廣，不需要在下這雕蟲小技吧。」\n"NOR,ob);
                }
                        else {
                                message_vision(CYN"宋天王哈哈大笑道：「連你也動到我的成名絕技上了，瞧你資質極佳，就傳授你吧。」\n"NOR,ob);
                message_vision(CYN"宋天王運起手上長刀，迅捷無比的使出了成名絕技，只見$N瞧的佩服不已...\n"NOR,ob);
                tell_object(ob,CYN"(你潛心默記，雖然只學習到皮毛，但用心苦練，還是可以大成的。)\n"NOR);
                ob->add("skills_point",3);
                ob->improve_skill("dragon four feat",100);
                tell_object(ob,HIG"(你的技能學習點數花掉三點。)\n" NOR);
                        }
                        ob->delete_temp("duli_forest/song-tian-wang");
                        return ;
                }
		}
}


