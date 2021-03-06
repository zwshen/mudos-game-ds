#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
        set_name(HIR"炎羽鳳爪"NOR,({"fire bird craw","craw"}) );
        set("long",@long
    這對手套傳說是以浴火重生之鳳凰掉落的火羽，混以烏蠶之絲，鬼蜥
之鱗，以天雷燒融鍛化七七四十九次後而成材料。毀壞十三把寶劍以成其
型，以人､鬼､神三界之血冶鍊麒麟之角以為針，化日､月､星三光以為
線，縫製三百寒暑而成器。以靈御之則風起，以氣御之則火生。本來謠傳
於江湖之中，人皆以為神話而不存於世，直到三年前方由李書文弟子柴子
雲所獲，而現之江湖，但亦有人認為其威力不符傳說之奇，乃後人依傳說
而製。

使用說明:
1.指令 irrigate ap — 將自己的內勁灌入炎羽鳳爪之中以產生火勁。
1.指令 irrigate mp — 將自己的靈力灌入炎羽鳳爪之中以產生風勁。
long
        );
       set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","對");
            set("value",23000);
            set("limit_con",20);
            set("limit_str",20);
            set("limit_int",20);
            set("limit_dex",20);
        set("wield_msg",
HIC "$N拿起一雙$n，只見$N戴上之後，一陣灼熱的熾風由$n向四面八方湧出！！\n"
NOR);
        }
    set("weapon_prop/armor", 17);
    init_fist(27);
        setup();
}
void init()
{        
        add_action("do_fire","irrigate");
        add_action("do_wind","irrigate");
}
int do_fire(object me,object target,string arg)
{
        object wp;
        int p,m,d,a;
        wp=target->query_temp("weapon");
        p=target->query_skill("dodge")+target->query_dex();
        m=me->query_skill("dodge")+me->query_dex();
        if(arg != "ap" ) return 0;
        if( me->query_skill_mapped("unarmed")!="unarmed")
                        return notify_fail("使用有招式的拳法時無法使用炎羽鳳爪的特攻。\n");
        if( !wp )
        {       
                a=10+random(100);
                me->receive_damage("ap", a );
                message_vision(HIY"$N雙掌一出，真氣一運，一股熾熱的火焰撲向$n！！\n"NOR,me,target);
                if(random(p) > random(a)+30 )
                {
                  message_vision(CYN "$N縱身一閃，恰恰躲開了火舌的襲擊。\n" NOR,target);
                  me->add_busy(2);
                }
                else

                {
                   d= a*2/3+random(me->query("ap"))*3/5;
                   if(d > 200) d=200;
                   target->receive_damage("hp", d );
                   message_vision(HIR "$N瞬時被烈焰纏身，火光濃煙之中傳出陣陣皮肉燒焦的臭味！\n" NOR,target);
                   me->add_busy(3);
                   target->add_busy(3);
                }
                return 1;
        }

        if( 30+random(p) < random(m))
        {
                wp->unequip();
                if(p->query_str()<20 || random(p->query_str())<random(p->quert_str()/3)) wp->move(environment(target));
                message_vision(HIC "只見一道火光燒向"+wp->query("name")+"！！$N手中登時一陣滾燙，急忙鬆開了"+wp->query("name")+"！！\n" NOR ,target);
                me->receive_damage("ap", 20 );
                me->add_busy(1);
        }
        else
        {
                message_vision(CYN "$N手中兵器一縮，躲開了火舌的攻擊！！\n" NOR,target);
                me->add_busy(1);
                target->add_busy(2);
        }

        return 1;
}
int do_wind(object me,object target,string arg)
{

        if(arg != "mp" ) return 0;
        
        return 1;
}

