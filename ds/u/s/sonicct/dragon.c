#include <ansi.h>

inherit NPC;

void create()
{
        
        set_name(HIR"火焰"HIG"飛龍"NOR,({"Flame of Dragon","dragon"}) );
        set("race", "野獸");
        set("level",100);
        set("age",1000);
        set("long", "一條全身覆蓋覆蓋的飛龍正在這裡。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"}));
        set("verbs", ({"bite"}));
        set("bullet",5000);
        set("count",5000);
        set("value",1000000);
        set("ridable",1);              
        setup();
}

void init()
{
	add_action("do_order","order");
        add_action("do_fly","fly");
        add_action("do_fire","fire");
}

int do_fly(string arg) 
{
        object who,me;
        int count1;


        if( this_object() != present(this_object(),this_player()) )
                return notify_fail("你並未騎上飛龍。\n");

        if( !arg ) return notify_fail("你想飛到往哪裡?\n");

        me=this_player();
        who = find_player(arg);
        if (!who) who = find_living(arg);
        if (!who) return notify_fail("你想飛到往哪裡?\n");

        count1 = (int)this_object()->query("count");
        if( (count1 -= 4) < 0 ) {
                count1 += 4;
                set("count",count1);
                return notify_fail(this_object()->name()+"已經不夠力量以進行飛行。\n");
        }

        set("count",count1);
                message_vision("$N"HIW"飛龍雙翼拍動，朝著終點飛翔。\n"NOR,this_object());
        tell_room(who,this_object()->name()+HIB"飛到此地，緩慢地下降到地面。\n"NOR);
        me->move(environment(who));
        return 1;
}
int ride_before_action(object me)     
{
        int s = me->query("str");
        if( s<90 || !s )
        {
                message_vision("由於$N的力量不夠，無法控制"+this_object()->name()+"，因而被"+this_object()->name()+"從飛龍背上摔了下來！\n",me);
                return 0;              
        }
        else
        {
                message_vision("$N使出全身的蠻力準備征服這隻"+this_object()->name()+"。\n",me);
                return 1;              
        }
}

int ride_after_action(object me)       
{
        message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
        return 1;                      
}


int ride_off_action(object me)   
{
        message_vision("$N已經離開"+this_object()->name()+"了。\n",me);
        return 1;                     



}
int do_fire(string act)
{
        string msg;
        object ob,target;

        ob = this_object();
        if( this_object() != present(this_object(),this_player()) )
                return notify_fail("你並未騎上飛龍。\n");

        if(ob->query("bullet")<=0) {
                write(this_object()->name()+"的真氣已經耗盡。\n");
                return 1;
        }

        if( act ) target = present( act, environment(this_player()) );

        if(!target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==this_player() )
                return notify_fail("請指定攻擊目標。\n");

        msg = "$n"+HIR+"慢慢的張開血盤大口。\n"NOR;
        message_vision(msg,target,ob);
        message_vision("$n"HIB"令四周氣溫開始上升。\n"NOR,target,ob);

        call_out("fire_2",5,this_player(),target,ob,act);
        this_player()->start_busy(3);
        return 1;
}

int fire_2(object me,object target,object ob,string act)
{
        string msg;
        int damage,i,bul,dp,pp,dx,nt,kr,cha;

        pp = COMBAT_D->skill_power(target, "parry");// SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge");
        dx = target->query_dex();
        nt = target->query_int();

        cha = pp*2 +dp*2 +dx +nt +target->query_armor()*3;

        for(i=0; i<10; i++)
        {
                bul = (int)this_object()->query("bullet");
                if ( (bul -= 50+random(100) ) < 0 ) {
                        bul += 50+random(100);
                        set("bullet",bul);
                }  
                set("bullet",bul);

                damage = 500+random(500) -cha/3;

                if(ob->query("bullet") <= 0 ) 
                {
                        message_vision("$n"HIW"的真氣已經耗盡，所以不能噴出火焰。\n"NOR,target,ob);
                        ob->set("bullet",0);
                        break;
                }
                else{
                        msg = HIY"從口中噴出第"+(i+1)+"波的火焰∼"NOR;
                }
                if ( damage > 0) {
                msg +=HIR"$N"HIR"鮮血狂噴而出。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,target,ob);
                        target->receive_damage("hp", damage, me);       
                        COMBAT_D->report_status(target);                
                }  else {
                msg +=HIW"可是火焰無害的焚燒在"NOR"$N"HIW"身上。\n"NOR;
                message_vision(msg,target,ob);
                } 
        }
        me->start_busy(1);
        target->start_busy(1);
        return 1;
}
int do_order(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="sonicct")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕order <某鬼魂> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}