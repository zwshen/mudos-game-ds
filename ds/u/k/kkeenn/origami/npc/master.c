#include <ansi.h>
inherit NPC;
void create()
{
        set_name("©PÅã©v",({"origami master","master"}));
        set("title",HIC"¢à¢Þ¢Õº©µe¤§¯«"NOR);
        set("nickname",HIW"ºP¯È¤u·|·|ªø"NOR);
        set("gender", "¨k©Ê");
        set("long",@LONG
¥L¬OºP¯È¤u·|¸Ì¸ê²`ªº²z¨Æªø¡A³o¬O¹CÀs«L­«ª÷¸u¨ÓªººP¯È±Ð®v¡C

        list    ¦C¥X¥i¾Çªº§Þ¯à
        train   °V½m§Þ¯à
        learn   ¾Ç²ßªk³N
        join    ¥[¤J¤u·|
        apply   ¥Ó½Ð¸Éµo«Hª«
        advance ¤É¯Å©Î¼W¥[ÄÝ©Ê

LONG
        );
        set("level",50);                
        set("age",40);
        set("adv_class",1);
        set("class1","origami");
        set("guild_skills",([   // Ãø«×, µ¥¯Å1¥i¾Ç¨ìªº§Þ¯àµ¥¯Å­¿²v, ¤W­­
                "dodge":({60,3,80}), 
                "gun":({60,3,80}),
                "combat":({50,3,80}),  
                "origami":({100,1,80}),  
                "doubleshoot":({80,2,90}),  
                "unarmed":({80,5,60}),
                "block":({40,3,70}), 
       ]) );
         set("guild_gifts",({10,5,-3,8}));
        setup();
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
     if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
        add_action("do_check_mark","apply");
     if(!query("no_advance"))
        add_action("do_advance","advance");
}
int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // Á×§K¦C¥XÀË¬dÂ¾·~ªº°T®§
        write("\n");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}
int do_guild_join(string arg)
{
        object ob, me;
        int i;
        ob = this_object();
        me = this_player();
        if( !arg && !me->query_temp("join_o") )
                return notify_fail("§A·Q­n¥[¤J¤°»ò¤u·|§r¡H(join origami)\n");
        if( me->query_temp("join_o") && !arg ) arg = "origami";
        if( strsrch(arg, "origami") == -1 || strsrch(arg, "¤£") > -1)
                return notify_fail("§A·Q­n¥[¤J¤°»ò¤u·|§r¡H(join origami)ù)\n");
        message_vision("$N·Q¥[¤J¡u"+ HIM"" + arg + ""NOR+ "¡v¡C\n",me); 
        if( me->query("class1") )
                return notify_fail("§A¤w¬O"+me->query("class1")+"ªº¾Ç®{¤F¡C\n");
        if( me->query("class1")=="origami" )
                return notify_fail("§A¤w¬OºP¯È¤u·|ªº¾Ç®{¤F¡C\n");
        if( !me->query_temp("ojoin") && !me->query_temp("join_o") ) {
        command("whisper "+me->query("id")+" ¶â...¦p§A©Ò¨£...§Ú­Ì¯Ê¿úÄw¿ì¤¤...¡C");
        command("whisper "+me->query("id")+" §Æ±æ±z¯à®½Ämµ¹§Ú­Ì¤­¤d¤¸À³«æ(donate 5000)¡C");
        me->set_temp("ojoin",1);
        add_action("do_donate", "donate");
        return 1;
        }
        else if( me->query_temp("ojoin") && !me->query_temp("join_o") ) {
                command("say ªB¤Í¡A§A¨M©w¤F¶Ü¡H¦¹¨Æ¤Q¤À­nºò¡A½Ð§Ö¦Ò¼{¡C");
                add_action("do_donate", "donate");
                return 1;
        }
        else {
                command("pat "+me->query("id")); 
                command("thank "+me->query("id"));                            me->set("guild_rank","ºP¯È¤u·|ªì¯Å·|­û");
                message_vision("$N¦¨¬°ºP¯È¤u·|ªº·|­û¡C\n",me);
                me->set("class1","origami");
                me->set("adv_class",1);
                new("/u/k/kkeenn/origami/paper/paper.c")->move(me);
                write(WHT"©PÅã©v®¨®¨¶ë¤F¤@±i¯}Äêªº³z©ú¯Èµ¹§A¡C\n"NOR);
                return 1;
        }
}
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // ±N rank ¤À¬°¤»­Ó¼h¦¸
        if( me->query("gender") == "¤k©Ê" )
        {
                switch( lv )
                {
                        case 0: rank = HIC"¥¼¨ÓºP¯È¤u·|¾Ç®{"NOR; break;
                        case 1: rank = HIY"ºP¯È¤u·|¤§¤k·|­û"NOR; break;
                        default: rank = HIM"ºP¯È¤u·|ºP¯È¾Ô¤h"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"¥¼¨ÓºP¯È¤u·|¾Ç®{"NOR; break;
                        case 1: rank = HIY"ºP¯È¤u·|¤§¨k·|­û"NOR; break;
                        default: rank = HIM"ºP¯È¤u·|ºP¯È¾Ô¤h"NOR;
                }
        }
        return rank;
}
int do_donate(string arg)
{
        object me;
        int i;
        me = this_player();
        if( !arg )
        return notify_fail(HIG"Computer Type Out 'How much money do you want to donate ?'¡C\n"NOR);
        if(sscanf(arg,"%d",i)!=1 ) 
        return notify_fail(HIG"Computer Type Out 'How much money do you want to donate ?'¡C\n"NOR);
        if( i < 5000 )
        return notify_fail("Computer Type Out 'The low money limit is 5000 !'¡C\n");
        if(me->query("bank/future") < i )
        return notify_fail("Computer Type Out 'Sorry, you don't have "+i+" future coco.'¡C\n");
        message_vision("$N donated "+i+" coco to the Origami club¡I\n"NOR,me);
        me->add("bank/future",-i);
        me->set_temp("join_o",1);
        return 1;
}
int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class1")!="origami")
                           return notify_fail("§A¨Ã¨S¦³°Ñ¥[ºP¯È¤u·|ý¡C\n");
        if(mark=present("none paper",me))
                           return notify_fail("§A¤w¸g¦³¯ÈÃþ«Hª«¤F¡C\n");
        if(mark=present(me->query("family/id")+" paper",me))
                           return notify_fail("§A¤w¸g¦³¯ÈÃþ«Hª«¤F¡C\n");       
        if(mark=present("armor",me))
                           return notify_fail("§A¤w¸g¦³¯ÈÃþ«Hª«¤F¡C\n");   
   if(!me->query("family"))
{
        ob=new("/u/k/kkeenn/origami/paper/paper.c");
}
else
{
        ob=new("/u/k/kkeenn/origami/paper/paper2.c");
}
        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("§A¥²¶·¥á±¼¤@¨ÇªF¦è¤~®³ªº°Ê¦¹ºP¯È¡C\n");
        }
        ob->move(me);
        message_vision("$N®³¤F¤@±i"+ob->name()+"µ¹$n¡C\n",this_object(),me);
        me->save();
        return 1;
}
