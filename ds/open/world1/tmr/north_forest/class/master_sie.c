inherit NPC;
#include <ansi.h>
void create()
{
 set_name(HIG"顏士興"NOR, ({ "master sie of ce", "master", "sie","ce" }) );
 set("nickname", HIW"靈幻教-"HIC"天城"NOR""CYN"分壇"HIC"壇主"NOR);
set("title", HIW"靈幻教"HIR"第四代"NOR""RED"壇主"NOR);
        set("gender", "男性");
        set("class","fighter");
        set("age", 40);
        set("adv_class",1);
        set("class1","靈幻教");

 set("guild_gifts",({7,4,1,8}));
        set("long",
"他是一位靈幻教在天城分壇的壇主，看他長的白白胖胖的，有點讓人難以相\n"
"信他是一位經過多年苦修的江湖人，每一位靈幻教的壇主都要經歷聖地的三\n"
"年鍛鍊和苦修，才有資格擔任的。\n"
        );
        set("max_ap",2225);
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
        "bagi_fist":({150,3,60}),
          "horse-steps":({130,4,100}),
        "dodge" : ({120,2,60}),
        "parry" : ({120,3,70}),
        "unarmed":({110,3,80}),
        "fork":({120,3,70}),
            "da-fork":({150,3,60}),
        ])  );
        set_skill("unarmed", 80);
        set_skill("sword",100);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_temp("apply/armor",38);
        set("no_check_class",1);
        set("chat_chance",20);
        set("chat_msg",({
          "顏士興緩緩的說道：「劍迴刀轉鋒相對。」\n" ,
          "顏士興慢慢的說道: 「疾風迅刀始論劍。」\n",
          "顏士興對你說道: 想加入靈幻教嗎？\n",
          "顏士興對你說道: 你能幫我嗎？\n",
          "顏士興喃喃地念道: 不知道誰能幫我找到材料。\n",
        (:command("peer"):),
        (:command("sigh"):),
        (:command("hi"):),
        (:command("wahaha"):),
         }) );


                set("chat_chance_combat", 100);
                set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
                (:command("exert da-fork"):),
         }) );
        
        create_family("靈幻教", 4, "分壇壇主");
        setup();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_kick","kick");
}
int do_slap(string arg)
{
object ob1,ob2;
ob1 = this_player();
ob2 = this_object();
if(!arg) return notify_fail(YEL"你想踢誰﹖"NOR);
if(arg != "master" && arg != "sky" && arg != "wind");
message_vision(YEL"$N一腳踢在顏士興(Master sie of ce)的屁屁上﹐印出一個清楚的鞋印。\n"NOR,this_player());
command("say 可惡！我最討厭別人踢我屁屁了！！");
ob1->kill_ob(ob2);
ob2->kill_ob(ob1);
return 1;
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();
        message_vision("$N想加入「"+ arg+ "」。\n",me); 
        if(arg != "靈幻教") return notify_fail("顏士興說道：你要加入什麼？\n");
        if(me->query("adv_class")) return notify_fail("你已有門派了。\n");
        if(me->query_temp("can_join_bo"))
        {
                i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
                switch(i)
                {
                case 1:
                        me->set("adv_class",1);
                        me->set("class1","靈幻教");
                        me->create_family("靈幻教",5,"教徒");
                        message_vision("$N加入了靈幻教。\n",me);
                        me->delete_temp("can_join_bo");
//  message("world:world1:vision",HIR"\n靈幻教天城分壇壇主顏士興大喊：" +HIC"歡迎"+me->query("name")+"加入靈幻教！\n\n"+NOR,users());
                        return 1;
                case -1: return notify_fail("你已有門派了。\n");
                case -2: return notify_fail("你已有門派了。\n");
                case -8: return notify_fail("沒有這種門派。\n");
                }
                return 0;
        }
        if(me->query_temp("join_bi") )
                command("say 這位"+ RANK_D->query_respect(me) +"你還沒幫我找到嗎？\n");
if(me->query_temp("join_bl") )
     command("say "+ RANK_D->query_respect(me) +"還沒把劍拿給另一位壇主嗎？快去吧。");
else
        {
                command("say 我們另一個分壇的壇主欠一把武器，剛好我又知道怎麼做。");
                command("say 可是欠缺一個材料耶，你能幫我找到它嗎？");
                command("addoil");
                me->set_temp("join_bi",1);                  
        }

        return 1;
}
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
                if(me->query("class1")=="靈幻教" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("你不是靈幻教的弟子。\n");
}
int accept_object(object me, object ob)
{    
if(me->query_temp("join_ll") && me->query_temp("join_bi") )return  notify_fail("你要給誰什麼東西? \n");
if( ob->query("join_blade") == 1 ) {
message_vision("$N將一把刀交給"HIG"顏士興"NOR"。\n",me);
command("say 謝謝你大老遠的把刀拿來給我，你等等。");
message_vision("$N看著顏士興拿著一封信走了出來。\n",me);
command("say 你幫我把這封信交給顏天風吧。");
me->set_temp("join_ba",1);
me->delete_temp("join_bl");
new(__DIR__"obj/notea")->move(me);
}else if( ob->query("lione1_join_quest") == 1 && me->query_temp("join_bi")) {
message_vision("$N將製造武器的材料交給了顏士興\n",me);
                command("say 謝謝，你等等喔！");
message_vision("$N看見顏士興拿著材料丟進火爐裡，不一會一把劍就出來了。\n",me);
                command("say 你拿著這把劍去給我們另一位壇主吧。");
                me->set_temp("join_bl",1);
new(__DIR__"eq/sword.c")->move(me);
                me->delete_temp("join_bi");
}else if( ob->query("lione1_join_quest") == 2 && me->query_temp("join_ba"))
{
message_vision("$N將感謝函交給了顏士興。\n",me);
                command("say 不錯不錯，辛苦你了，我就收你入我門下吧。");
                command("smile");
                me->set_temp("can_join_bo",1);
                me->delete_temp("join_ba");
        }
else
return notify_fail("顏士興不想收你的東西喔。\n");

        return 1;
}
