#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
    ([ "action": "$N爆喝一聲，手上鐵鍋有如烏雲蓋\頂罩向$n「"HIM"降龍十八炒"NOR"」鐵鍋不停地翻湧奔騰！",
       "damage": 10,
       "dodge" : 8,
       "parry" : 5,
       "attact_type": "bio",  // 設定技能的攻擊種類
                              // 種類有 生物(bio) 獸性(bar)
                              // 魔法(wit)心靈(sou)科技(tec)
       "damage_type": "重擊，頭暈腦脹摸不清東南西北",
    ]),
    ([ "action": "$N喊道：「"HIG"打狗鏟！"NOR"」從背後拿出鐵鏟不偏不倚地掃向$n的$l！",
       "damage": 8,
       "dodge": -5,
       "parry": 12,
       "attact_type": "bio",
       "damage_type": "擊傷，打的$n眼冒金星",
    ]),
    ([ "action": "$N從懷裡摸出菜刀，使出「"HIB"屠龍斬"NOR"」幻化成七七四十九把菜刀同時劈向$n的$l！",
       "damage": 7,
       "dodge" : 9,
       "parry" : -6,
       "attact_type": "bio",
       "damage_type": "割傷",
    ]),
    ([ "action": "$N反手握住菜刀，從不可思異的角度連續出招砍向$n$l，正是絕妙刀法「"HIW"倚天切"NOR"」",
       "damage": 13,
       "dodge" : 20,
       "parry" : -15,
       "attact_type": "bio",
       "damage_type": "割傷",
    ]),
    ([ "action": "$N右掌忽然冒出一團火光，正是少林絕學「"HIR"火雲掌"NOR"」$N身形一晃，掌風擊向$n$l",
       "damage": 15,
       "dodge" : 10,
       "parry" : 13,
       "attact_type": "wit",
       "damage_type": "燒傷，燙的$n哇哇大叫",
    ]),
});

string *colors = ({
  HIM"",
  HIR"",
  HIG"",
  HIB"",
  HIY"",
  HIW"",
});

mapping query_action()
{
    return combat_action[random(sizeof(combat_action))];
}

void heal();
void create()
{
    set_name("史提芬周", ({"food god", "god"}) );
    set("long",@LONG
    前「唐朝」飲食集團董事長，同時也是香港飲食界第一把交椅，
有『食神』之稱的男人─史提芬周。在一次新店開幕時被另一飲食集
團大快樂的老闆所陷害，人生跌落到谷底。後來靠著雙刀火雞與街坊
混混們的支持，以「撒尿牛丸」重出江湖，不但在中國廚藝訓練學院
學成出關，同時在新一次食神大賽上領悟了至高的要領。現在的史提
芬周已經成為一位半人半神的活神仙了。
LONG );
    set("race", "beast");
    set("race","人類");
    set("gender","男性");
    set("age", 29);
    set("level", 50);
    set("title",HIY"食神"NOR); 
    set("con", 100);
    set("int", 100);
    set("dex", 100);
    set("str", 100);
    add("addition_damage", 150);
    add("addition_armor", 250);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say 情和意...值千金..." :),
        (: command, "say 上刀山下火海...又何憾..." :),
        (: command, "say 為知心...犧牲又有何憾..." :),
        (: command, "say 為嬌娃...獻上一片心..." :),
        (: command, "say 血淚\為情流...至死無悔恨..." :),
        (: command, "say 有誰人...敢過問..." :),
    }));
    setup();
    set("default_actions", (: call_other, __FILE__, "query_action" :));
    set("actions", (: call_other, __FILE__, "query_action" :));
}
int special_attack(object me, object target, int hitchance)
{
    string msg;
    int i;
    if( !me || !target ) return 0;
    if( target->is_busy() ) return 0;
    if( random(100) < 25 ) {
        message_vision(HIC"\n$N"HIC"忽然間露出了黯然的神色，並在一分鐘內做出碗香噴噴的叉燒飯！\n\n"NOR, me, target);
        if( random(100) < target->query("level")/2 ) {
            message_vision(HIG"\n$N"HIG"費盡心力克制自己的食慾，終於躲過了叉燒飯的誘惑！\n\n"NOR, target, me);
            return 0;
        }
        message_vision(HIR"\n$N"HIR"受不了叉燒飯的誘惑，大口大口地巴起飯來！痛哭流涕吃著美味的叉燒！\n"NOR, target, me);
        for(i=random(5)+2;i>=0;i--) {
            switch( i ) {
                case 0: msg = "$N滿臉痛苦的大喊著：要是以後吃不到怎麼辦！\n"; break;
                case 1: msg = "$N說道：好叉燒阿！叉燒好吃阿！每塊肉都被內勁所震斷，有咬勁又不膩口！\n"; break;
                case 2: msg = "$N恍然大悟地說道：原來是加了洋蔥！真是太黯然！太消魂了！\n"; break;
                case 3: msg = "$N忽然間放聲大哭了起來，似乎遇到什麼心痛的事情！為什麼會流淚\！？\n"; break;
                case 4: msg = "$N驚嘆著：這荷包蛋真是太美味了！火雲掌將蛋的美味完全散發出來！真是太棒了！\n"; break;
                case 5: msg = "$N大叫道：沒想到蔬菜也能有如此效用！將整個叉燒飯的味道都襯托了出來！\n"; break;
                case 6: msg = "叉燒飯的美味令$N大快朵頤，但是每吃一口就緊皺眉頭，神色也漸漸暗淡了下去！\n"; break;
                default: msg = "$N忍不住讚不絕口：太好吃了，真是太好吃了。\n"; break;
            }
            message_vision("\n$N每吃一口叉燒飯，便不由自主的發出讚嘆聲，卻沒發現這黯然銷魂飯已使自己受到內傷！\n", target, me);
            message_vision(colors[random(sizeof(colors))]+msg+""NOR, target, me);
            switch( random(6) ) {
                case 0: target->receive_wound("head", 3 + random(15)); break;
                case 1: target->receive_wound("body", 3 + random(15)); break;
                case 2: target->receive_wound("left_arm", 3 + random(15)); break;
                case 3: target->receive_wound("left_leg", 3 + random(15)); break;
                case 4: target->receive_wound("right_arm", 3 + random(15)); break;
                case 5: target->receive_wound("right_leg", 3 + random(15)); break;
                default: target->receive_damage("hp", target->query("max_hp")/3); break;
            }
        }
        target->receive_damage("hp", target->query("max_hp")/6);
        message_vision(HIM"\n$N"HIM"終於將黯然銷魂飯吃個精光，但換來的結果是心力交瘁無力再戰！\n"NOR, target, me);
        target->start_busy(2+random(3));
        COMBAT_D->report_status(target);
    }
    return 0;
}
