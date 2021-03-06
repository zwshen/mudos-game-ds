#include <ansi.h>
inherit NPC;

string *sor_str= ({
"$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」\n"NOR,
"$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」\n"NOR,
"$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進\n",
"$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」\n"NOR,
"$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n使出一招"HIC"「"HIW"奘"HIC"」\n"NOR,
"$N凝神一定，將手中的劍忽地舞成劍花，趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去\n",
"$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去\n",
"$N內心一股衝動，把劍使出一招「小亂劍」，將劍身彎成像圓環一般往$n的頭部砸去\n",
"$N似乎醉了一般，使出了一招「酒謎醉人」，便如酒拳一般把$n打的不知該如何是好\n",
"$N心中一狠，臉色一青，立即對$n下了一招「草滿囹圄」，劍式便如打草雜法一般\n",
"$N手凝一招「怙惡不悛」，接著便猛攻$n手上大穴，接著又如小花一般輕柔的攻向$n頸部\n",
"$N化大為小，以小為礎，以太極為形，向$n連使出一招「"WHT"混沌破天"NOR"」，劍光閃爍在$n眼前\n",
});


void do_arc() 
{
        object weapon, me, *tar;
        int x=0, q, tar_d, me_d;
        me=this_object();
        tar = me->query_enemy();
        message_vision("\n\t$N雙手一合一分﹐隨空虛劃凝出一大片"HIC"「弧月」"NOR"。\n"NOR
        HIW"\t弧月似有生命一般﹐以快捷無倫的疾速攻向對手！！\n" NOR,me);

        for(q=0;q<sizeof(tar);q++)
        {
                if( !tar[q] ) continue;
                if( !tar[q]->query_temp("weapon") ) continue;
                if( !(weapon=tar[q]->query_temp("weapon")) ) continue;
                if( 20+random((tar_d=tar[q]->query_skill("dodge")+tar[q]->query_dex())*7/12) < random(me_d=me->query_skill("dodge")+me->query_dex())
                && weapon->unequip() ) {
                        message_vision(HIC "\n「鏘」"NOR"地一聲響，一道"HIC"弧月"NOR"撞得$N脫落了手中的武器！！\n" NOR , tar[q]);
                        tar[q]->start_busy(1);
                        message_vision(HIC"$N的武器好像被剛的弧月振壞了少許\！！\n"NOR, tar[q]);
                        weapon->set_durable((weapon->query_durable() - random (50) ) );
                } else {
                        message_vision(CYN "\n「鏘」"NOR"地一聲響，弧月一撞上$N手中的武器反而被震碎了！！\n" NOR, tar[q]);
                }
                x++;
        }
        if( !x ) {
                message_vision("\n「弧月」凌空轉了數圈，化成一陣輕煙消失了。\n",me);
                return;
        }
        return;

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
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                (: do_arc :),
                (: command ("exert moon-force shadow") :),
        }));
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
}
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

            switch( random(10) ) {
            case 0:
message_vision("\n$N握劍一立，將劍置於胸前五寸前，接著用劍在空中劃了個 "NOR+BLU"[田]"NOR" 字，"
               "\n大喝了一聲﹐一招"HIC"『"HIY"極星田字"HIC"』"NOR"殺向$n。\n\n", me, target);
                   target->receive_damage("ap", sum_damage/10, me);
                   target->receive_damage("hp", sum_damage, me);
                   target->start_busy(1+random(3));
                   message_vision(HIR"$n一個不小心，被$N擊中了極星田字，結果口中一陣鮮血狂噴！！"NOR, me, target);
                   me->add_busy(1+random(2)); 
                   if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                   message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                   else message_vision("\n\n", me);
                   COMBAT_D->report_status(target);
                   break;
            case 1:

message_vision("$N使了使手中之劍，憶起"HIW"穴道之門"NOR"，接著便用劍點向$n的穴道，"NOR, me, target);
message_vision(HIW"使得$N不能動彈!!\n"NOR, target);

                   if( sk < 30 ) target->start_busy(1+random(2));
                   if( sk > 30 && sk < 60 ) target->start_busy(2+random(2));
                   if( sk > 60 && sk < 90 ) target->start_busy(3+random(3));
                   if( sk >= 90 )
                       {
                        target->receive_damage("hp", me->query_damage()/3, me);
                        target->start_busy(4+random(2));
                        message_vision(HIR"$N似乎受了點傷！"NOR, target);
                       }
                   if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                   message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                   else message_vision("\n", me);
                   COMBAT_D->report_status(target);
                   break;
             case 3: 
                    attack_targets = me->query_enemy();message_vision(HIC"\n只見$N四周陡然一股強大的氣疾速上升…\n"NOR, me);
message_vision(HIY"　　$N提劍縱橫於敵之間，瞬間…$N發出劍氣，以劍剋敵…\n\n"NOR, me);
message_vision(HIM"  $N使出 - 進階 "HIY"『 "HIR"極 "HIG"． "HIR"星"HIG" ． "HIR"劍 "HIG"． "HIR"氣 "HIY"』 "HIM"－－－－－－－－－\n\n"NOR, me);

                        for(g=0;g<sizeof(attack_targets);g++)
                        {
              if( random( attack_targets[g]->query_dex() ) < random( me->query_dex()*2 ) + 15 ) { 
              if( random( attack_targets[g]->query_skill("force")/2 ) > random(force) )
                        {
                          damage = me->query_damage()*2/3 + w_force/4 + random( me->query_damage()/4 );
                          damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                          attack_targets[g]->receive_damage("hp",damage, me);
                          attack_targets[g]->start_busy(2);
           message_vision(CYN"$N奮力迎擊, 硬是接下了這道劍氣！"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                          COMBAT_D->report_status(attack_targets[g]);
                        }
                          else
                        {
                          damage = me->query_damage() + w_force*2/3 + random( me->query_damage()/3 );
                          damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                          attack_targets[g]->receive_damage("hp", damage , me);
                          attack_targets[g]->start_busy(3);
           message_vision(HIC"$N不及抵擋, 被劍氣打個正著！"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                          COMBAT_D->report_status(attack_targets[g]);
                        }
                        }
                          else {
           message_vision(YEL"$N躲過了這道劍氣！\n"NOR,attack_targets[g] );
                          attack_targets[g]->start_busy(1);
                               }
                        }
                        message_vision("\n",me);
                        break;
           case 4:

    message_vision("\n\t"HIW"$N一股作氣！將"HIB"內勁"HIW"一次導入劍內，使出疾風連技『"HIC"索星天壁"HIW"』\n\n"NOR,me,target);
    for(i=0;i<20;i++)
    {
      msg=sor_str[random(sizeof(sor_str))];
      message_vision(msg,me,target);
    }
    target->receive_damage("hp",sum_damage*3,me); 
    message_vision(HIR"("+sum_damage*3+")\n"NOR,me); 
    COMBAT_D->report_status(target);
    target->start_busy(random(3)); 
            break;
           case 5:
message_vision(
HIC"                      ◢○○"HIR"●●●●"HIC"○○◣
"HIW"                      真"NOR" 。 "HIW"索  星  奧  義          "NOR"　
                      "CYN"█"NOR"
                    "CYN"██"HIR"_________________"NOR"
        "RED"█          "CYN"██                 "HIR"＼_____________"NOR"
      "RED"███      ◢"CYN"██"HIM"████████◣              "HIR"＼________________"NOR"
      "RED"□██████"CYN"█"HIC"◣"HIM"□□□□□□□□□"HIG"███████◣                "HIR"＼"NOR" 
      "RED"□█"HIY"◇"HIW"████"NOR""CYN"█"HIC"█"HIC"索  星  傲  劍  式"HIG"□□□□□□□□"HIB"□□□□□□□□﹚"HIR"﹚"NOR"
      "RED"□██████"CYN"█"HIC"◤"HIM"□□□□□□□□□"HIG"███████◤"HIR"________________／"NOR" 
      "RED"███      ◥"CYN"██"HIM"████████◤ "HIR"_____________／"NOR"
        "RED"█          "CYN"██"HIR"_________________／"NOR"              
                    "CYN"██"NOR"
                      "CYN"█"NOR
,target,me);

    target->receive_damage("hp",sum_damage*7,me); 
    message_vision(HIR"\n("+sum_damage*7+")\n"NOR,me); 
    COMBAT_D->report_status(target);
            break;
                   }
                   return 0;
}     

varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if(this_object()->is_fighting() ) {
        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(100)<15)
                {
                   damage/=100000;
                   message_vision(HIC"\n$N身體周圍的氣勁將$n的攻勢完全的吸收了！！\n" NOR,this_object(),who);
                }
                }
                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}
