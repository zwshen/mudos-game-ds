#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("段洪",({"duan hong","duan","hong"}) );
        set("long",@LONG
疾風門劍聖，雖為劍聖確不見其劍乃用劍之最高奧義•
LONG);
        set("title",HIW"疾風劍聖"NOR); 
        set("nickname","虛劍御空");        
        set("age",40+random(5));
        set("level",80);
        set("gender","男性");
        set("attitude", "peaceful");  
        set_skill("fogseven", 100+random(50)); 
        set_skill("dodge", 100+random(50)); 
        set_skill("unarmed", 100+random(50)); 
        set_skill("sword", 100+random(50)); 
        set_skill("star-sword", 100+random(50));
        set_skill("sorgi_sword", 100+random(50)); 
        set_skill("moon_force", 100+random(50)); 
        set_skill("sorsin_force", 100+random(50));
        set_skill("force", 100+random(50));
        map_skill("dodge","fogseven");
        map_skill("sword","star-sword");
        set("Merits/bar",8+random(10));
        set("int",175);
        set("addition_armor",50+random(100));
        set("Merits/wit",8+random(4));
        set("addition_damage",50+random(100));
        add("apply/hit",80+random(30));
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
}
int force = (int)(this_player()->query_skill("moon_force")*0.3) + (int)(this_player()->query_skill("force")*0.2);
int p_force = this_player()->query_skill("star-sword")/5;
int b_force = random(this_player()->query_skill("moon_force"))/4;
int spal = ( p_force*p_force + b_force*b_force )/( p_force + b_force );
void star_tain(string a, string arg);

mapping *combat_action = ({
        ([
        "action": "$N凝神一定，將手中的劍忽地舞成劍花，趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去",
        "damage":       30+force,
        "dodge" :            -15,
        "attack_type":  "bar",
        "damage_type":  "刺傷", 
        ]),         
        ([
        "action": "$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去",
        "damage":        force*2,
        "dodge" :          -5,
        "attack_type":  "bar",
        "damage_type":  "刮傷", 
        ]),
        ([
        "action": "$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去",
        "damage":               15+force*2,
        "dodge" :               10,
        "attack_type":  "bar",
        "damage_type":  "鞭傷", 
        ]),
        ([
        "action": "$N內心一股衝動，把劍使出一招「小亂劍」，將劍身彎成像圓環一般往$n的頭部砸去",
        "damage":               10+force*2,
        "dodge" :               -3,
        "attack_type":  "bar",
        "damage_type":  "創傷", 
        ]),
        ([
        "action": "$N似乎醉了一般，使出了一招「酒謎醉人」\n，便如酒拳一般把$n打的不知該如何是好",
        "damage":               12+force*2,
        "dodge" :               -15,
        "attack_type":  "bar",
        "damage_type":  "刺傷", 
        ]),
        ([
        "action": "$N心中一狠，臉色一青，立即對$n下了一招「草滿囹圄」，劍式便如打草雜法一般",
        "damage":               15+force*2,
        "dodge" :               13,
        "attack_type":  "bar",
        "damage_type":  "刺傷", 
        ]),
        ([
        "action": "$N使出一招平平無奇的中宮劍往$n身上要穴而去，不料在途中突轉變為「曲龍幽行」，反攻向$n下盤",
        "damage":               18+force*2,
        "dodge" :               5,
        "attack_type":  "bar",
        "damage_type":  "刺傷", 
        ]),
        ([
        "action": "$N手凝一招「怙惡不悛」，接著便猛攻$n手上大穴，接著又如小花一般輕柔的攻向$n頸部",
        "damage":               17+force*2,
        "dodge" :               5,
        "attack_type":  "bar",
        "damage_type":  "戳傷", 
        ]),
        ([
        "action": "$N化大為小，以小為礎，以太極為形，向$n連使出一招「混沌破天」，劍光閃爍在$n眼前",
        "damage":               21+force*2,
        "dodge":                -10,
        "attack_type":  "bar",
        "damage_type":  "割傷",
        ]),
        ([
        "action": "$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進",
        "damage":       25*2,  
        "attack":       10*2,
        "attact_type":  "bar",  
        "damage_type":  "刺傷", 
        ]),
        ([
        "action": "$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」"NOR"戳向$n的$l",
        "damage":       15*2+random(spal/4),
        "dodge":        -5,
        "delay":        1,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
        ]),
        ([
        "action": "$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」"NOR,
        "damage":       18*2,
        "delay":        2,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
        ]),
        ([
        "action": "$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」"NOR,
        "damage":       25*2,
        "delay":        2,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
        ]),
        ([
        "action": "$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n的$l使出一招"HIC"「"HIW"奘"HIC"」"NOR,
        "damage":       30*2,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
        ]),
});  
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
int special_attack(object me,object target,int hitchance)
{   
            int sk = me->query_skill("star-sword"),
            force = me->query_skill("force"),
            w_force = me->query_skill("moon_force"),
            sw = me->query_skill("sorgi_sword"),
            target_armor, me_damage, target_dodge, me_dex, sum_damage, g,damage, i;
            object *attack_targets;
            string msg;

                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                me_damage = me->query_damage() + w_force/4 + sk/3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2); 
    message_vision("\n\t"HIW"$N一股作氣！將"HIB"內勁"HIW"一次導入劍內，使出疾風連技『"HIC"索星天壁"HIW"』\n\n"NOR,me,target);
    for(i=0;i<20;i++)
    { 
      call_other(__FILE__, "query_action");
    }
    target->receive_damage("hp",sum_damage*7,me); 
    message_vision(me,HIR"("+damage+")\n"NOR); 
    COMBAT_D->report_status(target);
    target->start_busy(random(3)); 
    return 0;}

