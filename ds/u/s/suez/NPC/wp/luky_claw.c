#include <ansi.h>
#include <weapon.h>
inherit SSERVER;
inherit F_UNIQUE;
inherit FIST;
void npc_auto_equip(object target);
void create()
{
        set_name(HIR"炎羽鳳爪"NOR,({"fire bird claw","claw"}) );
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
        set("wield_msg",
HIC "$N拿起一雙$n"HIC"，只見$N"HIC"戴上之後，一陣灼熱的熾風由$n"HIC"向四面八方湧出！！\n"
NOR);
        }
            set("value",23000);
            set("limit_con",20);
            set("limit_str",20);
            set("limit_int",20);
            set("limit_dex",20);
    set("weapon_prop/armor", 17);
    init_fist(27);
        setup();
}
void init()
{        
        add_action("do_irrigate","irrigate");
}

int do_irrigate(string arg)
{
        object wp,me,target;
        int p,m,d,a;
        me=this_player();
        
        if(environment(this_object())!=me) return 0;  //重要的檢查. (否則放在地上就可以用)
        if(me->query_temp("weapon")!=this_object()) return 0; //重要的檢查 (否則不用裝備就可以用)
        if( me->is_busy() || me->is_block() ) return notify_fail("你的上一個動作還沒完成。\n"); //不應該漏掉
        target = offensive_target(me);  // 要先 inherit SSERVER;
	if(!target) return notify_fail("在戰鬥中才能發揮炎羽鳳爪的力量。\n");
        wp=target->query_temp("weapon");
        p=target->query_skill("dodge")+target->query_dex();
        m=me->query_skill("dodge")+me->query_dex();
        if(!arg) return notify_fail("指令: irrigate ap 或 irrigate mp。\n");
        if(arg == "ap" )
        {
        	if(me->query("ap")<100) return notify_fail("你沒有足夠的ap可輸入炎羽鳳爪。\n"); //不應該漏掉.
		if( me->query_skill_mapped("unarmed") )  // 如果沒有map skill 會傳回 0
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
	                   me->add_busy(2);
	                   target->add_busy(2);
	                }
	                return 1;
	        }
	
	        if( 10+random(p+20) < random(m))
	        {
	                wp->unequip();
	                if(!userp(target)) call_out("npc_auto_equip",15,target);
	                if(target->query_str()<20 || random(target->query_str())<random(me->quert_str()/3)) wp->move(environment(target));
	                message_vision(HIC "只見一道火光燒向"+wp->query("name")+"！！$N手中登時一陣滾燙，急忙鬆開了"+wp->query("name")+"！！\n" NOR ,target);
	                me->receive_damage("ap", 20 );
	                me->add_busy(2);
	                target->add_busy(2);
	        }
	        else
	        {
	                message_vision(CYN "$N手中兵器一縮，躲開了火舌的攻擊！！\n" NOR,target);
	                me->add_busy(2);
	        }
	  return 1;
	} else if(arg=="mp") {
		if(me->query("mp")<100) return notify_fail("你沒有足夠的mp可輸入炎羽鳳爪。\n");
		//enter your code for "mp" here
		write("尚未完成!\n");
		return 1;
	} else return notify_fail("指令: irrigate ap 或 irrigate mp。\n");
        return 1;
}

void npc_auto_equip(object target)
{
	if(target) target->force_me("wield all");
	return;
}