inherit NPC;
#include <ansi2.h>;

void haltbusy()
{
       if( random(3) ) return;
       message_vision("$N額上的神紋發出陣陣光芒擴散開來。\n",this_object());
       message_vision("$N的身軀從僵硬恢復了過來。\n",this_object());
       this_object()->add_busy(-5);
       return;
}

void powerup()
{
        if( !this_object()->query_temp("pill") ) return;
        if( this_object()->query("hp") >  this_object()->query("max_hp")/2 ) return;
        if( random(2) ) message_vision("$N大喝：雅典娜，賜予我力量吧！\n", this_object());
        else message_vision("$N大喝：小宇宙！爆發吧！\n", this_object());
        this_object()->receive_heal("hp",query("max_hp")/2);
        this_object()->receive_heal("mp",query("max_mp")/2);
        this_object()->receive_heal("ap",query("max_ap")/2);
        this_object()->clean_condition();
        COMBAT_D->report_status(this_object());
        this_object()->add_temp("pill",-1);
        return;
}

void create()
{
        set_name("赫爾梅斯", ({"homeis"}));
        set("title", HIG"【傳令神】"NOR);
        set("long", "傳令神赫爾梅斯，守護雙子座。\n");
        set("gender","男性");
        set("level", 60);
        set("age",46);
        set("attitude", "friendly");
        set("race","titan");

        set("chat_chance_combat",100);
        set("chat_msg_combat",({
            //(: command("do wield sword,exert xxx"):),
            //(: command("exert xxx"):),
            (: powerup :),
        }));
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 100);

        set("max_hp", 23000);
        set("max_mp", 4000);
        set("max_ap", 6500);
        
        set_temp("pill", 2);
        set_temp("fly",1);
        set_temp("apply/damage",150+random(30));
        set_temp("apply/shield",150);
        set_temp("apply/armor", 300);
        set_temp("apply/hit", 70);
        set_temp("apply/dodge", 50);
        set("addition_armor", 40);

        setup();
        set_temp("apply/sou", -3);
        set_temp("apply/wit", -2);
        set_temp("apply/bio", -3);
        set_temp("apply/tec", 4);
        carry_object(__DIR__"wp/tyrfing_sword")->wield();
}

int special_attack(object me, object target, int hitchance)
{
    if(!me) return 0;
     switch(random(5))
     {
        case 0:
        {
        message_vision(YEL"$N手中令旗一揮，一陣狂風呼嘯而起！\n",me,target);
        if(random(2))
                {
            message_vision(YEL"$N被風吹的跪在地上，毫無半點力量！"HIR"("+query("max_mp")/7+")\n"NOR,target,me);
            target->receive_damage("mp",query("max_mp")/7);
            COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
                }
        else
        message_vision(HIR"$N在風中旋轉著，借助風的力量繼續作戰！\n"NOR,target,me);
        }
        break;
        case 1:
        {
        message_vision(HIR"$N一揮手中令旗，一道閃電劈向$n！\n",me,target);
        if(random(2))
                {
            message_vision(HIR"$N被閃電劈了個正著，直電的頭皮發麻！"HIR"("+query("max_ap")/10+")\n"NOR,target);
            target->receive_damage("mp", query("max_mp")/10);
            target->receive_damage("ap", query("max_ap")/10);
            COMBAT_D->report_status(target);
                }
        else
        message_vision(HIR"$N早就看清了閃電的方向，輕輕一閃，躲開了。\n"NOR,target);
        }
        break;
    }
        
        return 0;
}


// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        object sw;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( !objectp(who) ) return damage;
        if( environment(this_object()) != environment(who) ) return 0;
        if( objectp(who) && type=="hp")
        set_temp("last_damage_from", who);
        sw=who->query_temp("weapon");
        
        haltbusy();
        
        if(random(100)<35)
        {
            damage=1;
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 30 ) 
            {
                sw->unequip();
                message_vision(HIY"\n赫爾梅斯大喝一聲，$N"HIY"頓時被驚的手中一顫，赫爾梅斯順勢重擊$n。\n" NOR,who,sw);
                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
            } if(random(100) < 60 ) {
                message_vision(HIY "\n赫爾梅斯身上盔甲泛出金色奇異魔紋，$N"HIY"眼前一花，已被鬥氣重擊多次。\n" NOR,who);
               who->start_busy(1);
            } else {
                message_vision(HIM "\n$n"HIM"驟然發現，剛才交手的竟然是魔法幻影。\n" NOR,this_object(),who);
            }
        }

        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);
        return damage;
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->start_busy(3);
        message("channel:chat",HIY+"【黃金十二宮】"HIC"雅典娜(Athena)："+ob->name()+
        "闖過了"+environment(this_object())->query("short")+"\n"NOR,users());
        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        //ob->set("12gong/libra","done");
        //ob->add("12gong/libra",1);
        //ob->set("title",HIW"天坪座戰士"NOR);
        //ob->save();
        }
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}
